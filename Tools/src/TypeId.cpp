/*
** Author: Sebastien Maire
** Contribs:
*/

#include "TypeId.hpp"

namespace Tools {
  int TypeId::lastId_ = 0;
#ifdef	DEBUG_MODE
  DynVector<std::string>	TypeId::identifiers_;
#endif	// !DEBUG_MODE
  TypeId::TypeId(void) {
    left = nullptr;
    right = nullptr;
    restrictType_ = NO_RESTRICT;
    typeId_ = static_cast<unsigned int>(-1);
  }

  TypeId::TypeId(unsigned int typeId) :
    TypeId() {
    typeId_ = typeId;
  }

  TypeId&	TypeId::operator=(const TypeId& rhs) {
    restrictType_ = rhs.restrictType_;
    typeId_ = rhs.typeId_;
    if (rhs.left) {
      left = new TypeId();
      *left = *(rhs.left);
    }
    if (rhs.right) {
      right = new TypeId();
      *right = *(rhs.right);
    }	
    return *this;
  }

  TypeId&	TypeId::operator&&(const TypeId& rhs) {
    TypeId *nleft = new TypeId();
    TypeId *nright = new TypeId();

    *nleft = *this;
    *nright = rhs;
    left = nleft;
    right = nright;
    restrictType_ = AND;
    return *this;
  }

  TypeId&	TypeId::operator||(const TypeId& rhs) {
    TypeId *nleft = new TypeId();
    TypeId *nright = new TypeId();

    *nleft = *this;
    *nright = rhs;
    left = nleft;
    right = nright;
    restrictType_ = OR;
    return *this;
  }

  const TypeId	*TypeId::getLeft() const { return left; }
  const TypeId	*TypeId::getRight(void) const { return right; }
  auto		TypeId::getRestrictType(void) const -> TypeId::t_restrict { return restrictType_; }
  unsigned int	TypeId::getTypeId(void) const { return typeId_; }

  void	TypeId::view(const TypeId * const t) {
    static const std::string restr[] = {
      "NO_RESTRICT",
      "AND",
      "OR",
      "NOT"
    };
    if (t->left) {
      view(t->left);
    }
    if (t->restrictType_) {
      std::cout << " restrict(" << restr[t->restrictType_] << ") ";
    }
    if (t->right) {
      view(t->right);
    }
    if (t->restrictType_)
      std::cout << "Composed";
    else
      std::cout << " type(" << TypeId::identifiers_[t->typeId_] << ") ";
  }
  void	TypeId::view(void) {
    TypeId::view(this);
  }
}
