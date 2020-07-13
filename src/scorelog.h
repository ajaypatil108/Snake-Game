#ifndef SCORELOG_H
#define SCORELOG_H

#include <string>

class ScoreLog{
 public:
  ScoreLog(int score, std::string name); // constructor with arguments
  ~ScoreLog(); // Destructor
  // Getter methods
  int GetHighestScore() const;
  std::string GetHighestScorePlayer() const;
  
  //Setter functions
  void SetHighestScore(int score);
  void SetHighestScorePlayer(std::string name);
  
  // Other methods to manipulate .txt file
  void ParseLog();
  void WriteToLog(int score, std::string name);


 private:
  // private class attributes
  int _highestScore;
  std::string _HighestScorePlayer;
};

#endif