#include "Game.h"
#include "raylib-cpp.hpp"

int main() {
  Game game;

  // Main game loop
  while (!game.window->ShouldClose()) {
    // Draw
    game.draw();

    // Update
    game.update();
  }

  return 0;
}
