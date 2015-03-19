/*
** Author: Sebastien Maire
** Contribs:
*/

#include <iostream>

#include <stdexcept>
#include "ECSexceptions.hpp"
#include "Entity.hpp"
#include "AComponent.hpp"

namespace ECS {
  AComponent::AComponent(void) :
    AFinalNode() {
    parent_ = nullptr;
  }
  AComponent::~AComponent(void) {
  }

  void	AComponent::mute(float time) {
    throw std::logic_error("ECS: Mute on component is not implemented yet.");
  }

  void	AComponent::unmute(void) {
    throw std::logic_error("ECS: Unmute on component is not implemented yet.");
  }
  void	AComponent::remove(void) {
#ifdef	DEBUG_MODE
    if (!parent_)
      throw std::logic_error("ECS: Trying to remove a component which have no parent.");
#endif	// !DEBUG_MODE
    parent_->removeComponentByTypeId(typeId_, uniqueId_);
  }
  void	AComponent::bindParent(Entity *e) { parent_ = e; }
  void	AComponent::unbindParent(void) { parent_ = nullptr; }
  unsigned int	AComponent::getTypeId(void) const { return typeId_; }
  void	AComponent::setTypeId(unsigned int typeId) { typeId_ = typeId; }
}
