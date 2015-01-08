/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

namespace ECS {
  template<typename T>
  void ASystem::bindType(void) {
    this->bindType(Tools::TypeId::getId<T *>());
  }
}
