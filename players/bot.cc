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
        int x = b.countTriples(c);
        int y = b.countTriples(op);
        if (isMin) {
            swap(x, y);
        }
        return 100 * (x - y);
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
    if (b.empty()) {
        b.insert(c, 3);
        return;
    }
    int count = b.count();
    maxDepth = 7 + count * sqrt(count) / 20;
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
        cout << val << ' ';
    }
    cout << endl;
    b.insert(c, maxPos[rand() % maxPos.size()]);
}