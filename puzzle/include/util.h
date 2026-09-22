#pragma once
#include "includes.h"

typedef struct Board Board;
int pointInsideRectUI(Vector2, float[]);

void renderDrawRect(float[], Color);
void renderDrawText(float[], const char*, float, Color);