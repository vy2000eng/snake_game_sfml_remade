//
// Created by voldemort on 8/5/23.
//

#ifndef SNAKE_GAME_SFML_REMADE_SNAKE_H
#define SNAKE_GAME_SFML_REMADE_SNAKE_H

#include "SFML/Graphics.hpp"


struct SnakeSegment{
    sf::RectangleShape snake;
    SnakeSegment *next;
    sf::Vector2f pos;



};
class Snake {
private:

    SnakeSegment * head;

    SnakeSegment* tail;
    float move_speed;
    float segment_width ;
    float segment_length;
    sf::Color color;

public:
    Snake();

    ~Snake();
    void intialize_snake();
    void draw(sf::RenderWindow *window);
    void move(int direction);
    void add_segment(sf::Vector2f pos);

};


#endif //SNAKE_GAME_SFML_REMADE_SNAKE_H
