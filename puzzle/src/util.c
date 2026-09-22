#include "util.h"
#include "entity.h"
#include "board.h"

int pointInsideRectUI(Vector2 pos, float rect[4]) {
    return pos.x > rect[0] && pos.x < rect[0] + rect[2] && pos.y > rect[1] && pos.y < rect[1] + rect[3];
}

void renderDrawRect(float rect[4], Color color) {
    DrawRectangle(rect[0], rect[1], rect[2], rect[3], color);
}

void renderDrawText(float rect[2], const char* text, float size, Color color) {
    DrawText(text, rect[0], rect[1], size, color);
}