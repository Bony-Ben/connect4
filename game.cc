#include "game.h"

game::game(board *b, player &p1, player &p2) : b{b}, p1{p1}, p2{p2} {}

void game::play() {
    char winner = 0;
    bool turn = false;
    while (!winner && !b->isFull()) {
        cout << *b;
        if (turn) {
            p2.makeMove(*b, p2Char, p1Char);
        } else {
            p1.makeMove(*b, p1Char, p2Char);
        }
        turn = !turn;
        winner = b->getWinner();
    }
    if (winner) {
        cout << *b;
        cout << winner << " Wins!" << endl;
    } else {
        cout << "Tie!" << endl;
    }
}