#include "raylib.h"

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#endif

void UpdateDrawFrame(void) {
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, raylib on Web!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}

int main(void) {
    InitWindow(800, 600, "raylib [core] example - window web");

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
