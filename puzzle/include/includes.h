#pragma once

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <raylib.h>
#include <raymath.h>

enum Types {EMPTY, WALL, ROCK, GOAL, PLAYER};
enum GameScene {TITLE, FIELD};
enum GameState {NORMAL, MENU};

extern dataEntity[5][2] = {
    {0, 0},
    {0, 1},
    {1, 1},
    {0, 0},
    {1, 1}
};
