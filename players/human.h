#include "player.h"
class board;

class human : public player {
   public:
    void makeMove(board &b, char c, char op);
};