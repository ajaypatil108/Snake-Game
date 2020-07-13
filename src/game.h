#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  void TogglePause();
  int GetScore() const;
  int GetSize() const;
  bool _boundary = false; // Added bool boundary that decides whether to put a wall boundary around the game or not. 

 private:
  Snake snake;
  SDL_Point food;
  bool _paused = false; // Added bool _paused that is used to toggle pause/resume with ESC key. 
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  // Added Pause() and Resume() methods to control renderer state based on ESC key press. 
  void Pause();
  void Resume();
  void PlaceFood();
  void Update(Renderer &renderer);
};

#endif