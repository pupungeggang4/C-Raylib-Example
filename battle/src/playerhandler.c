#include "playerhandler.h"

void handlePlayer(GameVar* gameVar, Player* player) {
    if (IsKeyPressed(KEY_SPACE)) {
        for (int i = 0; i < 50; i++) {
            if (gameVar->enemy[i].valid) {
                Enemy* enemy = &gameVar->enemy[i];
                Vector2 diff = Vector2Subtract(player->rect.pos, enemy->rect.pos);
                if (Vector2Length(diff) < 200) {
                    enemy->hp -= player->attack;
                }
            }
        }
    }
}

void movePlayer(GameVar* gameVar, Player* player) {
    float speed = player->speed;
    if ((gameVar->keyPressed.left || gameVar->keyPressed.right) && (gameVar->keyPressed.up || gameVar->keyPressed.down)) {
        speed = player->speed * 0.7f;
    }
    if (gameVar->keyPressed.left) {
        player->rect.pos.x -= speed * gameVar->dt;
    }
    if (gameVar->keyPressed.right) {
        player->rect.pos.x += speed * gameVar->dt;
    }
    if (gameVar->keyPressed.up) {
        player->rect.pos.y -= speed * gameVar->dt;
    }
    if (gameVar->keyPressed.down) {
        player->rect.pos.y += speed * gameVar->dt;
    }
}

void renderPlayer(GameVar* gameVar, Player* player) {
    DrawTexture(*player->texture, player->rect.pos.x - player->rect.size.x / 2.0f, player->rect.pos.y - player->rect.size.y / 2.0f, WHITE);
}
