#pragma once
#include "includes.h"
#include "rect.h"

typedef struct Enemy {
    int valid;
    Rect rect;
    float speed;
    Texture* texture;

    float hp;
    float hpMax;
} Enemy;
