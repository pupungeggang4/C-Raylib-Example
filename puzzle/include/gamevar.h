#pragma once

typedef struct {
    int scene;
    int state;
} GameVar;

enum GameScene {TITLE, FIELD};
enum GameState {IDLE, MENU};
extern GameVar gameVar;
