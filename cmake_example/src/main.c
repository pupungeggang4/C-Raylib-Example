#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <raylib.h>
#include <stdio.h>

void loop() {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 clickPosition = GetMousePosition();
        printf("%.0f, %.0f\n", clickPosition.x, clickPosition.y);
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}

int main(void)
{
    InitWindow(800, 600, "raylib example - basic window");

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(loop, 0, 1);
    #else
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        loop();
    }
    #endif
    CloseWindow();

    return 0;
}
