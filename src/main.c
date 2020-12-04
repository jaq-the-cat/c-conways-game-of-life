#include <stdio.h>
#include "game.h"

int main() {
    Board board;
    GOLinit(board);
    while (1) {
        GOLtick(board);
    }
    return 0;
}
