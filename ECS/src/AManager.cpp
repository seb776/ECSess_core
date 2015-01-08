/*
** Author: Sebastien Maire
** Contribs:
*/

#include <stdexcept>
#include "AManager.hpp"

namespace ECS {
  void	AManager::mute(float time) {
    throw std::logic_error("ECS: Mute on managers is not implemented yet.");
  }
  void	AManager::unmute(void) {
    throw std::logic_error("ECS: Unmute on managers is not implemented yet.");
  }
  void	AManager::remove(void) {
throw std::logic_error("ECS: Remove on managers is not implemented yet.");
  }

  void	AManager::update(void) {
  }
}
