/*
** Author: Sebastien Maire
** Contribs:
*/

#include <iostream>

#include <algorithm>

#include "SystemManager.hpp"

namespace ECS {
  // PRIVATE
  bool	SystemManager::addSystem_(ASystem *sys) {
    unsigned int id;

    id = this->systems_.insert(sys);
    sys->setUniqueId(id);
    sys->bindWorld(this->world_);
    for (unsigned int ent : registeredEntities_) {
      // to push entities in the new system
      sys->submitEntity(ent);
    }
    return true;
  }
  bool	SystemManager::deleteSystem_(ASystem *sys) {
    sys->setMuted(false);
    systems_.erase(sys->getUniqueId());
    sys->unbindWorld();
    sys->clear(); // to cancel all entities
    sys->setUniqueId(static_cast<unsigned int>(-1));
    delete sys;
    return true;
  }
  bool	SystemManager::muteSystem_(ASystem *sys, const Tools::Timer& begin, float time, bool& firstCall) {
    if (firstCall) { // first iteration
      firstCall = false;
    }
    if (time == -1.0f) // for undefined delay
      return false;
    if (begin.elapsedTime() > time || !sys->isMuted()) { // for defined delay
      // world_->systemManager.registerEntity(sys->getUniqueId());
      sys->setMuted(false);
      return true;
    }
    return false;
  }
  bool	SystemManager::unmuteSystem_(ASystem *sys) {
    sys->setMuted(false);
    return true;
  }
  bool	SystemManager::registerEntity_(unsigned int id) {
    for (unsigned int i = 0;
	 i != systems_.size();
	 ++i) {
      if (systems_[i])
	systems_[i]->submitEntity(id);
    }
    registeredEntities_.push_back(id);
    return true;
  }
  bool	SystemManager::unregisterEntity_(unsigned int id) {
    // to set entities for next added systems
    registeredEntities_.erase(std::find_if(registeredEntities_.begin(), registeredEntities_.end(),
					   [&](unsigned int regId) {return regId == id;}));

    // to update current systems
    for (unsigned int i = 0;
	 i < systems_.size();
	 ++i) {
      systems_[i]->cancelEntity(id);
    }
    return true;
  }

  // PUBLIC
  SystemManager::~SystemManager(void) {
    for (unsigned int i = 0;
	 i < systems_.size();
	 ++i) {
      if (systems_[i])
	delete systems_[i];
    }
  }
  void SystemManager::addSystem(ASystem *sys) {
    systemTasks_.push_back(std::bind(&SystemManager::addSystem_, this, sys));
  }
  void SystemManager::removeSystem(ASystem *sys) {
    systemTasks_.push_back(std::bind(&SystemManager::deleteSystem_, this, sys));
  }
  void SystemManager::muteSystem(ASystem *sys, float time) {
#ifdef	DEBUG_MODE
    if (sys->isMuted())
      throw std::logic_error("ECS: Already muted system.");
#endif	// !DEBUG_MODE
    systemTasks_.push_back(std::bind(&SystemManager::muteSystem_, this, sys, Tools::Timer(), time, true));
    sys->setMuted(true);
  }
  void SystemManager::unmuteSystem(ASystem *sys) {
    systemTasks_.push_back(std::bind(&SystemManager::unmuteSystem_, this, sys));
  }
  void SystemManager::registerEntity(unsigned int id) {
    entitiesTasks_.push_back(std::bind(&SystemManager::registerEntity_, this, id));
  }
  void SystemManager::unregisterEntity(unsigned int id) {
    entitiesTasks_.push_back(std::bind(&SystemManager::unregisterEntity_, this, id));
  }
  void	SystemManager::update(void) {
    for (auto task : entitiesTasks_) {
      task();
    }
    entitiesTasks_.clear();
    systemTasks_.erase(std::remove_if(systemTasks_.begin(),
    				    systemTasks_.end(),
    				    [&](std::function<bool ()>& f) {
    				      return f();
				      }), systemTasks_.end());
  }
}
