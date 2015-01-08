/*
** Author: Yessin Abd-el rahman
** Contribs: Sebastien Maire
*/

#ifdef __UNIX__

#include <stdexcept>
#include "UnixDlHandle.hpp"

UnixDlHandle::~UnixDlHandle() {}

void	*UnixDlHandle::loadSym(std::string const& symName) {
  return dlsym(this->handle, symName.c_str());
}

void	UnixDlHandle::open(std::string const& libName) {
  std::string name = "./lib" + libName + ".so"; // to change
  if (!(this->handle = dlopen(name.c_str(), RTLD_LAZY))) {
  	std::string const error = "Can't find library: " + name;
    throw std::logic_error(error.c_str());
	}
}

void UnixDlHandle::close() {
  dlclose(this->handle);
}

#endif // __UNIX__
