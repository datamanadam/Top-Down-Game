#include "BaseCharacter.h"
#include "raymath.h"

// Base Character Class. Player and Enemies will Inherit from this Class.

BaseCharacter::BaseCharacter()
{
}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::GetCollisionRec()
{
    return Rectangle{
        GetScreenPos().x,
        GetScreenPos().y,
        width * scale,
        height * scale};
}

void BaseCharacter::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;
    // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }

    if (Vector2Length(velocity) != 0.0)
    {
        // set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    velocity = {};

    // draw the character
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{GetScreenPos().x, GetScreenPos().y, scale * width, scale * height};

    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}