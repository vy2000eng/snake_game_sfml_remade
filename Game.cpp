//
// Created by voldemort on 8/5/23.
//

#include "Game.h"


// constructor
Game::Game() {
    this->initialize_variables();
    this->initialize_window();
    this->food.set_random_food_position(this->window);


}

//Destructor
Game::~Game() {
    delete this->window;
}

//methods
const bool Game::get_window_is_open() const {
    return this->window->isOpen();
}

void Game::poll_events() {
    /*Description:
     *  - handles events
     *Events:
     *  - closes window
     *  - sets dir variable to l,r,u,p based on key pressed
     * */
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
    /*Description:
     *  - calls poll_events(), which is the function that assigns dir 0,1,2,3
     *    or left, right, up, down based on whether the u,d,l or r key was pressed
     *
     *  - calls update_snake(), which, based on what key was pressed calls the
     *    snake->move(dir) function
     * */
    this->poll_events();
    update_snake();


}

void Game::render() {
    /*Description:
     *  - clears the previous frame
     *  - calls render_snake()
     *  - displays the frame
     * */

    this->window->clear(sf::Color(0,0,0,255));
    this->render_snake();

    this->window->display();

}

void Game::initialize_variables() {
    /*Description:
     *  - initializes member variables
     *  - currently adds some segments tot the snake
     */
    this->window = nullptr;
    this->dir = Direction::down;
    this->direction = 0;
    this->start.pos = sf::Vector2f (55.f, 0.f);
    this->snake.add_segment(start.pos);
    this->start.pos = sf::Vector2f (80.f, 0.f);
    this->snake.add_segment(start.pos);
    this->start.pos = sf::Vector2f (110.f, 0.f);
    this->snake.add_segment(start.pos);
}

void Game::initialize_window() {
    /*Description:
     *  -initializes window
     * */
    this->vm.width = 1000;
    this->vm.height = 800;
    this->window = new sf::RenderWindow(this->vm, "Snake Game");
    this->window->setFramerateLimit(60);

}



void Game::render_snake() {
    /*Description:
     *  - calls snake.draw();
     * */
   this->snake.draw(this->window);
   this->food.draw(this->window);


}

void Game::update_snake() {
    /*Description:
     *  - if the spawn timer is less than 12 then update the spawn timer
     *  - otherwise set spawn timer to 0
     *  - call move with the according direction
     * */

    if(this->snake_spawn_timer >= 12){
        this->snake_spawn_timer = 0;
        switch (dir) {
            case down:
                this->snake.move(down, this->window);
                break;
            case up:
                this->snake.move(up,this->window);
                break;
            case left:
                this->snake.move(left,this->window);
                break;
            case right:
                this->snake.move(right,this->window);
                break;
            default:
                break;
        }
    }else{
        snake_spawn_timer++;
    }
}

const Snake &Game::getSnake() const {
    return snake;
}

sf::RenderWindow *Game::getWindow() const {
    return window;
}


