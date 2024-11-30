#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player : public Entity {
public:
    Player(float x, float y);
    void Update();
    void Draw();
};

#endif