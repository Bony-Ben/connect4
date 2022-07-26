#include "board.h"
#include "players/player.h"

class game {
    board *b;
    player &p1;
    player &p2;

   public:
    const char p1Char = 'A';
    const char p2Char = 'B';
    game(board *b, player &p1, player &p2);
    void play();
};