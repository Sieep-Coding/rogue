#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
protected:
    float x, y;
    float speed;

public:
    Entity(float x, float y, float speed);
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual ~Entity() = default;
};

#endif