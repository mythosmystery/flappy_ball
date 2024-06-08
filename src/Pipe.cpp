#include "Pipe.h"
#include "Bird.h"
#include "Constants.h"

Pipe::Pipe(raylib::Vector2 pos) : pos(pos) {
  this->height = GetRandomValue(100, 400);
  this->gap = GetRandomValue(150, 300);
}

Pipe::Pipe() {
  this->pos = raylib::Vector2(SCREEN_WIDTH, 0);
  this->height = GetRandomValue(100, 400);
  this->gap = GetRandomValue(150, 300);
}

void Pipe::draw() {
  DrawRectangleV(this->pos, raylib::Vector2(PIPE_WIDTH, this->height), GREEN);
  DrawRectangleV(
      raylib::Vector2(this->pos.x, this->height + this->gap),
      raylib::Vector2(PIPE_WIDTH, SCREEN_HEIGHT - this->height - this->gap),
      GREEN);
}

void Pipe::update() { this->pos.x -= PIPE_SPEED; }

bool Pipe::offscreen() { return this->pos.x + 50 < 0; }

bool Pipe::shouldScore(raylib::Vector2 birdPos) {
  bool passedPipe = birdPos.x > this->pos.x + PIPE_WIDTH;
  if (passedPipe && !this->scored) {
    this->scored = true;
    return true;
  }
  return false;
}

bool Pipe::isColliding(raylib::Vector2 birdPos) {
  if (birdPos.x + BIRD_SIZE > this->pos.x &&
      birdPos.x < this->pos.x + PIPE_WIDTH) {
    if (birdPos.y < this->height ||
        birdPos.y + BIRD_SIZE > this->height + this->gap) {
      return true;
    }
  }

  return false;
}
