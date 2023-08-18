//
// Created by voldemort on 8/15/23.
//

#include "SnakeFood.h"

SnakeFood::SnakeFood() {
    this->number_of_food_pieces = 1;
    this->segment = new SnakeSegment[number_of_food_pieces];
    srand((unsigned) time(NULL));
}


SnakeFood::~SnakeFood() {
    delete segment;

}

void SnakeFood::set_random_food_position(sf::RenderWindow *window) {
    for(int i = 0; i < number_of_food_pieces; i++){
        segment[i].pos = sf::Vector2f (
                static_cast<float>(rand()% static_cast<int>(window->getSize().x - this->getSnakeSize())),
                static_cast<float>(rand()% static_cast<int>(window->getSize().y - this->getSnakeSize()))

        );

    }

}

void SnakeFood::draw(sf::RenderWindow *window) {
    //Snake::draw(window);
//    SnakeSegment* current = this->head;
//    while(current != nullptr){
//        sf::RectangleShape segment(sf::Vector2f(this->segment_width, this->segment_length));
//
//        segment.setPosition(current->pos);
//        segment.setFillColor(color);
//        window->draw(segment);
//        current = current->next;

    for(int i = 0; i<number_of_food_pieces; i++ ){
        sf::RectangleShape segment (sf::Vector2f (getSegmentLength(),getSegmentWidth()));
        segment.setPosition(this->segment[i].pos);
        segment.setFillColor(sf::Color::Blue);
        window->draw(segment);

    }
}




