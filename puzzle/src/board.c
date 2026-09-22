#include "board.h"

void loadBoard(Board* board, const char* path) {
    FILE *fp;
    fp = fopen(path, "r");
    if (!fp) {
        printf("no file \n");
    } else {
        int row, col;
        fscanf(fp, "%d %d", &row, &col);
        printf("%d %d\n", row, col);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                board->cell[i][j].valid = 0;
                if (i < row && j < col) {
                    int type;
                    fscanf(fp, "%d", &type);
                }
            }
        }
    }
    fclose(fp);
}