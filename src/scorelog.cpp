#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "scorelog.h"


using namespace std;

ScoreLog::ScoreLog(int score, std::string name) : _highestScore(score), _HighestScorePlayer(name){};

int ScoreLog::GetHighestScore() const{
    return _highestScore;
}

std::string ScoreLog::GetHighestScorePlayer() const{
    return _HighestScorePlayer;
}

void ScoreLog::SetHighestScore(int score){
    ScoreLog::_highestScore = score;
}

void ScoreLog::SetHighestScorePlayer(std::string name){
    ScoreLog::_HighestScorePlayer = name;
}

void ScoreLog::WriteToLog(int score, std::string name){
    std::cout << "It worked!" ;
}

void ScoreLog::ParseLog(){
    std::ifstream score_file("../src/highscore.txt");
    int tempScore;
    std::string tempName;
    if(score_file){
    std::string line;
    while (getline(score_file, line)){
      std::istringstream sline(line);
      sline >> tempScore >> tempName;
      SetHighestScore(tempScore);
      SetHighestScorePlayer(tempName);
      }
    score_file.close();  
    }
    else ("Score file parse error!");
}
    


