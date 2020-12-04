#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#ifndef BOARDW
#define BOARDW 50
#endif

#ifndef BOARDH
#define BOARDH 50
#endif

typedef bool Board[BOARDW*BOARDH];

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
            board[x + y * BOARDW] = false;
}

void GOLtick(Board board) {
    for (int x=0; x<BOARDW; x++)
        for (int y=0; y<BOARDH; y++)
            board[x + y * BOARDW] = false;
}

#endif
