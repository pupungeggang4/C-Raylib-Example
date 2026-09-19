#include "includes.h"

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
void loopGame() {
}

void startGame() {
}
#endif

int main(int argc, char** argv) {
    #ifdef __EMSCRIPTEN__
    #else
    #endif
    return 0;
}
