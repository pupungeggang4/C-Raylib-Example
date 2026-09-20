#include "asset.h"

Asset asset = {0};

void loadAsset(Asset* asset) {
    asset->entity = LoadTexture("asset/entity.png");
}

void disposeAsset(Asset* asset) {
    UnloadTexture(asset->entity);
}
