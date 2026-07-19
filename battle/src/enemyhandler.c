#include "enemyhandler.h"

void initEnemy(GameVar* gameVar, Enemy* enemy) {
    enemy->valid = 0;
    enemy->texture = &gameVar->tex.enemy;
    enemy->rect = (Rect){{200, 200}, {40, 40}};
    enemy->speed = 200.0f;
}

void spawnEnemy(GameVar* gameVar, Vector2 pos) {
    for (int i = 0; i < 50; i++) {
        if (!gameVar->enemy[i].valid) {
            gameVar->enemy[i].valid = 1;
            gameVar->enemy[i].rect.pos = pos;
            break;
        }
    }
}

void moveEnemy(GameVar* gameVar, Enemy* enemy, Player* player) {
    Vector2 diff = Vector2Subtract(player->rect.pos, enemy->rect.pos);
    if (Vector2Length(diff) > 10.0f) {
        Vector2 norm = Vector2Normalize(diff);
        Vector2 velocity = Vector2Scale(norm, enemy->speed);
        enemy->rect.pos.x += velocity.x * gameVar->dt;
        enemy->rect.pos.y += velocity.y * gameVar->dt;
    }
}

void renderEnemy(GameVar* gameVar, Enemy* enemy) {
    DrawTexture(*enemy->texture, enemy->rect.pos.x - enemy->rect.size.x / 2.0f, enemy->rect.pos.y - enemy->rect.size.y / 2.0f, WHITE);
}
