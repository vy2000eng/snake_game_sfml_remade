//
// Created by voldemort on 8/15/23.
//

#ifndef SNAKE_GAME_SFML_REMADE_SNAKEFOOD_H
#define SNAKE_GAME_SFML_REMADE_SNAKEFOOD_H

#include "SFML/Graphics.hpp"
#include "Snake.h"
#include "SFML/Graphics.hpp"
#include <cstdlib>  // for srand() and rand()
#include <ctime>

class SnakeFood: public Snake{
    SnakeSegment *segment;

    int number_of_food_pieces;

   // std::vector<sf::RectangleShape> food_items;
    sf::RectangleShape food_items;
public:
        SnakeFood();
        void set_random_food_position(sf::RenderWindow * renderWindow);
        void draw(sf::RenderWindow *window);


        ~SnakeFood();






};


#endif //SNAKE_GAME_SFML_REMADE_SNAKEFOOD_H
