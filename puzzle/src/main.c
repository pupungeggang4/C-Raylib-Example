#include "includes.h"
#include "gamevar.h"
#include "game.h"

#ifdef __EMSCRIPTEN__
void loopGame() {
    loop(&gameVar);
}

void startGame() {
    initGame(&gameVar);
    emscripten_set_main_loop(loopGame, 0, 0);
}
#endif

int main(int argc, char** argv) {
    #ifdef __EMSCRIPTEN__
    startGame();
    #else
    initGame(&gameVar);
    while (gameVar.running == 1) {
        loop(&gameVar);
    }
    endGame(&gameVar);
    CloseWindow();
    #endif
    return 0;
}
