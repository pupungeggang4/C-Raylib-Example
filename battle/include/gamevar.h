#pragma once
#include "includes.h"
#include "player.h"
#include "enemy.h"

typedef struct GameVar {
    int width;
    int height;
    Camera2D camera;
    Player player;
    Enemy enemy[50];
} GameVar;
