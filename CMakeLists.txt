cmake_minimum_required(VERSION 3.20)
project(Gra2d)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 14)


add_executable(Gra2d main.cpp GameEngine/GameEngine.cpp GameEngine/GameEngine.h GUI/Button.h States/MenuState.h
        States/State.h States/OptionState.h States/MenuState.cpp States/OptionState.cpp States/GameState.cpp
        States/GameState.h Entity/Entity.cpp Entity/Entity.h Entity/Player/Player.cpp Entity/Player/Player.h Entity/Enemy/Enemy.cpp
        Entity/Enemy/Enemy.h TileMap/Tile.cpp TileMap/Tile.h TileMap/TileMap.cpp TileMap/TileMap.h Animation/Animation.cpp
        Animation/Animation.h GameData/GameStateData.h)
include_directories(/Users/jakubstawiarz/Desktop/gra/SFML-2.5.1-macos-clang/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Gra2d sfml-system sfml-window sfml-graphics sfml-audio sfml-network)