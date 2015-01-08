/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <vector>
#include "AFinalNode.hpp"
#include "TypeId.hpp"

namespace ECS {
  class Entity;
  class World;

  class ASystem : public AFinalNode {
  protected:
    std::vector<unsigned int>	entities_;
    // unsigned int		typeId_;
    Tools::TypeId		typeId_;
  public:
    ASystem(void);
    virtual ~ASystem(void);



    void bindType(unsigned int typeId); // to bind entities of type typeId
    template<typename T>
    void bindType(void);
    void bindType(const Tools::TypeId& type);
    bool isBoundTo(unsigned int id); // to know if an entity match the system restriction
    void bindTagged(const std::string& name) {} // to bind tagged entities
    void bindGrouped(const std::string& name) {} // to bind grouped entities
    void submitEntity(unsigned int id);
    void cancelEntity(unsigned int id);
    void mute(float time = -1); // Not implemented
    void unmute(void); // Not implemented
    void remove(void);
    void clear(void);
    void process();
    virtual void processAll(std::vector<unsigned int>& entities);
    virtual void processEntity(Entity *ent) = 0;
  };
}

#include "ASystem.ipp"
