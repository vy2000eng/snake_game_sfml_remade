#include <iostream>
#include "Game.h"

int main() {

    Game game;


    while(game.get_window_is_open()){

        game.update();
        game.render();
    }

    return 0;
}
