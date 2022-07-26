#include "game.h"

game::game(board *b, player &p1, player &p2) : b{b}, p1{p1}, p2{p2} {}

void game::play() {
    char winner = 0;
    bool turn = false;
    while (!winner) {
        cout << *b;
        if (turn) {
            p2.makeMove(*b, p2Char);
        } else {
            p1.makeMove(*b, p1Char);
        }
        turn = !turn;
        winner = b->getWinner();
    }
    cout << *b;
    cout << winner << " Wins!" << endl;
}