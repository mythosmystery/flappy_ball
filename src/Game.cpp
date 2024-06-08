#include "Game.h"
#include "Constants.h"

Game::Game() {
  // Initialization
  std::unique_ptr<raylib::Window> window = std::make_unique<raylib::Window>(
      SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Ball");

  SetTargetFPS(60);

  this->pipes.push_back(Pipe());
  this->window = std::move(window);
}

void Game::reset() {
  this->score = 0;
  this->bird = Bird();
  this->pipes.clear();
  this->pipes.push_back(Pipe());
  this->state = GameState::MENU;
}

void Game::draw() {
  // Draw the game
  BeginDrawing();

  this->backgroundColor.ClearBackground();

  switch (this->state) {
  case GameState::MENU:
    DrawText("Press SPACE to start", 100, SCREEN_HEIGHT / 2, 25, WHITE);
    break;
  case GameState::GAME_OVER:
    DrawText("Game Over", 100, SCREEN_HEIGHT / 2, 25, WHITE);
    DrawText("Press SPACE to restart", 100, SCREEN_HEIGHT / 2 + 50, 25, WHITE);
    DrawText(std::to_string(this->score).c_str(), SCREEN_WIDTH / 2,
             SCREEN_HEIGHT / 2 - 50, 25, WHITE);
    break;
  case GameState::PLAYING:
    this->bird.draw();
    DrawText(std::to_string(this->score).c_str(), SCREEN_WIDTH / 2, 10, 25,
             WHITE);

    for (Pipe &pipe : this->pipes) {
      pipe.draw();
    }
    break;
  }

  EndDrawing();
}

void Game::update() {
  // Update the game
  switch (this->state) {
  case GameState::MENU:
    if (IsKeyPressed(KEY_SPACE)) {
      this->state = GameState::PLAYING;
    }
    break;
  case GameState::GAME_OVER:
    if (IsKeyPressed(KEY_SPACE)) {
      this->reset();
    }
    break;
  case GameState::PLAYING:

    this->bird.gravity();

    if (IsKeyPressed(KEY_SPACE)) {
      this->bird.flap();
    }

    if (this->bird.getPos().y == SCREEN_HEIGHT) {
      this->state = GameState::GAME_OVER;
    }

    for (Pipe &pipe : this->pipes) {
      if (pipe.shouldScore(this->bird.getPos())) {
        this->score++;
      }

      pipe.update();

      if (pipe.getX() == SCREEN_CENTER.x ||
          pipe.getX() == SCREEN_CENTER.x - 1 ||
          pipe.getX() == SCREEN_CENTER.x + 1) {
        this->pipes.push_back(Pipe());
      }

      if (pipe.isColliding(this->bird.getPos())) {
        this->state = GameState::GAME_OVER;
      }

      if (pipe.offscreen()) {
        this->pipes.erase(this->pipes.begin());
      }
    }
    break;
  }
}
