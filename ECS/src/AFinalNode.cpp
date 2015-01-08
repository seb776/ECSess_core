/*
** Author: Sebastien Maire
** Contribs:
*/

#include "World.hpp"
#include "AFinalNode.hpp"

namespace ECS {
  AFinalNode::AFinalNode(void) : 
    uniqueId_(static_cast<unsigned int>(-1)),
    world_(nullptr),
    muted_(false) {
  }
  AFinalNode::~AFinalNode() {
  }

  unsigned int AFinalNode::getUniqueId(void) { return uniqueId_; }
  void AFinalNode::setUniqueId(unsigned int id) { uniqueId_ = id; }
  void AFinalNode::bindWorld(World *w) { world_ = w; }
  void AFinalNode::unbindWorld(void) { world_ = nullptr; }
  bool AFinalNode::isMuted(void) const { return muted_; }
  void AFinalNode::setMuted(bool b) { muted_ = b; }
}
