#include "includes.h"
#include "game.h"
#include "gamevar.h"

int main(int argc, char** argv) {
    GameVar gameVar = {0};
    initGame(&gameVar);
    while (gameVar.running) {
        loop(&gameVar);
    }
    CloseWindow();
    return 0;
}
