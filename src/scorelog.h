#ifndef SCORELOG_H
#define SCORELOG_H

#include <string>

class ScoreLog{
 public:
  ScoreLog(int score, std::string name);
  int GetHighestScore() const;
  std::string GetHighestScorePlayer() const;
  void SetHighestScore(int score);
  void SetHighestScorePlayer(std::string name);
  void ParseLog();
  void WriteToLog();

 private:
  int _highestScore;
  std::string _HighestScorePlayer;
};

#endif