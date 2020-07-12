#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "scorelog.h"


int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  ScoreLog log(0,"NoName");
  log.ParseLog();


  std::string name;
  std::cout << "Enter your name " << "\n"; 
  std::cin >> name;

  std::cout << "Hey " << name << ", can you beat the high score of " << log.GetHighestScore() <<  " set by " << log.GetHighestScorePlayer() << "?" << "\n";


  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";  
  std::cout << "Size: " << game.GetSize() << "\n";

  if (game.GetScore() > log.GetHighestScore()){
    log.WriteToLog(game.GetScore(), name);
  }


  return 0;
}