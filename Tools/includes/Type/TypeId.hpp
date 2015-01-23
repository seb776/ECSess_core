/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <string>
#ifdef	DEBUG_MODE
// to allow full name visualisation instead of system dependent one
// returned by typeid().name()
# include "DynVector.hpp"
#endif	// !DEBUG_MODE

#define INIT_TYPE(name, t)      Tools::TypeId name; name.init<t>(#t);

namespace Tools {
  class TypeId
  {
  private:
    static int lastId_;
#ifdef	DEBUG_MODE
    static DynVector<std::string>	identifiers_;
#endif	// !DEBUG_MODE
  public:
    template<typename T>
    static int	getId(T o = T());
    static void	view(const TypeId * const t);

  private:
    typedef enum e_restrict {
      NO_RESTRICT = 0,
      AND = 1,
      OR = 2,
      NOT = 3
    } t_restrict;
    t_restrict		restrictType_;
    unsigned int	typeId_;
    TypeId	*left;
    TypeId	*right;

  public:
    TypeId(void);
    TypeId(const TypeId&);
    TypeId(unsigned int typeId);
    ~TypeId(void) {
      // free the parsing tree
    }
#ifdef	DEBUG_MODE
    const std::string&	getIdentifier(void) const {
      return identifiers_[typeId_]; // not safe
    }
#endif	// !DEBUG_MODE
    template<typename T>
    void	init(std::string name = "", T o = T());
    TypeId&	operator=(const TypeId& rhs);
    TypeId&	operator&&(const TypeId& rhs);
    TypeId&	operator||(const TypeId& rhs);
    void	view(void);
    auto	getLeft(void) const -> const TypeId *;
    auto	getRight(void) const -> const TypeId *;
    auto	getRestrictType(void) const -> t_restrict;
    auto	getTypeId(void) const -> unsigned int;
  };
}

#include "TypeId.ipp"
