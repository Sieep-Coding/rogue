#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "raylib.h"

class Enemy : public Entity
{
public:
    Enemy(float x, float y);
    void Update() override;
    void Draw() override;
};

#endif