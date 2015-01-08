/*
** Author: Yessin Abd-el rahman
** Contribs: Sebastien Maire
*/

#pragma once

#include <dlfcn.h>
#include "ADlHandle.hpp"

class	UnixDlHandle : public ADlHandle<void *> {
  private:
    void	*loadSym(std::string const& symName);
  public:
    ~UnixDlHandle();
    void	open(std::string const& libName);
    void	close();
};
