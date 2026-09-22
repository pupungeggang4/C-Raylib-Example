#pragma once
#include "includes.h"

typedef struct {
    int selectedTitle;
    int selectedLevel;
} SceneTitleVar;

typedef struct {
    int selectedMenu;
} SceneFieldVar;

typedef struct {
    int running;
    int scene;
    int state;
    Camera2D camera;
    SceneTitleVar sceneTitleVar;
    SceneFieldVar sceneFieldVar;
} GameVar;

extern GameVar gameVar;
