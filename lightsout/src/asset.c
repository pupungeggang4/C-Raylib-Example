#include "includes.h"
#include "asset.h"

void loadAsset(Tex* tex) {
    tex->on = LoadTexture("asset/on.png");
    tex->off = LoadTexture("asset/off.png");
}

void disposeAsset(Tex* tex) {
    UnloadTexture(tex->on);
    UnloadTexture(tex->off);
}
