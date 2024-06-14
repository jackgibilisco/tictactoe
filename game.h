#ifndef GAME_H
#define GAME_H

#include "space.h"
#include <string>

class game
{
    public:
        game();
        ~game();

        space::PIECE play();

        void display_board();

    private:
        void take_turn();
        std::string get_move();
        space::PIECE who_won();
        
        space *board[3][3];
        bool is_x_turn;
};

#endif