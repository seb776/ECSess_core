/*
** Author: Sebastien Maire
** Contribs:
*/

#include <stdexcept>
#include "World.hpp"
#include "TagManager.hpp"

namespace ECS {
  TagManager::~TagManager(void) {
  }
  void TagManager::addTag(const std::string& tag, AFinalNode *n) {
    auto itNode = tagged_.find(tag);
    if (itNode == tagged_.end())
      tagged_[tag] = n;
    else
      throw std::logic_error("ECS: Trying to tag a node but the tag \"" + tag + "\" is already used.");
  }
  void TagManager::removeTag(const std::string& tag) {
    tagged_.erase(tagged_.find(tag));
  }
  void TagManager::unregisterNode(const AFinalNode *n) {
    
  }
  void TagManager::update(void) {
  }
}
