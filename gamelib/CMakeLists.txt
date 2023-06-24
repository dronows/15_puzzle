
cmake_minimum_required (VERSION 3.18)


find_package(Qt6 COMPONENTS  Core Gui Widgets  REQUIRED)

add_library(Gamelib STATIC GameBoard.cpp GameBoard.h)

set_target_properties(Gamelib PROPERTIES AUTOMOC ON)
target_link_libraries(Gamelib PRIVATE Qt6::Gui Qt6::Core Qt6::Widgets)
