//
// Created by voldemort on 8/5/23.
//

#ifndef SNAKE_GAME_SFML_REMADE_GAME_H
#define SNAKE_GAME_SFML_REMADE_GAME_H
#include "SFML/Graphics.hpp"
#include "Snake.h"


class Game {
private:
    //variables
    enum Direction{
      left,right,up,down
    };

    Direction dir;
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode vm;
    //sf::RectangleShape snake;
    int direction;
    Snake snake;
    SnakeSegment start;



    void initialize_variables();
    void initialize_window();
    //void initialize_snake();





public:
    Game();
    virtual ~Game();
    const bool get_window_is_open() const;
    void poll_events();
    void spawn_snake();
    void render_snake();
    void update_snake();
    void update();
    void render();

};


#endif //SNAKE_GAME_SFML_REMADE_GAME_H
