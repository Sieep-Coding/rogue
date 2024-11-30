#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Entity.h"
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