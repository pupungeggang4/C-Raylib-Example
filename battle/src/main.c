#include "includes.h"
#include "asset.h"
#include "game.h"
#include "gamevar.h"

int main (int argc, char** argv) {
    GameVar gameVar = {0};
    initGame(&gameVar);
    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(loop, &gameVar, 0, 1);
    #else
    SetTargetFPS(60);
    while (gameVar.running) {
        loop(&gameVar);
    }
    disposeAsset(&gameVar.tex, &gameVar.aud);
    CloseAudioDevice();
    CloseWindow();
    #endif
    return 0;
}
