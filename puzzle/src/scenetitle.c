#include "asset.h"
#include "ui.h"
#include "gamevar.h"
#include "scene.h"
#include "util.h"
#include "game.h"

void sceneTitleReady(GameVar* gameVar) {

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
    renderDrawText(ui.textQuit, "Quit Game", 20, BLACK);
}

void sceneTitleMouseUpLeft(GameVar* gameVar, Vector2 pos) {
    if (pointInsideRectUI(pos, ui.buttonStart)) {
        changeSceneTo(gameVar, FIELD);
    }
}

void sceneTitleKeyDown(GameVar* gameVar, int key) {

}
