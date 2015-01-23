/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <vector>

namespace       Tools {
  // This class is an array that automatically resize when accessing
  // an index bigger that the array.
  // Parameter defaultVal is to used to initialized empty fields
  // of the reallocated array.
  template<typename T>
  class DynVector {
    std::vector<T>	_array;
    unsigned int    _size;
    unsigned int    _reallocStep;

  public:
    DynVector(unsigned int baseSize = 10, unsigned int reallocStep = 10);
    ~DynVector();
    T&  operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int        getSize() const;
    unsigned int        getReallocStep() const;
    void                setReallocStep(unsigned int reallocStep);
  };
}
#include "DynVector.ipp"
