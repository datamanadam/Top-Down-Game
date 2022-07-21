#include "raylib.h"

//Class to genenerate props.

class Prop
{
public:
    Prop(Vector2 pos, Texture2D tex);
    void Render(Vector2 knightPos);
    Rectangle GetCollisionRec(Vector2 knightPos);

private:
    Texture2D texture{};
    Vector2 worlPos{};
    float scale{4.f};
};
