#include "game.h"

void initGame(GameVar* gameVar) {
    gameVar->width = 800;
    gameVar->height = 600;

    #ifndef __EMSCRIPTEN__
    InitWindow(800, 600, "Simple Battle Game");
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
    InitWindow(gameVar->width, gameVar->height, "Simple Battle Game");
    #endif
    
    float scale = (float)gameVar->width / 800.0f;
    gameVar->camera.zoom = scale;

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(loop, gameVar, 0, 1);
    #else
    while(!WindowShouldClose()) {
        loop(gameVar);
    }
    #endif
}

void loop(void* arg) {
    GameVar* gameVar = (GameVar*)arg;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetScreenToWorld2D(GetMousePosition(), gameVar->camera);
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode2D(gameVar->camera);
    DrawRectangle(0, 0, 800, 600, LIGHTGRAY);
    DrawCircle(400, 300, 100, MAROON);
    DrawText("Scaled with Camera2D!", 60, 60, 20, DARKGRAY);
    EndMode2D();
    EndDrawing();
}
