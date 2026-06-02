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
//
//   Explicit details are commented below
// *******************************************************************************************

#ifndef INTERN_PROJECT_PLAYER_H
#define INTERN_PROJECT_PLAYER_H

#include <string>


class player {
public:
    // ========= Constructor ==========

    // Default
    player();

    // Parameterized
    player(const std::string &playerName,
           const std::string &playerPosition,
           unsigned long long playerNum,
           unsigned long long playerScore
           );

    // =========== Mutators ===========

    // setName(): Sets the player's name
    //
    // Preconditions: Any String
    // Post-conditions: sets playerName with name
    void setName(const std::string &name);

    // setPosition(): Sets the player's position
    //
    // Preconditions: Any String
    // Post-conditions: sets playerPosition with position
    void setPosition(const std::string &position);

    // setNumber(): Sets the player's number
    //
    // Preconditions: Any String
    // Post-conditions: sets playerNumber with number
    void setNumber(unsigned long long num);

    // setScore(): Sets the player's score
    //
    // Preconditions: Any String
    // Post-conditions: sets playerScore with score
    void setScore(unsigned long long score);


    // ========== Accessors ===========

    // getName(): Gets the player's name
    //
    // Preconditions: None
    // Post-conditions: returns playerName
    [[nodiscard]] std::string getName() const;

    // getPosition(): Gets the player's position
    //
    // Preconditions: None
    // Post-conditions: returns playerPosition
    [[nodiscard]] std::string getPosition() const;

    // getNumber(): Gets the player's number
    //
    // Preconditions: None
    // Post-conditions: returns playerNumber
    [[nodiscard]] unsigned long long getNumber() const;

    // getScore(): Gets the player's score
    //
    // Preconditions: None
    // Post-conditions: returns playerScore
    [[nodiscard]] unsigned long long getScore() const;


    // getNumString():
    //
    // Preconditions: None
    // Post-conditions: returns a string converted playerNumber
    [[nodiscard]] std::string getNumString() const;

    // getScoreString():
    //
    // Preconditions: None
    // Post-conditions: returns a string converted playerScore
    [[nodiscard]] std::string getScoreString() const;

private:
    std::string playerName;
    std::string playerPosition;

    unsigned long long playerNum;
    unsigned long long playerScore;
};



#endif //INTERN_PROJECT_PLAYER_H
