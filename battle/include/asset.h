#pragma once
#include "includes.h"

typedef struct Tex {
    Texture2D player;
    Texture2D enemy;
} Tex;

void loadAsset(Tex*);
void disposeAsset(Tex*);
