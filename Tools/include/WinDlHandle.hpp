/*
** Author: Yessin Abd-el rahman
** Contribs: Sebastien Maire
*/

#pragma once

#include <windows.h>
#include "ADlHandle.hpp"

class	WinDlHandle : public ADlHandle<HMODULE> {
  private:
    void	*loadSym(std::string const& symName);
    WinDlHandle(WinDlHandle const& u);
    void	operator=(WinDlHandle const&);
  public:
    ~WinDlHandle();
    void	open(std::string const& libName);
    void	close();
};
