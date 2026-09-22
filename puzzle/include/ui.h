#pragma once
#include "includes.h"

typedef struct UI {
    float textTitle[2];
    float buttonMenu[4];
    float buttonStart[4];
    float textStart[2];
    float buttonLevel[4];
    float textLevel[2];
    float textLevelCurrent[2];
    float buttonDown[4];
    float buttonUp[4];
    float buttonQuit[4];
    float textQuit[2];
} UI;

extern UI ui;
