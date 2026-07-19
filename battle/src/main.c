#include "includes.h"
#include "asset.h"
#include "game.h"
#include "gamevar.h"

int main (int argc, char** argv) {
    GameVar gameVar = {0};
    initGame(&gameVar);
    #ifndef __EMSCRIPTEN__
    disposeAsset(&gameVar.tex);
    #endif
    return 0;
}
