#include "raylib.h"

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#endif

#include <stdio.h>

int width = 800;
int height = 600;
Camera2D camera = {0};

void UpdateDrawFrame(void) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetScreenToWorld2D(GetMousePosition(), camera);
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode2D(camera);
    DrawRectangle(0, 0, 800, 600, LIGHTGRAY);
    DrawCircle(400, 300, 100, MAROON);
    DrawText("Scaled with Camera2D!", 60, 60, 20, DARKGRAY);
    EndMode2D();
    EndDrawing();
}

int main(void) {
    InitWindow(100, 100, "raylib window");
    #ifndef __EMSCRIPTEN__
    int currentMonitor = GetCurrentMonitor();
    int monitorWidth = GetMonitorWidth(currentMonitor);
    int monitorHeight = GetMonitorHeight(currentMonitor);

    if (monitorWidth * 3 > monitorHeight * 4) {
        height = monitorHeight * 0.8f;
        width = height * 4 / 3;
        printf("%d", width);
    } else {
        width = monitorWidth * 0.8f;
        height = width * 3 / 4;
    );
    SetWindowSize(width, height);
    SetWindowPosition(
        (monitorWidth - width) / 2, (monitorHeight - height) / 2
    );
    #else
    SetWindowSize(width, height);
    #endif

 
    float scale = (float)width / 800.0f;
    camera.zoom = scale;

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
    #else
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
    #endif
    CloseWindow();
    return 0;
}
