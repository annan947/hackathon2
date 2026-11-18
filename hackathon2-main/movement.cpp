
#include "raylib.h"
using namespace std;

int main() {

    // Create game window
    InitWindow(800, 600, "Movement Game");
    SetTargetFPS(60);

    // Player position and size
    float playerX = 100;
    float playerY = 100;
    int playerWidth = 50;
    int playerHeight = 50;

    // Movement speed in pixels per second
    float playerSpeed = 300.0f;

    // Main game loop
    while (!WindowShouldClose()) {

        // Time elapsed since the previous frame
        float deltaTime = GetFrameTime();

        // WASD movement
        if (IsKeyDown(KEY_D)) {
            playerX += playerSpeed * deltaTime;
        }

        if (IsKeyDown(KEY_A)) {
            playerX -= playerSpeed * deltaTime;
        }

        if (IsKeyDown(KEY_W)) {
            playerY -= playerSpeed * deltaTime;
        }

        if (IsKeyDown(KEY_S)) {
            playerY += playerSpeed * deltaTime;
        }

        // Screen boundaries

        // Right boundary
        if (playerX > 800 - playerWidth) {
            playerX = 800 - playerWidth;
        }

        // Left boundary
        if (playerX < 0) {
            playerX = 0;
        }

        // Top boundary
        if (playerY < 0) {
            playerY = 0;
        }

        // Bottom boundary
        if (playerY > 600 - playerHeight) {
            playerY = 600 - playerHeight;
        }

        // Draw everything
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(
            (int)playerX,
            (int)playerY,
            playerWidth,
            playerHeight,
            BLUE
        );

        EndDrawing();
    }

    // Close game
    CloseWindow();

    return 0;
}
