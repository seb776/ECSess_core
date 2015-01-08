/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <iostream>

#include <vector>
#include "World.hpp"
#include "AComponent.hpp"
#include "DynVector.hpp"
#include "TypeId.hpp"

namespace ECS {
  class Entity : public AComponent
  {
  public:
    typedef Tools::DynVector<Tools::IndexVector<AComponent *> > ComponentsType;
  private:
    ComponentsType	components_;
  public:
    GENERATE_COMPONENT_DUPLICATE(Entity);
    Entity(void); // ~
    Entity(const Entity&o); // ~
    virtual	 ~Entity(void); // ~
    Entity&	operator=(const Entity& rhs); // ~

    template<typename T>
    void	addComponent(T *component); // ok
    template<typename T>
    void	removeComponentById(T *component, unsigned int id = 0); // ok ~
    template<typename T>
    T		*getComponentById(unsigned int id = 0); // You must be sure of the id
    template<typename T>
    T		*getComponent(unsigned int position = 0);
    template<typename T>
    auto	getComponentCount(void) const -> unsigned int;
    // check if there's at least one instance of T * of id is set at default
    template<typename T>
    bool	hasComponent(unsigned int id = static_cast<unsigned int>(-1)) const;
    auto	getComponents(void) const -> const ComponentsType&;
    auto	getComponentByTypeId(unsigned int typeId, unsigned int id = 0) -> AComponent *; // ~
    void	removeComponentByTypeId(unsigned int typeId, unsigned int id = 0); // ~
    void	mute(float time = -1.0); // ok ~
    void	unmute(void); // ok ~
    void	remove(void); // ok ~
    void	view(void);
  };
}
#include "Entity.ipp"
