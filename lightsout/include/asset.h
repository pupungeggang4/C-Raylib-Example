#pragma once
#include "includes.h"

typedef struct Tex {
    Texture2D on;
    Texture2D off;
} Tex;

void loadAsset(Tex*);
void disposeAsset(Tex*);
