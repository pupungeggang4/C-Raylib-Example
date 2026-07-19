#include "asset.h"

void loadAsset(Tex* tex, Aud* aud) {
    tex->player = LoadTexture("asset/player.png");
    tex->enemy = LoadTexture("asset/slime.png");
    aud->music = LoadMusicStream("asset/audio.ogg");
}

void disposeAsset(Tex* tex, Aud* aud) {
    UnloadTexture(tex->player);
    UnloadTexture(tex->enemy);
    UnloadMusicStream(aud->music);
    printf("Disposed assets\n");
}
