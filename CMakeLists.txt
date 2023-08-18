cmake_minimum_required(VERSION 3.25)
project(snake_game_sfml_remade)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(snake_game_sfml_remade main.cpp Game.cpp Game.h Snake.cpp Snake.h
        SnakeFood.cpp
        SnakeFood.h
)
target_link_libraries(snake_game_sfml_remade sfml-graphics sfml-window sfml-system)

