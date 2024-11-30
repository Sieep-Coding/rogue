#include "Player.h"
#include <cmath>

Player::Player(float x, float y)
    : Entity(x, y, 40.0f, 40.0f), speed(4.0f), isSwinging(false),
      swordAngle(0.0f), swingStartAngle(0.0f), swingEndAngle(0.0f),
      swingSpeed(500.0f), swordLength(50.0f), swordHitbox({0, 0, 0, 0}) {}

void Player::Update() {
    if (IsKeyDown(KEY_W)) position.y -= speed;
    if (IsKeyDown(KEY_S)) position.y += speed;
    if (IsKeyDown(KEY_A)) position.x -= speed;
    if (IsKeyDown(KEY_D)) position.x += speed;

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !isSwinging) {
        isSwinging = true;
        CalculateSwingAngles(); // Calculate start and end angles based on mouse
        swordAngle = swingStartAngle;
    }

    // Update sword mechanics
    UpdateSword();
}

void Player::CalculateSwingAngles() {
    Vector2 mousePos = GetMousePosition();

    float dx = mousePos.x - (position.x + width / 2);
    float dy = mousePos.y - (position.y + height / 2);
    float angleToMouse = atan2f(dy, dx) * RAD2DEG;

    swingStartAngle = angleToMouse - 45.0f;
    swingEndAngle = angleToMouse + 45.0f;
}

void Player::UpdateSword() {
    if (!isSwinging) return;

    // Animate the sword swing
    swordAngle += swingSpeed * GetFrameTime();
    if (swordAngle >= swingEndAngle) {
        swordAngle = swingEndAngle;
        isSwinging = false;         // End the swing
    }

    // sword hitbox
    float centerX = position.x + width / 2;
    float centerY = position.y + height / 2;
    float swordTipX = centerX + cosf(DEG2RAD * swordAngle) * swordLength;
    float swordTipY = centerY + sinf(DEG2RAD * swordAngle) * swordLength;

    swordHitbox = {
        centerX, centerY,
        swordTipX - centerX,
        swordTipY - centerY
    };
}

void Player::Draw() {

    DrawRectangleRec(GetCollisionBox(), BLUE);

    // Draw the sword
    if (isSwinging) {
        float centerX = position.x + width / 2;
        float centerY = position.y + height / 2;

        DrawLineEx(
            {centerX, centerY},
            {centerX + cosf(DEG2RAD * swordAngle) * swordLength,
             centerY + sinf(DEG2RAD * swordAngle) * swordLength},
            3.0f, DARKGRAY
        );
    }
}

bool Player::IsSwinging() const {
    return isSwinging;
}

Rectangle Player::GetSwordHitbox() const {
    return swordHitbox;
}

float Player::GetSwordAngle() const {
    return swordAngle;
}
