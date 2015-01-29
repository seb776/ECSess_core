/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include "AFinalNode.hpp"

namespace ECS {
  class AManager : public AFinalNode {
  private:
  public:
    virtual void	mute(float time = -1);
    virtual void	unmute(void);
    virtual void	update(void);
    virtual void	remove(void);
  };
}
