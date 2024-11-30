#include "Game.h"

Game::Game()
    : player(400, 300), currentRoom(1), isRunning(true)
{
    InitWindow(800, 600, "Rougeblob");
    SetTargetFPS(60);
    GenerateRoom();
}

Game::~Game() {
    CloseWindow();
}

void Game::Run() {
    while (!isRunning && !WindowShouldClose()) {
        Update();
        Draw();
    }
}

void Game::Update() {
    player.Update();

    for (auto& enemy : enemies) {
        enemy.Update();
    }

    if (enemies.empty() && (IsKeyPressed(KEY_E) || IsKeyPressed(KEY_RIGHT))) {
        currentRoom++;
        GenerateRoom();
    }
}

void 