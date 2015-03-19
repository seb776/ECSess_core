
/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include "AFinalNode.hpp"

#define	GENERATE_COMPONENT_DUPLICATE(type)		\
  ECS::AComponent	*duplicate(void) const {	\
    type *o = new type();	                        \
    *o = *this;						\
    return o;						\
  }							\

namespace ECS {
  class Entity;

  class AComponent : public AFinalNode
  {
  private:
    AComponent(AComponent *) {}
  protected:
    Entity		*parent_;
    unsigned int	typeId_;
  public:
    AComponent(void);
    virtual		~AComponent(void);

    void		bindParent(Entity *e); // for nested entities
    void		unbindParent(void);
    auto		getTypeId(void) const -> unsigned int; // to allow better control of components
    void		setTypeId(unsigned int typeId);
    template<typename T, typename... Args>
    static T*		createComponent(Args... args);
    virtual AComponent	*duplicate(void) const = 0;
    void		mute(float time = -1);
    void		unmute(void);
    void		remove(void);
  };
}

#include "AComponent.ipp"
