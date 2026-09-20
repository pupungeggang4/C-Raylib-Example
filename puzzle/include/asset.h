#pragma once
#include "includes.h"

typedef struct {
    Texture2D player;
    Texture2D entity;
} Asset;

extern Asset asset;

void loadAsset(Asset*);
void disposeAsset(Asset*);
