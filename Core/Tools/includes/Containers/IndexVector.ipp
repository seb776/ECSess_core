/*
** Author: Sebastien Maire
** Contribs:
*/

#include <algorithm>

namespace Tools {
  template<typename T>
  IndexVector<T>::IndexVector(const IndexVector<T>&) {

  }
  template<typename T>
  IndexVector<T>::IndexVector(void) :
    _defaultValue(T()) {
  }
  template<typename T>
  IndexVector<T>::~IndexVector() {
  }
  template<typename T>
  unsigned int        IndexVector<T>::insert(T value) {
    unsigned int      i;

    if (_freeSpaces.size()) {
      i = _freeSpaces.top();
      _data[i] = value;
      _freeSpaces.pop();
    }
    else {
      _data.push_back(value);
      i = static_cast<unsigned int>(_data.size()) - 1;
    }
    return i;
  }
  template<typename T>
  void        IndexVector<T>::setDefaultValue(T value) {
    _defaultValue = value;
  }
  template<typename T>
  void        IndexVector<T>::erase(unsigned int index) {
    _data[index] = _defaultValue;
    _freeSpaces.push(index);
  }
  template<typename T>
  inline unsigned int	IndexVector<T>::find(T value) const {
    return std::find(_data.begin(), _data.end(), value) - _data.begin();
  }
  template<typename T>
  const std::vector<T>&     IndexVector<T>::getVector() const { return _data; }
  template<typename T>
  T&  IndexVector<T>::operator[](unsigned int index) {
    return _data[index];
  }
  template<typename T>
  const T&	IndexVector<T>::operator[](unsigned int index) const {
    return _data[index];
  }

  // return the allocated size
  template<typename T>
  unsigned int        IndexVector<T>::size() const {
    return static_cast<unsigned int>(_data.size());
  }

  // return the number of elements inside
  template<typename T>
  unsigned int	IndexVector<T>::count(void) const {
    return _data.size() - _freeSpaces.size();
  }
}
