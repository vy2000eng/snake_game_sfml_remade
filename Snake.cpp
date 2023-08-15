//
// Created by voldemort on 8/5/23.
//

#include "Snake.h"
#include <stdio.h>
#include <iostream>


void Snake::add_segment(sf::Vector2f pos) {
    /* Description:
     * - creates a new segment
     * - sets the size of the segment
     * - sets the color of the segment
     * - sets the position of the segment
     * - connects pointers
     * */
    SnakeSegment *segment = new SnakeSegment;
    segment->snake.setSize(sf::Vector2f( segment_length,segment_width));
    segment->snake.setFillColor(color);
    segment->pos =  pos;
    if(head->next == nullptr){
        head->next = segment;
        segment->prev = head;
        tail = segment;
    }else{
        segment->prev = tail;
        tail->next = segment;
        tail= segment;
    }
}




Snake::Snake() {

    /* CONSTRUCTOR FOR THE SNAKE CLASS. Called inside the game class.
     * initializes:
     *  - head,
     *  - segment_length,
     *  - position,
     *  - size
     *  - next
     *  what it does:
     *  - points head to the first node
     *  - points tail to the first node
     *  - points next and prev to the first node, because there is only one node currently
     *
     * */
    this->head = new SnakeSegment;
    color = sf::Color::Magenta;
    this->segment_length = 25.f;
    this->segment_width = 25.f;
    head->pos = sf::Vector2f (20.f,20.f);
    head->next = nullptr;
    tail = head;

}

Snake::~Snake() {
    SnakeSegment *curr = head;
    while(curr != nullptr){
        SnakeSegment *temp = curr;
        curr = curr->next;
        delete temp;

    }
    this->head = nullptr;
    this->tail = nullptr;


}

void Snake::draw(sf::RenderWindow *window) {
    SnakeSegment* current = this->head;
    while(current != nullptr){
        sf::RectangleShape segment(sf::Vector2f(this->segment_width, this->segment_length));

        segment.setPosition(current->pos);
        segment.setFillColor(color);
        window->draw(segment);
        current = current->next;

    }

}

void Snake::move(int direction, sf::RenderWindow *window) {
    /**
     * Description:
     *  - creates a new segment and makes it the head pointer
     *  - adds the new segment to the front of the snake
     *  - reassigns the tail to tail->prev
     *  - deletes the tail
     * */
    SnakeSegment* segment = new SnakeSegment;
    segment->next =nullptr, segment->prev = nullptr;

    sf::Vector2u windowSize = window->getSize();
    unsigned int windowWidth = windowSize.x;
    unsigned int windowHeight = windowSize.y;


    switch (direction) {
        case 0://left
            segment->pos = sf::Vector2f (head->pos.x-30, head->pos.y);
            break;
        case 1://right
            segment->pos = sf::Vector2f (head->pos.x+30.f, head->pos.y);
            break;
        case 2://up
            segment->pos = sf::Vector2f (head->pos.x, head->pos.y-30.f);
            break;
        case 3://down
            segment->pos = sf::Vector2f (head->pos.x, head->pos.y+30.f);
            break;
    }

    // boundary checks
    if (segment->pos.x < 0) {
        segment->pos.x =(float ) windowWidth - 30.f; // move to the other side
    }
    else if (segment->pos.x > (float) windowWidth) {
        segment->pos.x = 0.f; // move to the other side
    }

    if (segment->pos.y < 0) {
        segment->pos.y = (float )windowHeight - 30.f; // move to the other side
    }
    else if (segment->pos.y > (float)windowHeight) {
        segment->pos.y = 0.f; // move to the other side
    }
    this->pre_pend(segment);
    tail = tail->prev;
    tail->next = nullptr;


}

void Snake::pre_pend(SnakeSegment *segment) {
   head->prev = segment;
   segment->next= head;
   head= segment;

}

SnakeSegment *Snake::getHead() const {
    return head;
}



