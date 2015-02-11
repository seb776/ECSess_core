##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 3.0)

projects(test_use)

file(
    GLOB_RECURSE
    "${CMAKE_PROJECT_NAME}_srcs"
    srcs/*.cpp
)

add_exectuable(
    "${CMAKE_PROJECT_NAME}"
    ${CMAKE_PROJECT_NAME}_srcs
)

target_link_libraries(
    "${CMAKE_PROJECT_NAME}"
    "libECSess.so"
)
