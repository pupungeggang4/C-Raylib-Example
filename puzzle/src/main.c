#include "includes.h"
#include "gamevar.h"
#include "game.h"

#ifdef __EMSCRITPEN__
void loopGame(GameVar* gameVar) {
}

void startGame(GameVar* gameVar) {
}
#endif

int main(int argc, char** argv) {
    #ifdef __ENSCRIPTEN__
    #else
    initGame(&gameVar);
    loop(&gameVar);
    #endif
    return 0;
}
