#pragma once
#include "includes.h"

typedef struct {
    int running;
    int scene;
    int state;
    Camera2D camera;
} GameVar;

extern GameVar gameVar;
