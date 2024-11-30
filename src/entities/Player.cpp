#include "Player.h"

Player::Player(float x, float y) 
    : Entity(x, y, 4.0f) {}

void Player::Update() {
    if (IsKeyDown(KEY_W)) y -= speed;
    if (IsKeyDown(KEY_S)) y += speed;
    if (IsKeyDown(KEY_A)) x -= speed;
    if (IsKeyDown(KEY_D)) x += speed;

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        //TODO: add sword swing
    }
}

void Player::Draw() {
    DrawCircle((int)x, (int)y, 20, BLUE);
}