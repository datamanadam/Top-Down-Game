#include "Prop.h"
#include "raylib.h"
#include "raymath.h"

// Class to genenerate props.

Prop::Prop(Vector2 pos, Texture2D tex) : worlPos(pos),
                                         texture(tex)
{
}

void Prop::Render(Vector2 knightPos)
{
    Vector2 screenPos{Vector2Subtract(worlPos, knightPos)};
    DrawTextureEx(texture, screenPos, 0.f, scale, WHITE);
}

Rectangle Prop::GetCollisionRec(Vector2 knightPos)
{
    Vector2 screenPos{Vector2Subtract(worlPos, knightPos)};
    return Rectangle{
        screenPos.x,
        screenPos.y,
        texture.width * scale,
        texture.height * scale};
}