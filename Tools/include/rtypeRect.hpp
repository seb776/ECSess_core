/*
 * R-Type, Vector.hpp
 * Loic Lefloch
 */

#pragma once 

/*
** TODO: Bounds
*/

#include "Vector.hpp"

namespace Tools {

  template <typename T>
  class RtypeRect {
  public:
    T left;   
    T top;    
    T width;  
    T height;

    RtypeRect() : left(0), top(0), width(0), height(0) {
    }

    RtypeRect(T left, T top, T width, T height) : left(left), top(top), width(width), height(height) {
    }

    RtypeRect(const Tools::Vector2<T>& position, const Tools::Vector2<T>& size) : left(position.x), top(position.y), width(size.x), height(size.y) {
    }

    bool contains(T x, T y) const {
      T minX = std::min(left, static_cast<T>(left + width));
      T maxX = std::max(left, static_cast<T>(left + width));
      T minY = std::min(top, static_cast<T>(top + height));
      T maxY = std::max(top, static_cast<T>(top + height));
      return (x >= minX) && (x < maxX) && (y >= minY) && (y < maxY);
    }

    bool contains(const Tools::Vector2<T>& vec) const {
      return contains(vec.x, vec.y);
    }

    bool intersects(const RtypeRect<T>& rect) const {
      T otherMinX = std::min(rect.left, static_cast<T>(rect.left + rect.width));
      T otherMaxX = std::max(rect.left, static_cast<T>(rect.left + rect.width));
      T otherMinY = std::min(rect.top, static_cast<T>(rect.top + rect.height));
      T otherMaxY = std::max(rect.top, static_cast<T>(rect.top + rect.height));

      T currentMinX = std::min(left, static_cast<T>(left + width));
      T currentMaxX = std::max(left, static_cast<T>(left + width));
      T currentMinY = std::min(top, static_cast<T>(top + height));
      T currentMaxY = std::max(top, static_cast<T>(top + height));

      T interLeft   = std::max(currentMinX, otherMinX);
      T interTop    = std::max(currentMinY, otherMinY);
      T interRight  = std::min(currentMaxX, otherMaxX);
      T interBottom = std::min(currentMaxY, otherMaxY);

      if ((interLeft < interRight) && (interTop < interBottom)) {
	return true;
      }
      return false;
    }

    RtypeRect<T> getGlobalBounds() const {
      return RtypeRect<T>(left, top, width, height);
    }

  };

  template<typename T>
  inline bool operator ==(const RtypeRect<T>& left, const RtypeRect<T>& right) {
    return ((left.left == right.left)
	    && (left.width == right.width)
	    && (left.top == right.top)
	    && (left.height == right.height));
  }

  template<typename T>
  inline bool operator !=(const RtypeRect<T>& current, const RtypeRect<T>& other) {
    return !(current == other);
  }

  typedef Tools::RtypeRect<int>   IntRtypeRect;
  typedef Tools::RtypeRect<float> FloatRtypeRect;
}
