/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <string>
#include <map>
#include "AECSManager.hpp"

namespace ECS {
  class World;

  class TagManager : public AECSManager {
  private:
    std::map<std::string, AFinalNode *>	tagged_;
  public:
    ~TagManager(void);

    void	addTag(const std::string& tag, AFinalNode *n);
    void	removeTag(const std::string& tag);
    void	unregisterNode(const AFinalNode *n);
    void	update();
  };
}
