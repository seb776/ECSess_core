/*
** Author: Sebastien Maire
** Contribs:
*/

#include "TypeId.hpp"

namespace ECS {
  template<typename T, typename... Args>
  T	*AComponent::createComponent(Args... args) {
    T* c = new T(args...);
    
    c->setTypeId(Tools::TypeId::getId<T *>());
    return c;
  }
}
