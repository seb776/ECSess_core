/*
** Author: Sebastien Maire
** Contribs:
*/

#include "Entity.hpp"
#include "SyncIdManager.hpp"

namespace ECS {
  SyncIdManager::SyncIdManager(void) {
  }

  SyncIdManager::~SyncIdManager(void) {
  }
  
  void	SyncIdManager::unregisterNode(AFinalNode *node) {
    for (unsigned int i = 0;
	 i < nodes_.getSize();
	 ++i) {
      if (node == nodes_[i]) {
	nodes_[i] = nullptr;
	break;
      }
    }
  }
  void	SyncIdManager::unregisterNode(unsigned int id) {
#ifdef	DEBUG_MODE
    if (id >= nodes_.getSize())
      return ;
#endif	// !DEBUG_MODE
    nodes_[id] = nullptr;
  }
  void	SyncIdManager::registerNode(unsigned int id, AFinalNode *node) {
#ifdef	DEBUG_MODE
    if (nodes_[id])
      throw std::logic_error("ECS: SyncIdManager: set an id which is already set.");
#endif	// !DEBUG_MODE
    nodes_[id] = node;
  }


  AFinalNode	*SyncIdManager::getNode(unsigned int id) {
    if (id < nodes_.getSize()) {
      return nodes_[id];
    }
    return nullptr;
  }

  Entity	*SyncIdManager::getEntity(unsigned int id) {
#ifdef	DEBUG_MODE
    return dynamic_cast<Entity *>(getNode(id));
#endif	// !DEBUG_MODE
    return static_cast<Entity *>(getNode(id));
  }

  void	SyncIdManager::update(void) {
    // nothing to update, tasks are done instant
  }
}
