#include "includes.h"
#include "game.h"
#include "gamevar.h"

int main (int argc, char** argv) {
    GameVar gameVar = {0};
    initGame(&gameVar);
    return 0;
}
