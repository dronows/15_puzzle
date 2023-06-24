
cmake_minimum_required (VERSION 3.18)

find_package(Qt6 COMPONENTS  Core Gui Widgets Qml Quick REQUIRED) 

add_library(Puzzlelib STATIC)

set_target_properties(Puzzlelib PROPERTIES AUTOMOC ON)

target_link_libraries(Puzzlelib PRIVATE Qt6::Gui Qt6::Quick Qt6::Qml) 

qt_add_qml_module(Puzzlelib 
              URI PuzzleModule
              VERSION 1.0
              RESOURCE_PREFIX /imports
              QML_FILES GameBoard.qml
                        main.qml
                        Tile.qml )