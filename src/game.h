#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#ifndef BOARDW
#define BOARDW 50
#endif

#ifndef BOARDH
#define BOARDH 50
#endif

typedef bool Board[BOARDW*BOARDH];

Board old;
bool cell_at(Board, int, int);
int nb(Board, int, int);
void GOLinit(Board);
void clone_to(Board, Board);
void GOLtick(Board);

#endif
