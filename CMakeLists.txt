##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 3.0)

project(ECSess)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./bin/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./bin/dyn)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

if(UNIX)
    set(
	GLOBAL_CXX_FLAGS
	"-std=c++11 -fPIC"
    )
elseif(WIN32)
    
endif()

include_directories(
    "./Core/ECS/includes/"
    "./Core/Tools/includes/"
    "./Core/Tools/includes/Type"
    "./Core/Tools/includes/Containers"
)

set(
    "${CMAKE_PROJECT_NAME}_srcs"
    "Core/ECS/src/AComponent.cpp"
    "Core/ECS/src/AECSManager.cpp"
    "Core/ECS/src/AFinalNode.cpp"
    "Core/ECS/src/AManager.cpp"
    "Core/ECS/src/ASystem.cpp"
    "Core/ECS/src/ECSEventManager.cpp"
    "Core/ECS/src/Entity.cpp"
    "Core/ECS/src/EntityManager.cpp"
    "Core/ECS/src/GroupManager.cpp"
    "Core/ECS/src/SyncIdManager.cpp"
    "Core/ECS/src/SystemManager.cpp"
    "Core/ECS/src/TagManager.cpp"
    "Core/ECS/src/World.cpp"
)

set(
    "${CMAKE_PROJECT_NAME}_includes"
    "Core/ECS/includes/AComponent.hpp"
    "Core/ECS/includes/AComponent.ipp"
    "Core/ECS/includes/AECSManager.hpp"
    "Core/ECS/includes/AFinalNode.hpp"
    "Core/ECS/includes/AManager.hpp"
    "Core/ECS/includes/ASystem.hpp"
    "Core/ECS/includes/ASystem.ipp"
    "Core/ECS/includes/ECSEventManager.hpp"
    "Core/ECS/includes/ECSexceptions.hpp"
    "Core/ECS/includes/Entity.hpp"
    "Core/ECS/includes/Entity.ipp"
    "Core/ECS/includes/EntityManager.hpp"
    "Core/ECS/includes/GroupManager.hpp"
    "Core/ECS/includes/SyncIdManager.hpp"
    "Core/ECS/includes/SystemManager.hpp"
    "Core/ECS/includes/SystemManager.ipp"
    "Core/ECS/includes/TagManager.hpp"
    "Core/ECS/includes/World.hpp"
)


source_group("Includes\\" FILES ${${CMAKE_PROJECT_NAME}_includes})
source_group("Sources\\" FILES ${${CMAKE_PROJECT_NAME}_srcs})


## Common  sources for shared and static libraries
add_library(
    core
    OBJECT
    ${${CMAKE_PROJECT_NAME}_srcs}
    ${${CMAKE_PROJECT_NAME}_includes}
)

add_library(
    "${CMAKE_PROJECT_NAME}"
    SHARED
    $<TARGET_OBJECTS:core>
)

add_library(
    "${CMAKE_PROJECT_NAME}_static"
    STATIC
    $<TARGET_OBJECTS:core>
)

set_target_properties(
    "core"
    PROPERTIES
    COMPILE_FLAGS "${GLOBAL_CXX_FLAGS}"
)
