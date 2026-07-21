#include "includes.h"
#include "asset.h"
#include "game.h"
#include "gamevar.h"

#ifdef __EMSCRIPTEN__
EM_BOOL key_callback(int eventType, const EmscriptenKeyboardEvent *e, void *userData) {
    if (strcmp(e->code, "Space") == 0) {
        return EM_TRUE;
    }
    return EM_FALSE;
}
#endif

int main (int argc, char** argv) {
    GameVar gameVar = {0};
    initGame(&gameVar);
    #ifdef __EMSCRIPTEN__
    emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_DOCUMENT, NULL, EM_TRUE, key_callback);
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
