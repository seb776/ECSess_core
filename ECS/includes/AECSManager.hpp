/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include "AManager.hpp"

namespace ECS {
  class	AECSManager : public AManager {
    void	remove(void);
    void	mute(float);
    void	unmute(void);
  };
}
