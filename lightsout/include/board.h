#pragma once
#include "includes.h"

typedef struct Board {
    int cell[16][16];
    int row;
    int col;
} Board;

void boardFlip(Board*, int, int);
int boardIsInside(Board*, int, int);
void boardRender(Board*);
