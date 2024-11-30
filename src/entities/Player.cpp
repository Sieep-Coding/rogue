#include "Player.h"
#include <cmath>
#include "raymath.h"

Player::Player(float x, float y)
    : Entity(x, y, 30, 30), isSwinging(false), swordAngle(0.0f), swingSpeed(300.0f), swingProgress(0.0f) {}

void Player::Update()
{
    // movement
    if (IsKeyDown(KEY_W))
        position.y -= 5.0f;
    if (IsKeyDown(KEY_S))
        position.y += 5.0f;
    if (IsKeyDown(KEY_A))
        position.x -= 5.0f;
    if (IsKeyDown(KEY_D))
        position.x += 5.0f;

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !isSwinging)
    {
        // TODO: add sword swing
        isSwinging = true;
        swingProgress = 0.0f;
        swordAngle = atan2f(GetMouseY() - (position.y + height / 2), GetMouseX() - (position.x + width / 2)) * RAD2DEG;
    }

    if (isSwinging)
    {
        swingProgress += GetFrameTime() * swingSpeed / 360.0f;
        if (swingProgress >= 1.0f)
        {
            isSwinging = false;
        }
    }
}

void Player::Draw()
{
    DrawRectangleRec(GetCollisionBox(), BLUE);

    if (isSwinging)
    {
        float currentAngle = swordAngle - 90.0f * swingProgress;
        float swordLength = 40.0f;

        Vector2 swordStart = 
        {
            position.x + width / 2,
            position.y + height / 2
        };

        Vector2 swordEnd = 
        {
            swordStart.x + cosf(DEG2RAD * currentAngle) * swordLength,
            swordStart.y + sinf(DEG2RAD * currentAngle) * swordLength
        };

        DrawLineEx(swordStart, swordEnd, 4.0f, RED);
    }
}

bool Player::IsSwinging() const
{
    return isSwinging;
}

float Player::GetSwordAngle() const
{
    return swordAngle;
}