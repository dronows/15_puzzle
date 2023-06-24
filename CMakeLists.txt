# CMakeList.txt: проект CMake для Cmake_15puzzle; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.18)


project ("Cmake_15puzzle")

set(CMAKE_AUTOMOC TRUE) 
set(CMAKE_AUTORCC ON) 
set(CMAKE_AUTOUIC ON) 

set(CMAKE_PREFIX_PATH "F:\\6.3.2\\msvc2019_64\\lib\\cmake") 
# Добавьте источник в исполняемый файл этого проекта.
add_executable(15_puzzle main.cpp) 

target_include_directories(15_puzzle PRIVATE 
                          ${CMAKE_CURRENT_SOURCE_DIR}/gamelib) 
find_package(Qt6 COMPONENTS  Core Gui Widgets Qml Quick REQUIRED) 


add_subdirectory(gamelib) 
add_subdirectory(qml) 

target_link_libraries(15_puzzle 
                      Qt6::Core
                      Qt6::Gui
                      Qt6::Widgets
                      Qt6::Qml
                      Qt6::Quick
                      Gamelib 
                      Puzzlelibplugin)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
