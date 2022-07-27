#include "player.h"
class board;

class bot : public player {
    const int maxDepth = 6;
    int minimax(board &b, char c, char op, bool isMin, int depth);

   public:
    void makeMove(board &b, char c, char op);
};