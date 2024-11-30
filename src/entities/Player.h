#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "raylib.h"

class Player : public Entity
{
private:
    bool isSwinging;
    float speed;
    float swordAngle;
    float swingStartAngle;
    float swingEndAngle;
    float swingSpeed;
    float swordLength;
    Rectangle swordHitbox;

    void UpdateSword();
    void CalculateSwingAngles();

public:
    Player(float x, float y);
    void Update() override;
    void Draw() override;

    bool IsSwinging() const;
    Rectangle GetSwordHitbox() const;
    float GetSwordAngle() const;
};

#endif