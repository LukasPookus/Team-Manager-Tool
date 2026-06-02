// *******************************************************************************************
//   Solo Project 01 - Team Manager Tool: teamRoster.h
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
//
//   Explicit details are commented below
// *******************************************************************************************

#ifndef INTERN_PROJECT_TEAM_H
#define INTERN_PROJECT_TEAM_H

#include "player.h"

#include <vector>

class teamRoster {
public:

    // ========= Constructor ==========

    // Default
    teamRoster();

    // =========== Mutators ===========

    // addPlayer():
    //
    // Preconditions: Two valid strings for name and position and two
    //                valid unsigned long longs for number and score
    // Post-conditions: Creates and adds player to the player vector
    void addPlayer(
        const std::string &name,
        const std::string &position,
        unsigned long long number,
        unsigned long long score
        );


    // editPlayerName():
    //
    // Preconditions: Any String
    // Post-conditions: Edits a player's name
    void editPlayerName(const std::string &name);

    // editPlayerPosition():
    //
    // Preconditions: Any String
    // Post-conditions: Edits a player's position
    void editPlayerPosition(const std::string &pos);

    // editPlayerNumber():
    //
    // Preconditions: An unsigned long long integer
    // Post-conditions: Edits a player's number
    void editPlayerNumber(unsigned long long num);

    // editPlayerScore():
    //
    // Preconditions: An unsigned long long integer
    // Post-conditions: Edits a player's score
    void editPlayerScore(unsigned long long score);


    // removePlayer():
    //
    // Preconditions: None
    // Post-conditions: Removes the player at index in the player vector
    void removePlayer();

    // clearPlayers():
    //
    // Preconditions: None
    // Post-conditions: Erases all players from the player vector
    void clearPlayers();


    // setIndex(): sets the index stored by teamRoster
    //
    // Preconditions: An unsigned long long integer idx
    // Post-conditions: sets index with idx - 1, unless idx <= 0
    void setIndex(unsigned long long idx);

    // setActionState(): sets the action state of teamRoster
    //
    // Preconditions: An unsigned long long integer state
    // Post-conditions: sets actionState with state
    void setActionState(unsigned long long state);

    // ========== Accessors ===========

    // getMaxName():
    //
    // Preconditions: None
    // Post-conditions: parses the player vector for the player with the
    //                  longest name, then returns the length of that name.
    [[nodiscard]] size_t getMaxName() const;

    // getMaxPos():
    //
    // Preconditions: None
    // Post-conditions: parses the player vector for the player with the
    //                  longest position, then returns the length of that position.
    [[nodiscard]] size_t getMaxPos() const;

    // getMaxNum():
    //
    // Preconditions: None
    // Post-conditions: parses the player vector for the player with the
    //                  longest number, then returns the length of that number.
    [[nodiscard]] size_t getMaxNum() const;

    // getMaxScore():
    //
    // Preconditions: None
    // Post-conditions: parses the player vector for the player with the
    //                  longest score, then returns the length of that score.
    [[nodiscard]] size_t getMaxScore() const;


    // getIndex():
    //
    // Preconditions: None
    // Post-conditions: Returns the value of index
    [[nodiscard]] size_t getIndex() const;

    // getActionState():
    //
    // Preconditions: None
    // Post-conditions: returns teamRoster's action state
    [[nodiscard]] size_t getActionState() const;

    // getPlayers():
    //
    // Preconditions: None
    // Post-conditions: Returns a reference to the player vector
    [[nodiscard]] const std::vector<player>& getPlayers() const;

    // getPlayer():
    //
    // Preconditions: None
    // Post-conditions: Returns a reference to the player at
    //                  index idx of the player vector
    [[nodiscard]] const player& getPlayer(size_t idx) const;

private:
    // Default Placeholders
    std::vector<player> players =
        {
            player("Plais E. Holderman", "N/A", 1000, 100),
            player("Dee Falt", "N/A", 96, 23),
            player("Ree M. Uvmee", "N/A", 40, 67),
            player("Cobson", "The GOAT", 1, 1000000)
        };

    size_t index = 0;
    unsigned long long actionState = 0;
};



#endif //INTERN_PROJECT_TEAM_H
