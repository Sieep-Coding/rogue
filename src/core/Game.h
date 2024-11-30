#pragma
#ifndef GAME_H
#define GAME_H

#include "../entities/Player.h"
#include "../entities/Entity.h"
#include "../entities/Enemy.h"
#include <vector>
#include "raylib.h"

class Game
{
public:
    Game();
    ~Game();
    void Run();

private:
    void Update();
    void Draw();
    void GenerateRoom();

    Player player;
    std::vector<Enemy> enemies;
    int currentRoom;
    bool isRunning;
};

#endif