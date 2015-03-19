/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <cstddef>
#include <vector>
#include <stack>

// This vector is fast access/push/remove
// In the best cases complexity could be O(1) on push,
// 0(n) on the worst

namespace       Tools {
  template<typename T>
  class IndexVector {
  private:
    std::vector<T>      _data;
    std::stack<unsigned int>    _freeSpaces;
    T   _defaultValue;

    // const IndexVector<T>& operator=(const IndexVector<T>&);

  public:
    IndexVector(const IndexVector<T>&); // because of DynVector Construction of default value
    IndexVector(void);
    virtual ~IndexVector();
    auto        insert(T value) -> unsigned int;
    void        erase(unsigned int index);
    auto	find(T value) const -> unsigned int;
    void        setDefaultValue(T value);
    auto	getVector() const -> const std::vector<T>&;
    T&		operator[](unsigned int index);
    const T&	operator[](unsigned int index) const;
    auto        size() const -> unsigned int; // return the allocated size
    unsigned int	count(void) const; // return the number of elements inside
  };
}

#include "IndexVector.ipp"
