#include "space.h"

char space::display()
{
    switch (state)
    {
        case X:
            return 'X';
            break;
        case O:
            return 'O';
            break;
        default:
            return ' ';
            break;
    }
}