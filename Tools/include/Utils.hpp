/**
 * Rtype, Utils.hpp
 * Loic Lefloch
 */

#pragma once

#include <string>
#include <sys/stat.h>

/*
 * A set of usefuls inline functions
 */
namespace Tools {

  inline bool FileExists(std::string const& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
  }

}
