/*
** Author: Sebastien Maire
** Contribs:
*/

#include "GroupManager.hpp"

namespace ECS {
  GroupManager::~GroupManager(void) {
  }

  void	GroupManager::addToGroup(const std::string& group, AFinalNode *n) {
  }
  void	GroupManager::removeGroup(const std::string& group) {
  }
  void	GroupManager::removeFromGroup(const std::string& group, AFinalNode *n) {
  }
  void	GroupManager::unregisterNode(const AFinalNode *n) {
    
  }
  auto	GroupManager::getGroup(const std::string& name) -> std::vector<AFinalNode *>&{
    return groups_[name];
  }

  void	GroupManager::update(void) {
    // do things
  }
}
