/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once
#include <iostream>
#include <typeinfo>
namespace Tools {
  template<typename T>
  int	TypeId::getId(T) {
    static int id = TypeId::lastId_++;
    identifiers_[id] = typeid(T).name(); // TODO
    return id;
  }

  template<typename T>
  void	TypeId::init(std::string name, T) {
    typeId_ = TypeId::getId<T>();
#ifdef	DEBUG_MODE
    if (name.length())
      identifiers_[typeId_] = name;
    else
      identifiers_[typeId_] = typeid(T).name();
#endif	// !DEBUG_MODE
  }
}
