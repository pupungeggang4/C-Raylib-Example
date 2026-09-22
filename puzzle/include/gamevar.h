#pragma once
#include "includes.h"
#include "board.h"

typedef struct SceneTitleVar {
    int selectedTitle;
    int selectedLevel;
} SceneTitleVar;

typedef struct SceneFieldVar {
    int selectedMenu;
} SceneFieldVar;

typedef struct GameVar {
    int running;
    int scene;
    int state;
    Camera2D camera;
    SceneTitleVar sceneTitleVar;
    SceneFieldVar sceneFieldVar;
    Board board;
} GameVar;

extern GameVar gameVar;
