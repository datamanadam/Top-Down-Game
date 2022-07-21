#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.5f;
}

void Enemy::tick(float deltaTime)
{
    if (!getAlive())
        return;

    // get toTarget
    velocity = Vector2Subtract(target->GetScreenPos(), GetScreenPos());
    if (Vector2Length(velocity) < radius)
        velocity = {}; // This prevents weird glitching movement by keeping enemy sprite a distance (radius ) away from player.

    BaseCharacter::tick(deltaTime);

    if (CheckCollisionRecs(target->GetCollisionRec(), GetCollisionRec()))
    {
        target->takeDamage(damagePerSec * deltaTime);
    }
}

Vector2 Enemy::GetScreenPos()
{
    return Vector2Subtract(worldPos, target->getWorldPos());
}
