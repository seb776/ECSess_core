/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <stdexcept>
#include "AECSManager.hpp"
#include "DynVector.hpp"

namespace ECS {
  class Entity;

  class SyncIdManager : public AECSManager {
    Tools::DynVector<AFinalNode *>	nodes_;
  public:
    SyncIdManager(void);
    ~SyncIdManager(void);

    AFinalNode	*getNode(unsigned int id);
    Entity	*getEntity(unsigned int id);
    void	unregisterNode(AFinalNode *node); // called only when an Entity is deleted
    void	unregisterNode(unsigned int id);
    void	registerNode(unsigned int id, AFinalNode *node);

    void	update(void);
  };
}
