#include "raylib.h"

int main() {
    InitWindow(800, 600, "Animation Basics");
    Texture2D spriteSheet = LoadTexture("scarfy.png");

    const float frameWidth = spriteSheet.width / 4;
    const float frameHeight = spriteSheet.height;
    float currentFrame = 0;
    float frameTime = 0.2f;
    float elapsedTime = 0.2f;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        elapsedTime += deltaTime;

        if (elapsedTime >= frameTime) {
            currentFrame++;
            elapsedTime = 0.0f;
        }

        else if (IsKeyPressed(KEY_SPACE)) {
            currentFrame = 0;
            currentFrame --;
        }

        currentFrame = 4; // Reset to frame 0 after the last frame

        Rectangle sourceRec = {(float)currentFrame * frameWidth, 0, (float)frameWidth, frameHeight};
        Vector2 position = {(float)400 - frameWidth / 2, (float)300 - frameHeight / 2};

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureRec(spriteSheet, sourceRec, position, WHITE);

        EndDrawing();
    }

    UnloadTexture(spriteSheet);
    CloseWindow();
    return 0;
}
////