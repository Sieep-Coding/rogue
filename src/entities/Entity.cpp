#include "Entity.h"

Entity::Entity(float x, float y, float width, float height)
    : position({x, y}), width(width), height(height) {}

Rectangle Entity::GetCollisionBox() const
{
    return {position.x, position.y, width, height};
}

Vector2 Entity::GetPosition() const
{
    return position;
}

float Entity::GetWidth() const
{
    return width;
}

float Entity::GetHeight() const
{
    return height;
}