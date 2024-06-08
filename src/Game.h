#define GAME_H

#include "Bird.h"
#include "Pipe.h"
#include "raylib-cpp.hpp"
#include <memory>

enum class GameState {
  PLAYING,
  GAME_OVER,
  MENU,
};

struct Game {
  Game();

  void draw();
  void update();

  void reset();

  Bird bird;
  std::vector<Pipe> pipes = {};
  GameState state = GameState::MENU;
  int score = 0;

  raylib::Color backgroundColor = BLUE;
  std::unique_ptr<raylib::Window> window;
};
