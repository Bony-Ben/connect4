#include "player.h"
class board;

class bot : public player {
   public:
    void makeMove(board &b, char c);
};