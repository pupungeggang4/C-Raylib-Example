#pragma once

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <raylib.h>
#include <raymath.h>

enum Types {PLAYER, WALL, ROCK, GOAL};
enum GameScene {TITLE, FIELD};
enum GameState {NORMAL, MENU};
