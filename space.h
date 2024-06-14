#ifndef SPACE_H
#define SPACE_H

class space
{
    public:
        enum PIECE{EMPTY, X, O};

        space() { state = EMPTY; }

        /**
         * @brief sets the state to x or o
         * 
         * @param piece
         */
        void set(PIECE piece) { state = piece; }

        /**
         * @brief returns state of spot
         * 
         * @return PIECE 
         */
        PIECE get() { return state; }

        char display();

    private:
        PIECE state = EMPTY;
};

#endif