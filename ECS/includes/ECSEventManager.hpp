/*
** Author: Sebastien Maire
** Contribs:
*/

#include <vector>
#include <functional>
#include "AECSManager.hpp"
#include "Timer.hpp"

namespace ECS {
  class ECSEventManager : public AECSManager {
    std::vector<std::function<bool ()> >	eventQueue_;

    bool	wrapCall_(std::function<void ()>& event, const Tools::Timer& begin, float time) const;
  public:
    ECSEventManager(void);
    void	addEvent(float time, std::function<void ()> event);
    void	update(void);
  };
}
