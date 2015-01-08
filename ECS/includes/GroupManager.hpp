/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <string>
#include <vector>
#include <map>
#include "AECSManager.hpp"

namespace ECS {
  class World;

  class GroupManager : public AECSManager {
  private:
    std::map<std::string, std::vector<AFinalNode *> >	groups_;
  public:
    ~GroupManager(void);
    void	addToGroup(const std::string& group, AFinalNode *n);
    void	removeGroup(const std::string& group);
    void	removeFromGroup(const std::string& group, AFinalNode *n);
    void	unregisterNode(const AFinalNode *n);
    auto	getGroup(const std::string& name) -> std::vector<AFinalNode *>&;
    void	update();
  };
}
