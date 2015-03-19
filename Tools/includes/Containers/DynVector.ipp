/*
** Author: Sebastien Maire
** Contribs: 
*/
#include <iostream>

#include <algorithm>
#include <exception>
#include <stdexcept>

namespace Tools {
  template<typename T>
  DynVector<T>::DynVector(unsigned int baseSize, unsigned int reallocStep) :
    _size(baseSize), _reallocStep(reallocStep) {
    _array.resize(baseSize);
  }

  template<typename T>
  T&		DynVector<T>::operator[](unsigned int index) {

    if (index >= _size) {
      _size = index + _reallocStep;
      std::vector<T>	tmp(_array);

      std::copy_n(_array.begin(), tmp.size(), tmp.begin());
      _array.resize(_size);
      std::copy_n(tmp.begin(), tmp.size(), _array.begin());
    }
    if (_array.capacity() < index) {
      throw std::logic_error("Overflow the DynVector. Don't put negative value as reallocStep");
    }
    return _array[index];
  }

  template<typename T>
  const T&		DynVector<T>::operator[](unsigned int index) const {
    if (index >= _size) {
      throw std::range_error("Index out of range in DynVector[]");
    }
    return _array[index];
  }

  template<typename T>
  unsigned int	DynVector<T>::getSize() const {
    return _size;
  }

  template<typename T>
  unsigned int	DynVector<T>::getReallocStep() const {
    return _reallocStep;
  }

  template<typename T>
  void	DynVector<T>::setReallocStep(unsigned int reallocStep) {
    _reallocStep = reallocStep;
  }

  template<typename T>
  DynVector<T>::~DynVector() {
  }
}
