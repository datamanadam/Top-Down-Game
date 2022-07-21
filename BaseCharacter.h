#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"
//Base Character Class. Player and Enemies will Inherit from this Class. 

class BaseCharacter
{
public:
    BaseCharacter();
    virtual void tick(float deltaTime);
    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle GetCollisionRec();
    virtual Vector2 GetScreenPos() = 0;
    bool getAlive() { return alive; }
    bool setAlive(bool isAlive) { alive = isAlive; }

private:
    bool alive{true};

protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // 1 : facing right, -1 : facing left
    float rightLeft{1.f};
    // animation variables
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    float width{};
    float height{};
    float scale{4.0f};
    Vector2 velocity{};
};

#endif
