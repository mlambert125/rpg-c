cmake_minimum_required(VERSION 3.16)
project(rpg)
set(CMAKE_C_FLAGS "--std=c2x -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter")
set(CMAKE_C_COMPILER "/usr/bin/clang")

set(SourceFiles
    src/main.c
)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(Lua 5.4 REQUIRED)

include_directories(${GLIB_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_TTF_INCLUDE_DIRS})
include_directories(${LUA_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SourceFiles})
target_link_libraries(
    ${PROJECT_NAME}
    ${GLIB_LIBRARIES}
    ${SDL2_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${LUA_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
