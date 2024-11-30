#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"

class Entity
{
protected:
    Vector2 position;
    float width;
    float height;

public:
    Entity(float x, float y, float width, float height);
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual ~Entity() = default;

    Rectangle GetCollisionBox() const;
    Vector2 GetPosition() const;
    float GetWidth() const;
    float GetHeight() const;
};

#endif