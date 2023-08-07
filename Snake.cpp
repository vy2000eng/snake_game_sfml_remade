//
// Created by voldemort on 8/5/23.
//

#include "Snake.h"
#include <stdio.h>



void Snake::add_segment(sf::Vector2f pos) {
    SnakeSegment *segment = new SnakeSegment;
    segment->snake.setSize(sf::Vector2f( segment_length,segment_width));
    segment->snake.setFillColor(color);
    segment->pos =  pos;
//    printf("%f \n ", this->tail->pos.x+25.f);
//    printf("%f \n ", this->tail->pos.y+25.f);
    tail->next = segment;
    tail = segment;

}




Snake::Snake() {
    this->head = new SnakeSegment;
    color = sf::Color::Magenta;
    this->segment_length = 25.f;
    this->segment_width = 25.f;
    //head->pos = sf::Vector2f (20.f,20.f);

    head->snake.setSize(sf::Vector2f (segment_length, segment_width));
    head->pos = sf::Vector2f (20.f, 20.f);
   // head->snake.setPosition(head->pos);
    head->next = nullptr;
    this->move_speed = 1.f;
    this->tail = head;


}

Snake::~Snake() {
    SnakeSegment *curr = head;
    while(curr != nullptr){
        SnakeSegment *temp = curr;
        curr = curr->next;
        delete temp;

    }

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

void Snake::move(int direction) {
    SnakeSegment * temp = this->head;
    sf::Vector2f new_pos = sf::Vector2f (temp->pos.x+25, temp->pos.y+25);

    if(this->head == this->tail){
        temp->pos.x+=0.f;
        temp->pos.y+=1.f;


        head = tail;
        tail = temp;
    }else{
        switch (direction) {
            case 0:
                // |head| -> |next| -> |tail|
                //this->head->pos = sf::Vector2f (temp->pos.x+25, temp->pos.y+25);
                //sf::Vector2f new_pos = sf::Vector2f (temp->pos.x+25, temp->pos.y+25);
                add_segment(new_pos);
                head = tail;



//                head = tail;
//                head->next = temp;
//                tail = nullptr;






//                head = tail;
//                tail = temp;
//                head->next = temp;
//                tail->next = nullptr;


//
//                tail->pos.x += 0.f;
//               tail->pos.y += 1.f;


                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;

        }
    }

//    switch (direction) {
//        case 0:
//            break;
//        case 1:
//            break;
//        case 2:
//            break;
//        case 3:
//            break;
//
//
//
//
//    }

}

void Snake::intialize_snake() {

}
