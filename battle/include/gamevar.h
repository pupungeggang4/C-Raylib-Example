#pragma once
#include "includes.h"
#include "asset.h"
#include "player.h"
#include "enemy.h"

typedef struct KeyPressed {
    int left; int right; int up; int down;
} KeyPressed;

typedef struct GameVar {
    Tex tex;
    Aud aud;
    int audReady;
    int width;
    int height;
    KeyPressed keyPressed;
    float dt;

    Camera2D camera;
    Player player;
    Enemy enemy[50];
} GameVar;
