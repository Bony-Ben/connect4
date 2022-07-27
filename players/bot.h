#include "player.h"
class board;

class bot : public player {
    int maxDepth;
    int minimax(board &b, char c, char op, bool isMin, int depth);

   public:
    void makeMove(board &b, char c, char op);
};