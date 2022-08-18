#include "bot.h"

#include <climits>
#include <cmath>
#include <iostream>

#include "../board.h"
using namespace std;

int bot::minimax(board &b, char c, char op, bool isMin, int depth) {
    char winner = b.getWinner();
    if (winner) {
        if (isMin) {
            return 10000 - depth;
        } else {
            return -10000 + depth;
        }
    } else if (b.isFull()) {
        return 0;
    } else if (depth > maxDepth) {
        int x = b.evaluate(c);
        int y = b.evaluate(op);
        if (isMin) {
            swap(x, y);
        }
        return x - y;
    } else if (isMin) {
        int minVal = INT_MAX;
        for (int i = 0; i < b.width && minVal > -9000; i++) {
            try {
                b.insert(c, i);
            } catch (const char *e) {
                continue;
            }
            minVal = min(minVal, minimax(b, op, c, false, depth + 1));
            b.pop(i);
        }
        return minVal;
    } else {
        int maxVal = INT_MIN;
        for (int i = 0; i < b.width && maxVal < 9000; i++) {
            try {
                b.insert(c, i);
            } catch (const char *e) {
                continue;
            }
            maxVal = max(maxVal, minimax(b, op, c, true, depth + 1));
            b.pop(i);
        }
        return maxVal;
    }
}

void bot::makeMove(board &b, char c, char op) {
    int count = b.count();
    auto state = b.getState();
    if (count == 0) {
        b.insert(c, 3);
    } else if (count == 1) {
        if (state[1][0]) {
            b.insert(c, 2);
        } else if (state[5][0]) {
            b.insert(c, 4);
        } else {
            b.insert(c, 3);
        }
    } else if (count == 2) {
        if (state[1][0] || state[2][0]) {
            b.insert(c, 5);
        } else if (state[5][0] || state[4][0]) {
            b.insert(c, 1);
        } else {
            b.insert(c, 3);
        }
    } else if (count == 3 && state[3][0] == op && state[3][1] == c) {
        if (state[1][0]) {
            b.insert(c, 2);
        } else if (state[2][0]) {
            b.insert(c, 1);
        } else if (state[5][0]) {
            b.insert(c, 4);
        } else if (state[4][0]) {
            b.insert(c, 5);
        } else {
            b.insert(c, 3);
        }
    } else {
        maxDepth = 7 + count * log(count) / 20;
        board tempB{b};

        int max = INT_MIN;
        vector<int> maxPos;
        for (int i = 0; i < tempB.width; i++) {
            try {
                tempB.insert(c, i);
            } catch (const char *e) {
                continue;
            }
            int val = minimax(tempB, op, c, true, 1);
            tempB.pop(i);
            if (val > max) {
                max = val;
                maxPos.clear();
                maxPos.push_back(i);
            } else if (val == max) {
                maxPos.push_back(i);
            }
            std::cout << val << ' ';
        }
        std::cout << endl;
        b.insert(c, maxPos[rand() % maxPos.size()]);
    }
}