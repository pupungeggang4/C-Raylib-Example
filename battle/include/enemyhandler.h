#pragma once
#include "includes.h"
#include "gamevar.h"
#include "player.h"
#include "enemy.h"

void initEnemy(GameVar*, Enemy*);
void spawnEnemy(GameVar*, Vector2);
void renderEnemy(GameVar*, Enemy*);
void moveEnemy(GameVar*, Enemy*, Player*);
