#include "human.h"

#include <iostream>

#include "../board.h"
using namespace std;

void human::makeMove(board &b, char c, char op) {
    int col;
    cin >> col;
    while (true) {
        try {
            b.insert(c, col);
            break;
        } catch (const char *e) {
        }
    }
}