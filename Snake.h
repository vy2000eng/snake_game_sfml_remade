//
// Created by voldemort on 8/5/23.
//

#ifndef SNAKE_GAME_SFML_REMADE_SNAKE_H
#define SNAKE_GAME_SFML_REMADE_SNAKE_H

#include "SFML/Graphics.hpp"


struct SnakeSegment{
    /*
     * structure of the snake segments:
     *   - what it is, is a doubly linked list
     *
     * */
    sf::RectangleShape snake;
    SnakeSegment *next;
    SnakeSegment *prev;
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
    //constructor
    Snake();
    //destructor
    ~Snake();

    // methods
    void draw(sf::RenderWindow *window);
    void move(int direction);
    void add_segment(sf::Vector2f pos);
    void pre_pend(SnakeSegment* segment);

};


#endif //SNAKE_GAME_SFML_REMADE_SNAKE_H
