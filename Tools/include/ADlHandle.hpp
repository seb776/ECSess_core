/*
** Author: Yessin Abd-el rahman
** Contribs: Sebastien Maire
*/

#pragma once

#include <string>

template<typename T>
class	ADlHandle {
  protected:
    T	handle;
    virtual void	*loadSym(std::string const&) = 0;
  public:
    virtual ~ADlHandle() {}
    virtual void	open(std::string const&) = 0;
    virtual void	close(void) = 0;
    template<typename U>
    U	getSym(std::string const& symName);
};

#include "ADlHandle.ipp"
