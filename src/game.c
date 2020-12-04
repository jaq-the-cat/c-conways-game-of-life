#include "game.h"

bool cell_at(Board board, int x, int y) {
    return x >= 0 && y >= 0 && x < BOARDW && y < BOARDH && board[x + y * BOARDW];
}

int nb(Board board, int x, int y) {
    bool checked[8] = {
        cell_at(board, x-1, y-1),
        cell_at(board, x,   y-1),
        cell_at(board, x+1, y-1),

        cell_at(board, x-1, y),
        cell_at(board, x+1, y),

        cell_at(board, x-1, y+1),
        cell_at(board, x,   y+1),
        cell_at(board, x+1, y+1),
    };
    static int count = 0;
    count = 0;
    for (int i=0; i<8; i++)
        count += checked[i];
    return count;
}

void GOLinit(Board board) {
    for (int x=0; x<BOARDW; x++)
        for (int y=0; y<BOARDH; y++)
            board[x + y * BOARDW] = rand() % 2;
}

void clone_to(Board a, Board b) {
    for (int x=0; x<BOARDW; x++)
        for (int y=0; y<BOARDH; y++)
            b[x + y * BOARDW] = a[x + y * BOARDW];
}

void GOLtick(Board board) {
    clone_to(board, old);
    for (int x=0; x<BOARDW; x++) {
        for (int y=0; y<BOARDH; y++) {
            if (cell_at(old, x, y))
                printf("🮋🮋");
            else
                printf("  ");

            int n = nb(old, x, y);
            board[x + y * BOARDW] = (cell_at(old, x, y) && n == 2) || n == 3;
        }
        printf("\n");
    }
    printf("\e[1;1H\e[2J");
    usleep(150000);
}
