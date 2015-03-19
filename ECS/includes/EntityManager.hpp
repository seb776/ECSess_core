/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <functional>
#include "IndexVector.hpp"
#include "AECSManager.hpp"
#include "Timer.hpp"

namespace ECS {
  class World;
  class Entity;

  class EntityManager : public AECSManager {
  private:
    std::vector<std::function<bool ()> >	tasks_;
    Tools::IndexVector<Entity *>		entities_;

    bool 	addEntity_(Entity *e);
    bool	deleteEntity_(unsigned int entId);
    bool	muteEntity_(Entity *e, const Tools::Timer& begin, float time, bool& firstCall);
    bool	unmuteEntity_(Entity *e);
  public:
    ~EntityManager(void);

    // for user purpose
    static
    Entity	*createEntity(void);
    void	addEntity(Entity *ent);
    Entity	*getEntity(unsigned int id);
    auto	getEntities(void) -> Tools::IndexVector<Entity *>&;
    void	muteEntity(Entity *ent, float time = -1.0f);
    void	unmuteEntity(Entity *ent);
    void	removeEntity(Entity *ent);
    void	removeEntity(unsigned int id);
    void	update();

  };
}
