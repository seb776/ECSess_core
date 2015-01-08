/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <chrono>

namespace Tools {
  class	Timer {
  private:
    std::chrono::time_point<std::chrono::system_clock>	startTime_;

  public:
    Timer(void);
    void	restart(void);
    float	elapsedTime(void) const;
  };
}
