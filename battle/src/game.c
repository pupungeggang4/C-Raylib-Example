#include "game.h"
#include "asset.h"
#include "playerhandler.h"

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

    loadAsset(&gameVar->tex);

    gameVar->player.rect = (Rect){{400, 300}, {80, 80}};
    gameVar->player.speed = 400.0f;

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(loop, gameVar, 0, 1);
    #else
    SetTargetFPS(60);
    while(!WindowShouldClose()) {
        loop(gameVar);
    }
    #endif
}

void loop(void* arg) {
    GameVar* gameVar = (GameVar*)arg;
    gameVar->dt = GetFrameTime();
    update(gameVar);
    render(gameVar);
}

void update(GameVar* gameVar) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetScreenToWorld2D(GetMousePosition(), gameVar->camera);
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
    }

    if (IsKeyPressed(KEY_A)) {
        gameVar->keyPressed.left = 1;
    }
    if (IsKeyPressed(KEY_D)) {
        gameVar->keyPressed.right = 1;
    }
    if (IsKeyPressed(KEY_W)) {
        gameVar->keyPressed.up = 1;
    }
    if (IsKeyPressed(KEY_S)) {
        gameVar->keyPressed.down = 1;
    }

    if (IsKeyReleased(KEY_A)) {
        gameVar->keyPressed.left = 0;
    }
    if (IsKeyReleased(KEY_D)) {
        gameVar->keyPressed.right = 0;
    }
    if (IsKeyReleased(KEY_W)) {
        gameVar->keyPressed.up = 0;
    }
    if (IsKeyReleased(KEY_S)) {
        gameVar->keyPressed.down = 0;
    }

    movePlayer(gameVar, &gameVar->player);
}

void render(GameVar* gameVar) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode2D(gameVar->camera);
    DrawTexture(gameVar->tex.player, gameVar->player.rect.pos.x - gameVar->player.rect.size.x / 2.0f, gameVar->player.rect.pos.y - gameVar->player.rect.size.y / 2.0f, WHITE);
    EndMode2D();
    EndDrawing();
}
