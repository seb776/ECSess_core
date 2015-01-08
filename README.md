# ECS
===

An ECS design in c++14.

The goal is to provide a user friendly and optimized EntityComponentSystem.

## What's in ?
- EntityManager
- SystemManager
- BindingSystems: By tag, group, Type, TypeRestriction, Entity to System
- PoolManager to avoid heavy reallocation
- ScheduleManager
- Serializer to freeze the game and then store/retrieve the party.

## Build platform:
It will be available under GNU/Linux, Windows (to see xp compatibility) and maybe Mac OS

## Presets:
Many presets will be present to make it a real framework.
### Graphical presets
  - 2D
    - SDL
    - SFML
  - 3D
    - OPENGL ?
    
### Sounds presets

### Physical presets
  - Chipmunk
  
### Network presets

### Game presets
  - Life
  - PatternMovement
  - ...

You'll be able to add your own Entities, Components, Systems and Managers.

## TODO:
- Store Components on EntityManager contiguous
- Fill the repo with the actual c++11 version of the ECS
- bindTagged
- bindGrouped
- advancedTypeSystem
- Entity::bind(ASystem *)
- complete view functions (tree view of type restriction...)
- Conception for dll/so mistake
