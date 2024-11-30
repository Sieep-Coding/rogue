#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
private:
    float speed;
    bool isAlive;

public:
    Enemy(float x, float y, float width, float height, float speed);
    void Update() override;
    void UpdateAI(const Player &player);
    void Draw() override;

    bool IsAlive() const;
    void Kill();
};

#endif