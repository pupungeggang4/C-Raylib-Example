#pragma once
#include "includes.h"

typedef struct GameVar GameVar;
void initGame(GameVar*);
void loop(GameVar*);
void render(GameVar*);
void handleInput(GameVar*);
void changeSceneTo(GameVar*, int);
void endGame(GameVar*);
