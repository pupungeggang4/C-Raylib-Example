#include "board.h"

void boardFlip(Board* board, int row, int col) {
    int neighbor[5][2] = {{-1, 0}, {0, -1}, {0, 0}, {0, 1}, {1, 0}};
    for (int i = 0; i < 5; i++) {
        int cRow = row + neighbor[i][0];
        int cCol = col + neighbor[i][1];
        if (boardIsInside(board, cRow, cCol)) {
            board->cell[cRow][cCol] = !board->cell[cRow][cCell];
        }
    }
}

void boardIsInside(Board* board, int row, int col) {
    return row >= 0 && row < board->row && col >= 0 && col < board->col;
}

void boardRender(Board* board) {
    
}
