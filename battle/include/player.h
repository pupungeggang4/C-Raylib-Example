#pragma once
#include "includes.h"
#include "rect.h"

typedef struct Player {
    Rect rect;
    float speed;
    Texture2D* texture;

    float attack;
} Player;
