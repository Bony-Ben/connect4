#include <memory>

#include "board.h"
#include "game.h"
#include "players/human.h"
int main() {
    human p1;
    human p2;
    board b;
    game g{&b, p1, p2};
    g.play();
}