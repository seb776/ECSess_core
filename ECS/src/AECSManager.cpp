/*
** Author: Sebastien Maire
** Contribs:
*/

#include <stdexcept>
#include "ECSexceptions.hpp"
#include "AECSManager.hpp"

namespace ECS {
  void	AECSManager::remove(void) {
    throw std::logic_error("Cannot remove mandatory managers.");
  }
  void	AECSManager::mute(float) {
    throw std::logic_error("Cannot mute mandatory managers.");
  }
  void	AECSManager::unmute(void) {
    throw std::logic_error("Cannot unmute mandatory managers.");
  }
  
}
