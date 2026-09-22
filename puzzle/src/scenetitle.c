#include "asset.h"
#include "ui.h"
#include "gamevar.h"
#include "scene.h"
#include "util.h"
#include "game.h"

void sceneTitleReady(GameVar* gameVar) {
    gameVar->sceneTitleVar.selectedTitle = 0;
    gameVar->sceneTitleVar.selectedLevel = 1;
}

void sceneTitleUpdate(GameVar* gameVar) {

}

void sceneTitleRender(GameVar* gameVar) {
    renderDrawText(ui.textTitle, "Puzzle Game", 20, BLACK);
    renderDrawRect(ui.buttonStart, YELLOW);
    renderDrawText(ui.textStart, "Start Game", 20, BLACK);
    renderDrawRect(ui.buttonLevel, PINK);
    renderDrawText(ui.textLevel, "Select Level", 20, BLACK);
    renderDrawRect(ui.buttonQuit, YELLOW);
    DrawTexture(asset.arrowLeft, ui.buttonDown[0], ui.buttonDown[1], WHITE);
    DrawTexture(asset.arrowRight, ui.buttonUp[0], ui.buttonUp[1], WHITE);
    renderDrawText(ui.textLevelCurrent, TextFormat("%d", gameVar->sceneTitleVar.selectedLevel), 20, BLACK);
    renderDrawText(ui.textQuit, "Quit Game", 20, BLACK);
}

void sceneTitleMouseUpLeft(GameVar* gameVar, Vector2 pos) {
    if (pointInsideRectUI(pos, ui.buttonStart)) {
        changeSceneTo(gameVar, FIELD);
    } else if (pointInsideRectUI(pos, ui.buttonQuit)) {
        gameVar->running = false;
    } else if (pointInsideRectUI(pos, ui.buttonDown)) {
        gameVar->sceneTitleVar.selectedLevel -= 1;
        if (gameVar->sceneTitleVar.selectedLevel < 1) {
            gameVar->sceneTitleVar.selectedLevel = 1; 
        }
    } else if (pointInsideRectUI(pos, ui.buttonUp)) {
        gameVar->sceneTitleVar.selectedLevel += 1;
        if (gameVar->sceneTitleVar.selectedLevel > 10) {
            gameVar->sceneTitleVar.selectedLevel = 10;
        }
    }
}

void sceneTitleKeyDown(GameVar* gameVar, int key) {

}
