#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "raylib.h"

class Player : public Entity
{
private:
    float swordAngle = 0.0f;
    bool isSwinging = false;
    float swingTimer = 0.0f;

public:
    Player(float x, float y);
    void Update();
    void Draw();

    bool IsSwinging() const { return isSwinging; }
    float GetSwordAngle() const { return swordAngle; }
};

#endif