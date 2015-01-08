/*
** Author: Sebastien Maire
** Contribs:
*/

#include <sstream>
#include "ECSexceptions.hpp"
#include "Entity.hpp"
#include "World.hpp"

namespace ECS {
  Entity::Entity(void) :
    AComponent() {
    setMuted(false);
  }
  Entity::Entity(const Entity& o) { *this = o; }
  Entity::~Entity(void) {
    for (unsigned int i = 0;
	 i < components_.getSize();
	 ++i) {
      for (unsigned int j = 0;
	   j < components_[i].size();
	   ++j) {
	if (components_[i][j])
	  delete components_[i][j];
      }
    }
  }

  Entity&	Entity::operator=(const Entity& rhs) {
    unsigned int i;
    unsigned int j;

    for (i = 0; i < rhs.getComponents().getSize(); ++i) {
      for (j = 0; j < rhs.getComponents()[i].size(); ++j) {
    	this->components_[i].insert(rhs.getComponents()[i][j]->duplicate());
      }
    }
    return *this;
  }

  void	Entity::mute(float time) {
#ifdef	DEBUG_MODE
    if (!world_) {
      std::stringstream ss;
      
      ss << "An Entity must be bound to the world before being muted (" << std::hex << this << ").";
      throw ECS::exception(1,  ss.str().c_str());
    }
#endif	/* !DEBUG_MODE */
    world_->entityManager.muteEntity(this, time);
  }
  void	Entity::unmute(void) {
    if (!world_) {
      std::stringstream ss;

      ss << "An Entity must be bound to the world before being unmuted (" << std::hex << this << ").";
      throw ECS::exception(1,  ss.str().c_str());
    }
    world_->entityManager.unmuteEntity(this);
  }
  void	Entity::remove(void) {
#ifdef	DEBUG_MODE
    if (!world_) {
      std::stringstream ss;

      ss << "An Entity must be bound to the world before being removed (" << std::hex << this << ").";
      throw ECS::exception(1,  ss.str().c_str());
    }
#endif	/* !DEBUG_MODE */
    world_->entityManager.removeEntity(this);
  }
  
  AComponent	*Entity::getComponentByTypeId(unsigned int typeId, unsigned int id) {
#ifdef	DEBUG_MODE
#endif	/* !DEBUG_MODE */
    return components_[typeId_][id];
  }
    
    void	Entity::removeComponentByTypeId(unsigned int typeId, unsigned int id) {
    components_[typeId][id]->unbindParent();
    components_[typeId].erase(id);
    world_->systemManager.unregisterEntity(uniqueId_);
    world_->systemManager.registerEntity(uniqueId_);
  }

  auto	Entity::getComponents(void) const -> const ComponentsType& {
    return components_;
  }

  void	Entity::view(void) {
    std::cout << "Entity(" << this << ":id=>" << this->uniqueId_ << ")" << std::endl;

    for (unsigned int i = 0;
	 i < components_.getSize();
	 ++i) {
      std::cout << "\t" << "TypeId(" << Tools::TypeId(i).getIdentifier() << ")len=>" << components_[i].size() << std::endl;
      if (components_[i].size()) {
	for (unsigned int j = 0;
	     j < components_[i].size();
	     ++j) {
	  std::cout << "\t\t" << "Component(" << components_[i][j] << ")=>" << j << std::endl;
	}
      }
    }
    std::cout << std::endl;
  }
}
