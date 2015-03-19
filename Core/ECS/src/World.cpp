/*
** Author: Sebastien Maire
** Contribs:
*/

#include "World.hpp"

namespace ECS {
  World::World(void) {
    entityManager.bindWorld(this);
    systemManager.bindWorld(this);
    groupManager.bindWorld(this);
    tagManager.bindWorld(this);
    syncIdManager.bindWorld(this);
    eventManager.bindWorld(this);

    this->addManager(&entityManager); // TODO: direct task (not delayed)
    this->addManager(&systemManager);
    this->addManager(&groupManager);
    this->addManager(&tagManager);
    this->addManager(&syncIdManager);
    this->addManager(&eventManager);
  }
  World::~World(void) {
  }

  void	World::addManager(AManager *m) {
    added_.push_back(m);
  }
  void	World::removeManager(AManager *m) {
    if (m->getUniqueId() > 3)
      deleted_.push_back(m->getUniqueId());
    else
      m->remove();
  }
  void	World::update(void) {
    unsigned int idx;

    // update data
    for (auto itDel = deleted_.begin();
	 itDel != deleted_.end();
	 ++itDel) {
      managers_.erase(*itDel);
    }
    for (auto itAdd = added_.begin();
	 itAdd != added_.end();
	 ++itAdd) {
      idx = managers_.insert(*itAdd);
      (*itAdd)->setUniqueId(idx);
    }
    // update managers
    for (idx = 0; idx < managers_.size(); ++idx) {
      managers_[idx]->update();
    }
  }

  std::string	version("1.0");
}

