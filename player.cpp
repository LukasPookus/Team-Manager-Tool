// *******************************************************************************************
//   Solo Project 01 - Team Manager Tool: player.h
//   Author: Luke Drago
//
//   Description:
//   player is the second class designed for data storage. It is far more primitive than
//   teamRoster, handling just the attributes of a single player.
//
//   Member Functions:
//   - base mutators
//   - base accessors
//
//   - getNumString()
//   - getScoreString()
// *******************************************************************************************

#include "functions.h"
#include "player.h"

// ========= Constructor ==========

player::player() : playerNum(0), playerScore(0) {}

player::player(const std::string &playerName,
               const std::string &playerPosition,
               unsigned long long playerNum,
               unsigned long long playerScore)
    : playerName(playerName),
      playerPosition(playerPosition),
      playerNum(playerNum),
      playerScore(playerScore)
{}

// =========== Mutators ===========

void player::setName(const std::string& name) {
    playerName = name;
}

void player::setPosition(const std::string& position) {
    playerPosition = position;
}

void player::setNumber(unsigned long long num) {
    playerNum = num;
}

void player::setScore(unsigned long long score) {
    playerScore = score;
}


// ========== Accessors ===========

std::string player::getName() const {
    return playerName;
}

std::string player::getPosition() const {
    return playerPosition;
}

unsigned long long player::getNumber() const {
    return playerNum;
}

unsigned long long player::getScore() const {
    return playerScore;
}

std::string player::getNumString() const {
    return ullToString(playerNum);
}


std::string player::getScoreString()  const {
    return ullToString(playerScore);
}

