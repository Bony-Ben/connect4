class board;

#ifndef PLAYER_H
#define PLAYER_H

class player {
   public:
    virtual void makeMove(board &b, char c, char op) = 0;
};

#endif