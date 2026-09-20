#include "asset.h"
#include "ui.h"
#include "gamevar.h"
#include "scene.h"
#include "game.h"

void initGame(GameVar* gameVar) {
    #ifdef __EMSCRIPTEN__
    InitWindow(800, 600, "Puzzle Game");
    #else
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Card Roguelike");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    int width, height;
    int currentMonitor = GetCurrentMonitor();
    int monitorWidth = GetMonitorWidth(currentMonitor);
    int monitorHeight = GetMonitorHeight(currentMonitor);
    if (monitorWidth * 3 > monitorHeight * 4) {
        height = monitorHeight * 0.8f;
        width = height * 4 / 3;
    } else {
        width = monitorWidth * 0.8f;
        height = monitorHeight * 3 / 4;
    }

    SetWindowSize(width, height);
    SetWindowPosition(
        (monitorWidth - width) / 2, (monitorHeight - height) / 2
    );
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    #endif
    
    loadAsset(&asset);
    gameVar->running = 1;
    gameVar->scene = TITLE;
    gameVar->state = NORMAL;
    Camera2D baseCamera = {0};
    gameVar->camera = baseCamera;
    gameVar->camera.zoom = GetRenderWidth() / 800.0f;
}

void loop(GameVar* gameVar) {
    handleInput(gameVar);

    if (gameVar->scene == NORMAL) {
        sceneTitleUpdate(gameVar);
    } else if (gameVar->scene == FIELD) {
        sceneFieldUpdate(gameVar);
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText(TextFormat("FPS: %i", GetFPS()), 20, 560, 20, DARKGRAY);
    render(gameVar);
    EndDrawing();

    #ifdef __EMSCRIPTEN__
    if (gameVar->running == 0) {
        emscripten_cancel_main_loop();
    }
    #else
    if (WindowShouldClose()) {
        gameVar->running = false;
    }
    #endif
}

void render(GameVar* gameVar) {
    if (gameVar->scene == TITLE) {
        sceneTitleRender(gameVar);
    } else if (gameVar->scene == FIELD) {
        sceneFieldRender(gameVar);
    } 
}

void handleInput(GameVar* gameVar) {
    gameVar->camera.zoom = GetRenderWidth() / 800.0f;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        #ifdef __EMSCRIPTEN__
        Vector2 pos = GetMousePosition();
        #else
        Vector2 pos = GetScreenToWorld2D(Vector2Scale(GetMousePosition(), GetWindowScaleDPI().x), gameVar->camera);
        #endif
        printf("%f, %f\n", pos.x, pos.y);
        if (gameVar->scene == TITLE) {
            sceneTitleMouseUpLeft(gameVar, pos);
        } else if (gameVar->scene == FIELD) {
            sceneFieldMouseUpLeft(gameVar, pos);
        }
    }
}

void changeSceneTo(GameVar* gameVar, int scene) {
    gameVar->scene = scene;
    if (gameVar->scene == TITLE) {
        sceneTitleReady(gameVar);
    } else if (gameVar->scene == FIELD) {
        sceneFieldReady(gameVar);
    }
}

void endGame(GameVar* gameVar) {
    disposeAsset(&asset);
}
