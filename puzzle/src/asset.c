#include "asset.h"

Asset asset = {0};

void loadAsset(Asset* asset) {
    asset->player = LoadTexture("asset/player.png");
    asset->entity = LoadTexture("asset/entity.png");
    asset->arrowLeft = LoadTexture("asset/arrow_left.png");
    asset->arrowRight = LoadTexture("asset/arrow_right.png");
}

void disposeAsset(Asset* asset) {
    UnloadTexture(asset->player);
    UnloadTexture(asset->entity);
    UnloadTexture(asset->arrowLeft);
    UnloadTexture(asset->arrowRight);
}
