/*
** Author: Sebastien Maire
** Contribs:
*/

#include <stdexcept>
#include <algorithm>
#include "ASystem.hpp"
#include "World.hpp"
#include "Entity.hpp"

namespace ECS {
  ASystem::ASystem(void) :
    AFinalNode(),
    typeId_(static_cast<unsigned int>(-1)) {
  }
  ASystem::~ASystem(void) {
  }

  void ASystem::bindType(unsigned int id) {
    typeId_ = Tools::TypeId(id);
  }

  void ASystem::bindType(const Tools::TypeId& typeId) {
    typeId_ = typeId;
  }

  bool ASystem::isBoundTo(unsigned int id) {
    if (world_->entityManager.getEntity(id)->getComponents()[this->typeId_.getTypeId()].size() < 1) {
      return false;
    }
    if (!(world_->entityManager.getEntity(id)->getComponents()[this->typeId_.getTypeId()][0]))
      return false;
    return true;
  }

  void ASystem::submitEntity(unsigned int id) {
    if (this->isBoundTo(id))
      this->entities_.push_back(id);
  }
  void ASystem::cancelEntity(unsigned int id) {
    entities_.erase(std::remove_if(entities_.begin(), entities_.end(),
				   [&](unsigned int regId) {
				     return regId == id;
				   }),
		    entities_.end());
  }

  void	ASystem::mute(float time) {
    world_->systemManager.muteSystem(this, time);
  }

  void	ASystem::unmute(void) {
    world_->systemManager.unmuteSystem(this);
  }

  void ASystem::remove(void) {
#ifdef DEBUG_MODE
if (!this->world_)
  throw std::logic_error("ECS: Cannot remove an unbound System.");
#endif /* !DEBUG_MODE */
    this->world_->systemManager.removeSystem(this);
  }

  void ASystem::clear(void) {
    entities_.clear();
  }

  void ASystem::process() {
    if (world_ && !this->isMuted()) {
      this->processAll(entities_);
    }
  }
  void ASystem::processAll(std::vector<unsigned int>& entities) {
    std::vector<unsigned int>::iterator it = entities.begin();

    for (;it != entities.end(); ++it) {
      this->processEntity(this->world_->entityManager.getEntity(*it));
    }
  }
}
