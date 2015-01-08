/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <functional>
#include <tuple>
#include <time.h>
#include "IndexVector.hpp"
#include "ASystem.hpp"
#include "AECSManager.hpp"
#include "Timer.hpp"

namespace ECS {
  class Entity;

  class SystemManager : public AECSManager {
  private:
    // manipulate data
    std::vector<std::function<bool ()> >	entitiesTasks_;
    std::vector<std::function<bool ()> >	systemTasks_;

    // data
    Tools::IndexVector<ASystem *>	systems_;
    std::vector<unsigned int>		registeredEntities_;

    bool	addSystem_(ASystem *sys);
    bool	deleteSystem_(ASystem *sys);
    bool	muteSystem_(ASystem *sys, const Tools::Timer& begin, float time, bool& firstCall);
    bool	unmuteSystem_(ASystem *sys);
    bool	registerEntity_(unsigned int id);
    bool	unregisterEntity_(unsigned int id);
  public:
    ~SystemManager(void);
    template<typename T, typename... Args>
    static
    T		*createSystem(Args... args);
    void	addSystem(ASystem *sys);
    void	removeSystem(ASystem *sys);
    void	muteSystem(ASystem *sys, float time = -1.0);
    void	unmuteSystem(ASystem *sys);
    void	registerEntity(unsigned int id);
    void	unregisterEntity(unsigned int id);
    void	update(void);
  };
}

#include "SystemManager.ipp"
