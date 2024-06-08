#define PIPE_H
#include "raylib-cpp.hpp"

const int PIPE_WIDTH = 50;
const int PIPE_SPEED = 3;

class Pipe {
public:
  void draw();
  void update();

  bool offscreen();
  bool isColliding(raylib::Vector2 birdPos);
  bool shouldScore(raylib::Vector2 birdPos);

  float getX() { return this->pos.x; }

  Pipe(raylib::Vector2 pos);
  Pipe();

private:
  raylib::Vector2 pos;
  int height;
  int gap;
  bool scored = false;
};
