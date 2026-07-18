#pragma once
#include "includes.h"
#include "rect.h"

typedef struct Player {
    Rect rect;
    float speed;
    Image* texture;
} Player;
