//
// Created by voldemort on 8/5/23.
//

#ifndef SNAKE_GAME_SFML_REMADE_GAME_H
#define SNAKE_GAME_SFML_REMADE_GAME_H
#include "SFML/Graphics.hpp"
#include "Snake.h"
#include "SnakeFood.h"
#define SNAKE_SPAWN_TIMER_MAX = 10



class Game {
private:
    //variables
    enum Direction{
      left,right,up,down
    };


    SnakeFood food;

    Direction dir;
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode vm;
    int direction;
    Snake snake;
    SnakeSegment start;

    int snake_spawn_timer;
    void initialize_variables();

    void initialize_window();
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
    const Snake &getSnake() const;
    //void initialize_snake();
    sf::RenderWindow *getWindow() const;

};


#endif //SNAKE_GAME_SFML_REMADE_GAME_H
