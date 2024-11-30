#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "raylib.h"

class Player : public Entity
{
private:
    bool isSwinging;
    float swordAngle;
    float swingSpeed;
    float swingProgress;

public:
    Player(float x, float y);
    void Update() override;
    void Draw() override;

    bool IsSwinging() const;
    float GetSwordAngle() const;
};

#endif