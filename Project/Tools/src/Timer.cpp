/*
** Author: Sebastien Maire
** Contribs:
*/

#include "Timer.hpp"

namespace Tools {
  Timer::Timer(void) {
    this->restart();
  }

  void	Timer::restart(void) {
    startTime_ = std::chrono::high_resolution_clock::now();
  }

  float	Timer::elapsedTime(void) const {
    auto endTime = std::chrono::high_resolution_clock::now();
    auto f_ms =  std::chrono::duration<float, std::chrono::seconds::period>(endTime - startTime_);
    return f_ms.count();
  }
}
