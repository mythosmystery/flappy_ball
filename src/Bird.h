#define BIRD_H
#include "raylib-cpp.hpp"

const float GRAVITY = 0.5f;
const float FLAP = -11.0f;
const int BIRD_SIZE = 20;

class Bird {
public:
  void draw();
  void move(raylib::Vector2 pos);

  void gravity();
  void flap();

  raylib::Vector2 getPos() { return this->pos; }

  Bird(raylib::Vector2 pos);
  Bird();

private:
  raylib::Vector2 pos;
  float velocity = 0.0f;
};
