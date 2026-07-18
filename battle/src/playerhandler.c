#include "playerhandler.h"

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
