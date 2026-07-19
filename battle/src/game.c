#include "game.h"
#include "asset.h"
#include "playerhandler.h"
#include "enemyhandler.h"

void initGame(GameVar* gameVar) {
    gameVar->width = 800;
    gameVar->height = 600;

    #ifndef __EMSCRIPTEN__
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
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

    gameVar->camera.zoom = GetRenderWidth() / 800.0f;

    loadAsset(&gameVar->tex);

    gameVar->player.rect = (Rect){{400, 300}, {80, 80}};
    gameVar->player.speed = 400.0f;
    gameVar->player.texture = &gameVar->tex.player;

    for (int i = 0; i < 50; i++) {
        initEnemy(gameVar, &gameVar->enemy[i]);
    }
    spawnEnemy(gameVar, (Vector2){200, 200});
    spawnEnemy(gameVar, (Vector2){600, 200});
    spawnEnemy(gameVar, (Vector2){200, 400});
    spawnEnemy(gameVar, (Vector2){600, 400});

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(loop, gameVar, 0, 1);
    #else
    SetTargetFPS(60);
    gameVar->running = 1;
    while(gameVar->running) {
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
    gameVar->camera.zoom = GetRenderWidth() / 800.0f;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetScreenToWorld2D(Vector2Scale(GetMousePosition(), GetWindowScaleDPI().x), gameVar->camera);
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
    if (IsKeyPressed(KEY_GRAVE)) {
        #ifdef __EMSCRIPTEN__
        emscripten_cancel_main_loop();
        disposeAsset(&gameVar->tex);
        #else
        gameVar->running = 0;
        #endif
    }

    movePlayer(gameVar, &gameVar->player);
    for (int i = 0; i < 50; i++) {
        if (gameVar->enemy[i].valid) {
            moveEnemy(gameVar, &gameVar->enemy[i], &gameVar->player);
        }
    }
}

void render(GameVar* gameVar) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode2D(gameVar->camera);
    for (int i = 0; i < 50; i++) {
        if (gameVar->enemy[i].valid) {
            renderEnemy(gameVar, &gameVar->enemy[i]);
        }
    }
    renderPlayer(gameVar, &gameVar->player);
    EndMode2D();
    EndDrawing();
}
