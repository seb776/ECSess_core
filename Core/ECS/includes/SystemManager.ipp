/*
** Author: Sebastien Maire
** Contribs:
*/

namespace ECS {
  template<typename T, typename... Args>
  T	*SystemManager::createSystem(Args... args) {
    return new T(args...);
  }
}
