/*
** Author: Yessin Abd-el rahman
** Contribs: Sebastien Maire
*/

#pragma once

#ifdef _WIN32
# include "WinDlHandle.hpp"
typedef WinDlHandle DlHandle;
#elif defined  __UNIX__
#include "UnixDlHandle.hpp"
typedef UnixDlHandle DlHandle;
#endif


