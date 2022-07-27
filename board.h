#include <iostream>
#include <vector>
using namespace std;

#ifndef BOARD_H
#define BOARD_H

class board {
    vector<vector<char>> state;

   public:
    const int width = 7;
    const int height = 6;
    const int connectLen = 4;
    board();
    void insert(char player, int index);
    void pop(int index);
    char getWinner();
    bool isFull();
    int countTriples(char player);

    friend ostream& operator<<(ostream& os, const board& b);
};

#endif