#include "game.h"
#include "board.h"

void initGame(GameVar* gameVar) {
    srand(time(NULL));
    gameVar->width = 800;
    gameVar->height = 600;
    #ifndef __EMSCRIPTEN__
    SetTargetFPS(60);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Lights Out Puzzle");
    SetExitKey(KEY_NULL);
    int currentMonitor = GetCurrentMonitor();
    int monitorWidth = GetMonitorWidth(currentMonitor);
    int monitorHeight = GetMonitorHeight(currentMonitor);

    if (monitorWidth * 3 > monitorHeight * 4) {
        gameVar->height = monitorHeight * 0.8f;
        gameVar->width = gameVar->height * 4 / 3;
    } else {
        gameVar->width = monitorWidth * 0.8f;
        gameVar->height = monitorHeight * 3 / 4;
    }

    SetWindowSize(gameVar->width, gameVar->height);
    SetWindowPosition(
        (monitorWidth - gameVar->width) / 2, (monitorHeight - gameVar->height) / 2
    );
    #else
    InitWindow(gameVar->width, gameVar->height, "Lights Out Puzzle");
    #endif
    gameVar->running = 1;
    gameVar->camera.zoom = GetRenderWidth() / 800.0f;
    loadAsset(&gameVar->tex);
    gameVar->board.on = gameVar->tex.on;
    gameVar->board.off = gameVar->tex.off;

    boardInit(&gameVar->board, 7, 7);
}

void loop(void* p) {
    GameVar* gameVar = (GameVar*) p;
    #ifndef __EMSCRIPTEN__
    if (WindowShouldClose()) {
        gameVar->running = 0;
    }
    #else
    if (!gameVar->running) {
        emscripten_cancel_main_loop();
    }
    #endif
    if (IsKeyPressed(KEY_GRAVE)) {
        gameVar->running = 0;
    }

    update(gameVar);
    render(gameVar);
}

void update(GameVar* gameVar) {
    gameVar->camera.zoom = GetRenderWidth() / 800.0f;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        #ifdef __EMSCRIPTEN__
        Vector2 pos = GetScreenToWorld2D(GetMousePosition(), gameVar->camera);
        #else
        Vector2 pos = GetScreenToWorld2D(Vector2Scale(GetMousePosition(), GetWindowScaleDPI().x), gameVar->camera);
        #endif
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
        boardFlip(&gameVar->board, (int)(pos.y / 80), (int)(pos.x / 80));
    }
}

void render(GameVar* gameVar) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    boardRender(&gameVar->board);
    EndDrawing();
}
