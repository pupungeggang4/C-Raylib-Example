#include "board.h"

void boardInit(Board* board, int row, int col) {
    board->row = row;
    board->col = col;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            board->cell[i][j] = 0;
        }
    }

    for (int i = 0; i < 8; i++) {
        int rf = rand() % row;
        int cf = rand() % col;
        boardFlip(board, rf, cf);
    }
}

void boardFlip(Board* board, int row, int col) {
    int neighbor[5][2] = {{-1, 0}, {0, -1}, {0, 0}, {0, 1}, {1, 0}};
    for (int i = 0; i < 5; i++) {
        int cRow = row + neighbor[i][0];
        int cCol = col + neighbor[i][1];
        if (boardIsInside(board, cRow, cCol)) {
            board->cell[cRow][cCol] = !board->cell[cRow][cCol];
        }
    }
}

int boardIsInside(Board* board, int row, int col) {
    return row >= 0 && row < board->row && col >= 0 && col < board->col;
}

void boardRender(Board* board) {
    for (int i = 0; i < board->row; i++) {
        for (int j = 0; j < board->col; j++) {
            if (board->cell[i][j] == 0) {
                DrawTexture(board->off, 80 * j, 80 * i, WHITE);
            } else {
                DrawTexture(board->on, 80 * j, 80 * i, WHITE);
            }
        }
    }
}
