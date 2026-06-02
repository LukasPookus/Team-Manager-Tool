// *******************************************************************************************
//   Solo Project 01 - Team Manager Tool: teamRoster.cpp
//   Author: Luke Drago
//
//   Description:
//   The teamRoster class is one of two classes designed for data storage. It was designed to hold
//   a dynamic vector of "player" objects, as well as its own internal index and action state.
//   Additionally, it handles getting other details about the players stored in its vector,
//   such as the long instance of a given attribute, and can return those values.
//
//   Member Functions:
//   - addPlayer()
//   - editPlayer"  "()
//   - removePlayer()
//   - clearPlayers()
//   - setIndex()
//   - setActionState()
//
//   - getMax"  "()
//   - getIndex()
//   - getActionState()
//   - getPlayers()
//   - getPlayer()
// *******************************************************************************************

#include "teamRoster.h"

// ========= Constructor ==========

teamRoster::teamRoster() {}

// =========== Mutators ===========

void teamRoster::addPlayer(const std::string &name,
                           const std::string &position,
                           const unsigned long long number,
                           const unsigned long long score) {
    player player(name, position, number, score);
    players.push_back(player);
}

void teamRoster::editPlayerName(const std::string& name) {
    players[index].setName(name);
}

void teamRoster::editPlayerPosition(const std::string& pos) {
    players[index].setPosition(pos);
}

void teamRoster::editPlayerNumber(unsigned long long num) {
    players[index].setNumber(num);
}

void teamRoster::editPlayerScore(unsigned long long score) {
    players[index].setScore(score);
}

void teamRoster::removePlayer() {
    players.erase(players.begin() + index);
}

void teamRoster::clearPlayers() {
    players.clear();
}

void teamRoster::setIndex(const unsigned long long idx) {
    if (idx <= 0) {
        this->index = 0;
    } else {
        this->index = idx - 1;
    }
}

void teamRoster::setActionState(const unsigned long long state) {
    actionState = state;
}


// ========== Accessors ===========

size_t teamRoster::getMaxName() const {
    size_t maxName = 0;
    for (const player &player : players) {
        if (player.getName().length() > maxName) {
            maxName = player.getName().length();
        }
    }
    return maxName;
}

size_t teamRoster::getMaxPos() const {
    size_t maxPos = 0;
    for (const player &player : players) {
        if (player.getPosition().length() > maxPos) {
            maxPos = player.getPosition().length();
        }
    }
    return maxPos;
}

size_t teamRoster::getMaxNum() const {
    size_t maxNum = 0;
    for (const player &player : players) {
        if (player.getNumString().length() > maxNum) {
            maxNum = player.getNumString().length();
        }
    }
    return maxNum;
}

size_t teamRoster::getMaxScore() const {
    size_t maxScore = 0;
    for (const player &player : players) {
        if (player.getScoreString().length() > maxScore) {
            maxScore = player.getScoreString().length();
        }
    }
    return maxScore;
}

size_t teamRoster::getIndex() const {
    return index;
}

size_t teamRoster::getActionState() const {
    return actionState;
}

const std::vector<player>& teamRoster::getPlayers() const {
    return players;
}

const player& teamRoster::getPlayer(const size_t idx) const {
    return players[idx];
}




