/*
** Author: Yessin Abd-el rahman
** Contribs: Sebastien Maire
*/

#ifdef _WIN32

#include <stdexcept>
#include "WinDlHandle.hpp"

void	*WinDlHandle::loadSym(std::string const& symName) {
  return GetProcAddress(this->handle, symName.c_str());
}

WinDlHandle::~WinDlHandle() {}

void		WinDlHandle::open(std::string const& libName) {
	std::string name = libName + ".so";
    if (!(this->handle = LoadLibrary(name.c_str()))) {
    	std::string const error = "Can't find library: " + name;
      throw std::logic_error(error.c_str());
    }
  }

void		WinDlHandle::close() {
  FreeLibrary(this->handle);
}

#endif
