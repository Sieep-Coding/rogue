#include "Enemy.h"

Enemy::Enemy(float x, float y) 
    : Entity(x, y, 2.0f) {}

void Enemy::Update() {
    //TODO: Enemy
}

void Enemy::Draw() {
    DrawCircle((int)x, int(y), 15, RED);
}