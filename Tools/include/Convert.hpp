/**
 * Rtype, convert.hpp
 * Loic Lefloch
 */

#pragma once

#include <sstream>
#include <string>

namespace Tools {

  namespace Convert {
    /*
     ** conversion string -> T
     */
    template<typename T>
      T   StringTo(const std::string &str)
      {
        std::stringstream ss;
        T     value;

        ss << str;
        ss >> value;

        return value;
      }

    /*
     ** convestion T -> string
     */
    template<typename T>
      std::string ToString(T value)
      {
        std::ostringstream  ss;

        ss << value;

        return ss.str();
      }

  }
}
