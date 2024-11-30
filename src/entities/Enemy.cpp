#include "Enemy.h"
#include "Entity.h"
#include <cmath>

Enemy::Enemy(float x, float y, float width, float height, float speed)
    : Entity(x, y, width, height), speed(speed), isAlive(true) {}

void Enemy::UpdateAI(const Player &player)
{
    if (!isAlive)
        return;
    Vector2 playerPos = player.GetPosition();
    float dx = playerPos.x - position.x;
    float dy = playerPos.y - position.y;
    float distance = sqrtf(dx * dx + dy * dy);

    if (distance > 0.0f)
    {
        position.x += (dx / distance) * speed;
        position.y += (dy / distance) * speed;
    }
}

void Enemy::Update()
{
    if (!isAlive)
    {
        position = {-1000, -1000};
    }
}

void Enemy::Draw()
{
    if (!isAlive)
        return;
    DrawRectangleRec(GetCollisionBox(), RED);
}

bool Enemy::IsAlive() const
{
    return isAlive;
}

void Enemy::Kill()
{
    isAlive = false;
}