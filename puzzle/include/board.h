#pragma once
#include "includes.h"
#include "entity.h"

typedef struct Board {
    int row;
    int col;
    Entity entity[100];
    Entity cell[10][10];
} Board;

void loadBoard(Board*, const char*);