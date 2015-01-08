/*
 * R-Type, RtypeVector.hpp
 * Loic Lefloch
 */

#pragma once 

namespace Tools {
  template <typename T>
  class RtypeVector2 {
  public:
    RtypeVector2();
    RtypeVector2(T x, T y) : x(x), y(y) {}

    T x;
    T y;
  };

  template <typename T>
  inline RtypeVector2<T> operator-(const RtypeVector2<T>& other) {
    return RtypeVector2<T>(-other.x, -other.y);
  }

  template <typename T>
  inline RtypeVector2<T>& operator+=(RtypeVector2<T>& current, const RtypeVector2<T>& other) {
    current.x += other.x;
    current.y += other.y;
    return current;
  }

  template <typename T>
  inline RtypeVector2<T>& operator-=(RtypeVector2<T>& current, const RtypeVector2<T>& other) {
    current.x += other.x;
    current.y += other.y;
    return current;
  }

  template <typename T>
  inline RtypeVector2<T> operator+(const RtypeVector2<T>& current, const RtypeVector2<T>& other) {
    return RtypeVector2<T>(current.x + other.x, current.y + other.y);
  }

  template <typename T>
  inline RtypeVector2<T> operator-(const RtypeVector2<T>& current, const RtypeVector2<T>& other) {
    return RtypeVector2<T>(current.x - other.x, current.y - other.y);
  }

  template <typename T>
  inline RtypeVector2<T> operator*(const RtypeVector2<T>& current, T other) {
    return RtypeVector2<T>(current.x * other, current.y * other);
  }

  template <typename T>
  inline RtypeVector2<T> operator*(T current, const RtypeVector2<T>& other) {
    return RtypeVector2<T>(other.x * current, other.y * current);
  }

  template <typename T>
  inline RtypeVector2<T>& operator*=(RtypeVector2<T>& current, T other) {
    current.x *= other;
    current.y *= other;
    return current;
  }

  template <typename T>
  RtypeVector2<T> operator/(const RtypeVector2<T>& current, T other) {
    return RtypeVector2<T>(current.x / other, current.y / other);
  }

  template <typename T>
  inline RtypeVector2<T>& operator/=(RtypeVector2<T>& current, T other) {
    current.x /= other;
    current.y /= other;

    return current;
  }

  template <typename T>
  inline bool operator==(const RtypeVector2<T>& current, const RtypeVector2<T>& other) {
    return (current.x == other.x) && (current.y == other.y);
  }

  template <typename T>
  inline bool operator!=(const RtypeVector2<T>& current, const RtypeVector2<T>& other) {
    return (current.x != other.x) || (current.y != other.y);
  }

  // Define the most common types
  typedef RtypeVector2<int>          RtypeVector2i;
  typedef RtypeVector2<unsigned int> RtypeVector2u;
  typedef RtypeVector2<float>        RtypeVector2f;

}
