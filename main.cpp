#include <iostream>
#include "game.h"
#include "space.h"

int main()
{
    std::cout << "Tic Tac Toe" << std::endl;

    game new_game;

    space::PIECE winner = new_game.play();

    new_game.display_board();

    if (winner == space::X)
        std::cout << "X Wins!" << std::endl;
    else if (winner == space::O)
        std::cout << "O Wins!" << std::endl;
    else
        std::cout << "It's a Tie!" << std::endl;
    
    return 0;
}
