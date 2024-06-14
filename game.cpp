#include <iostream>

#include "game.h"

using namespace std;

game::game()
{
    is_x_turn = true;

    //create board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = new space();
        }
    }
}

game::~game()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            delete board[i][j];
        }
    }
}

space::PIECE game::play()
{
    int turn = 0;
    
    while(who_won() == space::EMPTY && turn < 9)
    {
        take_turn();
        turn++;
    }

    return who_won();
}

void game::take_turn()
{
    space::PIECE piece_to_place;

    if (is_x_turn)
        piece_to_place = space::X;
    else
        piece_to_place = space::O;

    display_board();
    
    string move = get_move();

    board[move[0] - '1'][move[1] - '1']->set(piece_to_place);

    is_x_turn = !is_x_turn;
}

void game::display_board()
{
    cout << "\n\n\n";
    cout << " ";
    cout << "  1     2     3  " << endl;
    cout << " ";
    cout << "     |     |     " << endl;
    cout << "1";
    cout << "  " << board[0][0]->display();
    cout << "  |  " << board[1][0]->display();
    cout << "  |  " << board[2][0]->display();
    cout << "  " << endl;
    cout << " ";
    cout << "_____|_____|_____" << endl;
    cout << " ";
    cout << "     |     |     " << endl;
    cout << "2";
    cout << "  " << board[0][1]->display();
    cout << "  |  " << board[1][1]->display();
    cout << "  |  " << board[2][1]->display();
    cout << "  " << endl;
    cout << " ";
    cout << "_____|_____|_____" << endl;
    cout << " ";
    cout << "     |     |     " << endl;
    cout << "3";
    cout << "  " << board[0][2]->display();
    cout << "  |  " << board[1][2]->display();
    cout << "  |  " << board[2][2]->display();
    cout << "  " << endl;
    cout << " ";
    cout << "     |     |     " << endl;
}

string game::get_move()
{
    if (is_x_turn)
        cout << "X move" << endl;
    else
        cout << "O move" << endl;
    
    //prompt user
    cout << "Enter Your Move (row, column)" << endl;

    //get move from cin
    string move;
    getline(cin, move);

    if (
        move.length() == 4     //correct length
        && move[0] - '0' > 0   //in bounds
        && move[0] - '0' < 4   //in bounds
        && move[3] - '0' > 0   //in bounds
        && move[3] - '0' < 4   //in bounds
        && board[move[0] - '1'][move[3] - '1']->get() == space::EMPTY
    ) { return {move[0], move[3]}; }
    else
    {
        cout << "Illegal Move" << endl;
        return get_move();
    }
}

space::PIECE game::who_won()
{
    //vertical
    for (int i = 0; i < 3; i++)
    {
        int x = 0;
        int o = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]->get() == space::X)
                x++;
            else if (board[i][j]->get() == space::O)
                o++;
        }

        if (x == 3)
            return space::X;
        if (o == 3)
            return space::O;
    }

    //horizontal
    for (int i = 0; i < 3; i++)
    {
        int x = 0;
        int o = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[j][i]->get() == space::X)
                x++;
            else if (board[j][i]->get() == space::O)
                o++;
        }

        if (x == 3)
            return space::X;
        if (o == 3)
            return space::O;
    }

    //diagonal from top left
    int x = 0;
    int o = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][i]->get() == space::X)
            x++;
        else if (board[i][i]->get() == space::O)
            o++;
    }
    if (x == 3)
        return space::X;
    else if (o == 3)
        return space::O;

    //diagonal from top right
    x = 0;
    o = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][2 - i]->get() == space::X)
            x++;
        else if (board[i][2 - i]->get() == space::O)
            o++;
    }
    if (x == 3)
        return space::X;
    else if (o == 3)
        return space::O;

    //no one is winning
    return space::EMPTY;
}