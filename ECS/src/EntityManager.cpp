/*
** Author: Sebastien Maire
** Contribs:
*/

#include <iostream>

#include <stdexcept>
#include <utility>
#include "World.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"
#include "ECSexceptions.hpp"

namespace ECS {
  // PRIVATE
  bool	EntityManager::addEntity_(Entity *e) {
    unsigned int id;

#ifdef	DEBUG_MODE
    for (unsigned int i = 0;
	 i < entities_.size();
	 ++i) {
      if (e == entities_[i])
	throw std::logic_error("ECS: Already added entity.");
    }
#endif	// !DEBUG_MODE
    id = entities_.insert(e);
    e->setUniqueId(id);
    e->bindWorld(world_);
    world_->systemManager.registerEntity(id);
    return true;
  }
  bool	EntityManager::deleteEntity_(unsigned int id) {
#ifdef	DEBUG_MODE
    if (!entities_[id])
      throw std::logic_error("ECS: EntityManager: Cannot delete entity.");
#endif	// !DEBUG_MODE
    if (entities_[id]->isMuted())
      entities_[id]->setMuted(false);
    world_->groupManager.unregisterNode(entities_[id]);
    world_->tagManager.unregisterNode(entities_[id]);
    world_->systemManager.unregisterEntity(id);
    world_->syncIdManager.unregisterNode(entities_[id]);
    delete entities_[id];
    entities_.erase(id);
    return true;
  }
  bool	EntityManager::muteEntity_(Entity *e, const Tools::Timer& begin, float time, bool& firstCall) {
    unsigned int id;

    if (firstCall) {
      firstCall = false;
      world_->systemManager.unregisterEntity(e->getUniqueId());
    }
    if (time == -1.0f) {// for undefined delay
      return true;
    }
    if (begin.elapsedTime() > time || !e->isMuted()) { // for defined delay
      world_->systemManager.registerEntity(e->getUniqueId());
      e->setMuted(false);
      return true;
    }
    return false;
  }
  bool	EntityManager::unmuteEntity_(Entity *e) {
    world_->systemManager.registerEntity(e->getUniqueId());
    e->setMuted(false);
    return true;
  }

  // PUBLIC
  EntityManager::~EntityManager(void) {
    for (unsigned int i = 0;
	 i < entities_.size();
	 ++i) {
      if (entities_[i])
	delete entities_[i];
    }
  }
  Entity *EntityManager::createEntity(void) {
    Entity *e = new Entity();

    return e;
  }
  void EntityManager::addEntity(Entity *e) {
    tasks_.push_back(std::bind(&EntityManager::addEntity_, this, e));
  }
  void EntityManager::removeEntity(Entity *e) {
    this->removeEntity(e->getUniqueId());
  }
  void EntityManager::removeEntity(unsigned int entId) {
    tasks_.push_back(std::bind(&EntityManager::deleteEntity_, this, entId));
  }
  void EntityManager::muteEntity(Entity *ent, float time) {
#ifdef	DEBUG_MODE
    if (ent->isMuted())
      throw std::logic_error("ECS: Trying to mute already muted entity.");
    else if (ent->getUniqueId() == static_cast<unsigned int>(-1))
      throw std::logic_error("ECS: Trying to mute an Entity which was not added in the world.");
#endif	// !DEBUG_MODE
    tasks_.push_back(std::bind(&EntityManager::muteEntity_, this, ent, Tools::Timer(), time, true));
    ent->setMuted(true);
  }
  void EntityManager::unmuteEntity(Entity *ent) {
    tasks_.push_back(std::bind(&EntityManager::unmuteEntity_, this, ent));
  }
  Entity *EntityManager::getEntity(unsigned int id) {
#ifdef	DEBUG_MODE
    if (entities_.size() <= id || !entities_[id])
      throw std::logic_error("ECS: EntityManager: Trying to get unknown entity.");
#endif	/* !DEBUG_MODE */
    return entities_[id];

  }

  Tools::IndexVector<Entity *>&	EntityManager::getEntities(void) {
    return entities_;
  }

  void	EntityManager::update(void) {
    unsigned int i;

    for (i = 0; i < tasks_.size();) {
      if (tasks_[i]()) {
	tasks_.erase(tasks_.begin() + i);
      }
      else
	++i;
    }
  }
}
