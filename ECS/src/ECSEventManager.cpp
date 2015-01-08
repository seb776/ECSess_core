/*
** Author: Sebastien Maire
** Contribs:
*/

#include "ECSEventManager.hpp"

namespace ECS {
  ECSEventManager::ECSEventManager(void) {
  }

  bool	ECSEventManager::wrapCall_(std::function<void ()>& event, const Tools::Timer& begin, float time) const {
    if (begin.elapsedTime() > time) {
      event();
      return true;
    }
    return false;
  }

  void	ECSEventManager::addEvent(float time, std::function<void ()> event) {
    eventQueue_.push_back(std::bind(&ECSEventManager::wrapCall_, this, event, Tools::Timer(), time));
  }

  void	ECSEventManager::update(void) {
    for (unsigned int i = 0;
	 i < eventQueue_.size();) {
      if (eventQueue_[i]())
	eventQueue_.erase(eventQueue_.begin() + i);
      else
	++i;
    }
  }
}
