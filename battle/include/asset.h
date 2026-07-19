#pragma once
#include "includes.h"

typedef struct Tex {
    Texture2D player;
    Texture2D enemy;
} Tex;

typedef struct Aud {
    Music music;
} Aud;

void loadAsset(Tex*, Aud*);
void disposeAsset(Tex*, Aud*);
