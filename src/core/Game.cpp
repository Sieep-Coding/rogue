#include "Game.h"
#include "../entities/Enemy.h"

Game::Game()
    : player(400, 300), currentRoom(1), isRunning(true)
{
    InitWindow(800, 600, "Rougeblob");
    SetTargetFPS(60);
    GenerateRoom();
}

Game::~Game()
{
    CloseWindow();
}

void Game::Run()
{
    while (isRunning && !WindowShouldClose())
    {
        Update();
        Draw();
    }
}

void Game::Update()
{
    TraceLog(LOG_INFO, "Updating Game. Current Room: %d", currentRoom);
    player.Update();

    for (auto &enemy : enemies)
    {
        enemy.Update();
    }

    if (enemies.empty() && (IsKeyPressed(KEY_E) || IsKeyPressed(KEY_RIGHT)))
    {
        currentRoom++;
        GenerateRoom();
    }
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(WHITE);

    player.Draw();

    for (auto &enemy : enemies)
    {
        enemy.Draw();
    }

    DrawText(TextFormat("Room: %d", currentRoom), 10, 10, 20, DARKPURPLE);

    EndDrawing();
}

void Game::GenerateRoom()
{
    enemies.clear();
    for (int i = 0; i < currentRoom + 2; i++)
    {
        float ex = GetRandomValue(50, 750);
        float ey = GetRandomValue(50, 550);
        enemies.emplace_back(Enemy(ex, ey));
    }
}