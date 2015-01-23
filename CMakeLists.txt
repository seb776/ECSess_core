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
    "./ECS/includes/"
    "./Tools/includes/"
    "./Tools/includes/Type"
    "./Tools/includes/Containers"
)

file(
    GLOB_RECURSE
    "${CMAKE_PROJECT_NAME}_srcs"
    ECS/*.cpp
    Tools/*.cpp
)

add_library(
    core
    OBJECT
    ${ECSess_srcs}
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
