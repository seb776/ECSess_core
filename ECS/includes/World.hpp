/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <vector>
#include <string>
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "TagManager.hpp"
#include "GroupManager.hpp"
#include "SyncIdManager.hpp"
#include "ECSEventManager.hpp"

namespace ECS {
  class World {
  private:
    std::vector<AManager *>		added_;
    Tools::IndexVector<AManager *>	managers_;
    std::vector<unsigned int>		deleted_;

    World(const World& o); // to see public
    World& operator=(const World& rhs);    
  public:
    World(void);
    ~World(void);

    EntityManager	entityManager;
    SystemManager	systemManager;
    TagManager		tagManager;
    GroupManager	groupManager;
    SyncIdManager	syncIdManager;
    ECSEventManager	eventManager;

    void	addManager(AManager *m);
    void	removeManager(AManager *m);
    void	update(void);
  };
  extern std::string	version;
}
