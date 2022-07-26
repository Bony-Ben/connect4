#include "board.h"
board::board() {
    state = vector<vector<char>>(width, vector<char>(height));
}

void board::insert(char player, int index) {
    for (int i = 0; i < height; i++) {
        if (!state[index][i]) {
            state[index][i] = player;
            return;
        }
    }
    throw "ERROR: Invalid Insert";
}

char board::getWinner() {
    for (int k = 0; k < height; k++) {
        for (int i = 0; i + connectLen - 1 < width; i++) {
            bool same = true;
            for (int j = i; j < i + connectLen - 1; j++) {
                if (state[j][k] != state[j + 1][k]) {
                    same = false;
                    break;
                }
            }
            if (same && state[i][k]) {
                return state[i][k];
            }
        }
    }

    for (int k = 0; k < width; k++) {
        for (int i = 0; i + connectLen - 1 < height; i++) {
            bool same = true;
            for (int j = i; j < i + connectLen - 1; j++) {
                if (state[k][j] != state[k][j + 1]) {
                    same = false;
                    break;
                }
            }
            if (same && state[k][i]) {
                return state[k][i];
            }
        }
    }

    for (int i = 0; i + connectLen - 1 < width; i++) {
        for (int j = 0; j + connectLen - 1 < height; j++) {
            bool same = true;
            for (int k = 0; k < connectLen - 1; k++) {
                if (state[i + k][j + k] != state[i + k + 1][j + k + 1]) {
                    same = false;
                    break;
                }
            }
            if (same && state[i][j]) {
                return state[i][j];
            }
        }
    }

    for (int i = 0; i + connectLen - 1 < width; i++) {
        for (int j = height - 1; j - connectLen + 1 >= 0; j--) {
            bool same = true;
            for (int k = 0; k < connectLen - 1; k++) {
                if (state[i + k][j - k] != state[i + k + 1][j - k - 1]) {
                    same = false;
                    break;
                }
            }
            if (same && state[i][j]) {
                return state[i][j];
            }
        }
    }

    return 0;
}

ostream& operator<<(ostream& os, const board& b) {
    for (int j = b.height - 1; j >= 0; j--) {
        for (int i = 0; i < b.width; i++) {
            if (!b.state[i][j]) {
                cout << '-';
            } else {
                cout << b.state[i][j];
            }
            cout << ' ';
        }
        cout << endl;
    }
    return os;
}