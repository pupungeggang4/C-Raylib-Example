#pragma once
#include "includes.h"
#include "asset.h"
#include "board.h"

typedef struct GameVar {
    Board board;
    Camera2D camera;
    Tex tex;
    int width; int height;
    int running;
} GameVar;
