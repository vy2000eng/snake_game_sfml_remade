//
// Created by voldemort on 8/5/23.
//

#include "Game.h"


// constructor
Game::Game() {
    this->initialize_variables();
    this->initialize_window();
    //this->initialize_snake();

}

Game::~Game() {
    delete this->window;

}

const bool Game::get_window_is_open() const {
    return this->window->isOpen();
}

void Game::poll_events() {
    while(this->window->pollEvent(this->event)){
        switch (this->event.type) {
            case::sf::Event::Closed:
                this->window->close();
                break;
            case::sf::Event::KeyPressed:
                switch (this->event.key.code) {
                    case::sf::Keyboard::Up:
                        this->dir = Direction::up;
                        break;
                    case::sf::Keyboard:: Down:
                        this->dir = Direction::down;
                        break;
                    case::sf::Keyboard::Left:
                        this->dir = Direction::left;

                        break;
                    case::sf::Keyboard::Right:
                        this->dir = Direction::right;
                        break;
                    case::sf::Keyboard::Escape:
                        this->window->close();
                }

                break;



        }

    }

}

void Game::update() {
    this->poll_events();
    update_snake();


}

void Game::render() {
    this->window->clear(sf::Color(0,0,0,255));
    this->render_snake();

    this->window->display();

}

void Game::initialize_variables() {
    this->window = nullptr;
    this->dir = Direction::down;
    this->direction = 0;
    this->start.pos = sf::Vector2f (55.f, 0.f);
    this->snake.add_segment(start.pos);
    this->start.pos = sf::Vector2f (80.f, 0.f);
    this->snake.add_segment(start.pos);
    this->start.pos = sf::Vector2f (110.f, 0.f);
    this->snake.add_segment(start.pos);

    // this->snake.add_segment();





}

void Game::initialize_window() {
    this->vm.width = 1000;
    this->vm.height = 800;
    this->window = new sf::RenderWindow(this->vm, "Snake Game");
    this->window->setFramerateLimit(60);

}



void Game::render_snake() {
   // this->window->draw(this->snake);
   this->snake.draw(this->window);

}

void Game::update_snake() {

    if(this->snake_spawn_timer >= 12){
        this->snake_spawn_timer = 0;
        switch (dir) {
            case down:

                this->snake.move(down);
                break;
            case up:
                this->snake.move(up);
                break;
            case left:
                this->snake.move(left);
                break;
            case right:
                this->snake.move(right);
                break;

            default:
                break;
        }
    }else{
        snake_spawn_timer++;
    }



//    if(this->snake_spawn_timer >=12){
//        snake_spawn_timer = 0;
//        this->snake.move(0);
//    }else{
//        snake_spawn_timer++;
//    }

//    switch(dir){
//        case down:
//            this->snake.move(0.f, this->move_speed);
//            break;
//        case up:
//            this->snake.move(0.f, -this->move_speed);
//            break;
//        case left:
//            this->snake.move(-this->move_speed, 0.f);
//            break;
//        case right:
//            this->snake.move(this->move_speed, 0.f);
//            break;
//
//
//        default:
//            break;
//    }


}


