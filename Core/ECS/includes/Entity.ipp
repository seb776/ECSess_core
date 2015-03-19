/*
** Author: Sebastien Maire
** Contribs:
*/

#include <stdexcept>
#include "ECSexceptions.hpp"

#pragma once

namespace ECS {
  template<typename T>
  void	Entity::addComponent(T *component) {
    unsigned int id;

    id = components_[Tools::TypeId::getId<T *>()].insert(component);
    component->bindParent(this);
    component->setUniqueId(id);
    if (world_)
      world_->systemManager.registerEntity(uniqueId_);
  }
  template<typename T>
  void	Entity::removeComponentById(T *component, unsigned int id) {
    components_[Tools::TypeId::getId<T *>()].erase(id);
    component->unbindParent();
    delete component;
    world_->systemManager.unregisterEntity(uniqueId_);
    world_->systemManager.registerEntity(uniqueId_);
  }

  template<typename T>
  T	*Entity::getComponentById(unsigned int id) {
#ifdef	DEBUG_MODE
    if (!hasComponent<T>(id)) {
      throw ECS::exception(1, "Try to get a component that not exists.");
    }
#endif	// !DEBUG_MODE
    return dynamic_cast<T *>(components_[Tools::TypeId::getId<T *>()][id]);
  }

  template<typename T>
  T	*Entity::getComponent(unsigned int pos) {
    unsigned int count = 0;

    for (unsigned int i = 0;
	 i < components_[Tools::TypeId::getId<T *>()].size();
	 ++i) {
      if (components_[Tools::TypeId::getId<T *>()][i] && count == pos) {
	if (count == pos) {
	  return dynamic_cast<T *>(components_[Tools::TypeId::getId<T *>()][i]);
	}
	else
	  ++count;
      }
    }
    throw std::logic_error("ECS: getComponent() no component on position.");
    return nullptr;
  }
  
  template<typename T>
  unsigned int	Entity::getComponentCount(void) const {
    if (Tools::TypeId::getId<T *>() < components_.getSize()) {
      return components_[Tools::TypeId::getId<T *>()].count();
    }
    return 0;
  }

  template<typename T>
  bool	Entity::hasComponent(unsigned int id) const { // default static_cast<unsigned int>(-1)
    unsigned int typeId;

    typeId = Tools::TypeId::getId<T *>();
    if (typeId < components_.getSize()) {
      if (id == static_cast<unsigned int>(-1)) { // check if at least 1 is present
	if (components_[typeId].count())
	  return true;
      }
      if (id < components_[typeId].size())
	return components_[typeId][id] == nullptr;
    }
    return false;
  }
}
