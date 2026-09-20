#pragma once
#include "includes.h"

struct GameVar;

typedef struct {
    void (*loopFunc)(GameVar*);
    void (*mouseUpLeftFunc)(GameVar*, Vector2);
    void (*keyDownFunc)(GameVar*, int);
} Scene;

void sceneTitleReady(GameVar*);
void sceneTitleUpdate(GameVar*);
void sceneTitleRender(GameVar*);
void sceneTitleMouseUpLeft(GameVar*, Vector2);
void sceneTitleKeyDown(GameVar*, int);

void sceneFieldReady(GameVar*);
void sceneFieldUpdate(GameVar*);
void sceneFieldRender(GameVar*);
void sceneFieldMouseUpLeft(GameVar*, Vector2);
void sceneFieldKeyDown(GameVar*, int);
