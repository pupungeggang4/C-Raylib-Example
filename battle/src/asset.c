#include "asset.h"

void loadAsset(Tex* tex) {
    tex->player = LoadTexture("asset/player.png");
    tex->enemy = LoadTexture("asset/slime.png");
}

void disposeAsset(Tex* tex) {
    UnloadTexture(tex->player);
    UnloadTexture(tex->enemy);
    printf("Disposed assets\n");
}
