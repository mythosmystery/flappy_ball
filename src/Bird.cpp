#include "Bird.h"
#include "Constants.h"

void Bird::flap() { this->velocity = FLAP; }

void Bird::gravity() {
  this->velocity += GRAVITY;
  this->move(raylib::Vector2(0, this->velocity));
}

void Bird::draw() { DrawCircleV(pos, BIRD_SIZE, YELLOW); }

void Bird::move(raylib::Vector2 pos) {
  raylib::Vector2 newPos = this->pos.Add(pos);

  if (newPos.y > SCREEN_HEIGHT) {
    newPos.y = SCREEN_HEIGHT;
  } else if (newPos.y < 0) {
    newPos.y = 0;
  } else if (newPos.x > SCREEN_WIDTH) {
    newPos.x = SCREEN_WIDTH;
  } else if (newPos.x < 0) {
    newPos.x = 0;
  }

  this->pos = newPos;
}

Bird::Bird(raylib::Vector2 pos) : pos(pos) {}

Bird::Bird() { this->pos = SCREEN_CENTER; }
