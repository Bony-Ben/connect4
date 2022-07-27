#include <memory>

#include "board.h"
#include "game.h"
#include "players/bot.h"
#include "players/human.h"
int main() {
    srand (time(NULL));
    human p1;
    bot p2;
    board b;
    int x;
    cin >> x;
    if (x) {
        game g{&b, p1, p2};
        g.play();
    } else {
        game g{&b, p2, p1};
        g.play();
    }
}