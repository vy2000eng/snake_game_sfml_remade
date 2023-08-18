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
    int snake_size;



public:
    //constructor
    Snake();
    //destructor
    ~Snake();


    SnakeSegment *getHead() const;

    float getSegmentWidth() const;

    float getSegmentLength() const;

    // methods
    void draw(sf::RenderWindow *window);
    void move(int direction,sf::RenderWindow *window) ;
    void add_segment(sf::Vector2f pos);
    void pre_pend(SnakeSegment* segment);

    int getSnakeSize() const;

};


#endif //SNAKE_GAME_SFML_REMADE_SNAKE_H
