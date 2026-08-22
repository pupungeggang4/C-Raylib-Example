#include "game.h"

void initGame(GameVar* gameVar) {
    srand(time(NULL));

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

    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
}
