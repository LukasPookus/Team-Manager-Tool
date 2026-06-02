// *******************************************************************************************
//   Solo Project 01 - Team Manager Tool: functions.cpp
//   Author: Luke Drago
//
//   Description:
//   This is where all of the meat of the code lies. It was intended
//   to handle all complex behaviors of this program.
//
//   Functions:
//   - printMenu()
//   - confirm()
//   - prompt()
//   - toUpper()
//   - centerText()
//   - stringToUll()
//   - ullToString()
// *******************************************************************************************

#include "teamRoster.h"
#include "functions.h"

#include <iostream>
#include <fstream>

// ============================================================================
//                               UI and Menus
// ============================================================================


// printMenu(): Takes input gathered from the Main File, then
//              prints the desired menu
//
// Precondition: An integer and a teamRoster object
// Post-condition: Prints the menu associated with each integer value.
//
// Notes: Currently requires the call to pass the teamRoster object
//        being used to track all player data. I plan to change this
//        approach to shorten each call as more functionality is added.
bool printMenu(const int &menu, teamRoster &team) {
    switch (menu) {
        // ===============================================================================================
        //  CASE 0: MAIN MENU (As simple and obvious as it gets :P)
        // ===============================================================================================
        case 0: {
            std::cout << "================================================ \n";
            std::cout << "             Team Manager Tool v1.0              \n";
            std::cout << "================================================ \n";
            std::cout << "  [C] Check Roster                               \n";
            std::cout << "  [A] Add Player                                 \n";
            std::cout << "  [E] Edit Player                                \n";
            std::cout << "  [R] Remove Player                              \n";
            std::cout << "  [S] Save to File                               \n";
            std::cout << "  [L] Load from File                             \n";
            std::cout << "                                                 \n";
            std::cout << "  [Q] Quit                                       \n";
            std::cout << "================================================ \n";
            break;
        }
        // ===============================================================================================
        //  CASE 1: ADD PLAYER (Prompts the User for a Name, Position, Number, and Score)
        // ===============================================================================================
        case 1: {
            std::cout << "Selected: Add Player" << std::endl;
            std::cout << std::string(48,'=') << std::endl;      // Used repeatedly as the minimum
                                                                      // border for non-dynamic menus

            std::string inputs[4];
            const std::string prompts[] = {
                "Player's Name",
                "Player's Position",
                "Player's Number",
                "Player's Score"
            };

            for (int i = 0; i < 4; i++) {               // Prompts User for Player's details
                inputs[i] = prompt(prompts[i]);
            }

            team.addPlayer(inputs[0],                   // Adds Player
                           inputs[1],
                           stringToUll(inputs[2]),
                           stringToUll(inputs[3])
                           );
            return true;
        }
        // ===============================================================================================
        //  CASE 2: PLAYER SELECT MENU (Routes to the Edit Player Menu [Case 4] or Removes a Player)
        // ===============================================================================================
        case 2: {

            // ========== Declarations ===========
            const size_t PREFIX_PADDING = 7;
            const size_t MIN_MENU_WIDTH = 48;

            const std::vector<player> &players = team.getPlayers();

            size_t numberOption = 1;

            size_t borderWidth = team.getMaxName() + PREFIX_PADDING;
            if (borderWidth < MIN_MENU_WIDTH) borderWidth = MIN_MENU_WIDTH;

            // ============= Printer =============
            if (players.empty()) {                                                  // stops the user from accessing
                if (team.getActionState() == 4) {                                   // an empty menu screen
                    std::cout << "There are no players to edit." << std::endl;
                    return true;
                }
                if (team.getActionState() == 5) {
                    std::cout << "There are no players to remove." << std::endl;
                    return true;
                }
            }

            if (team.getActionState() == 4) {
                std::cout << "Selected: Edit Player" << std::endl;
            }

            if (team.getActionState() == 5) {
                std::cout << "Selected: Remove Player" << std::endl;
            }

            std::cout << std::string(borderWidth,'=') << std::endl;

            for (const player &player : players) {                                          // Prints players in a
                std::cout << "  [" << numberOption << "] " << player.getName() << "\n";     // numbered list
                numberOption++;
            }

            std::cout << "\n  [0]  Go Back\n";

            std::cout << std::string(borderWidth,'=') << std::endl;

            // ======= Prompts / Branches ========

            std::string input;

            // Calls Case 4, the "Edit Menu"
            if (team.getActionState() == 4) {
                while (true) {
                    size_t index = stringToUll(prompt("Option #"));
                    if (index == 0) return false;
                    if (index > players.size()) {
                        std::cout << "Invalid Choice. Please try again.\n";
                        continue;
                    }
                    team.setIndex(index);
                    if (!printMenu(4, team)) return false;
                }
            }

            // Removes a player according to user selection
            if (team.getActionState() == 5) {
                while (true) {
                    size_t index = stringToUll(prompt("Option #"));
                    if (index == 0) return false;
                    if (index > players.size()) {
                        std::cout << "Invalid Choice. Please try again.\n";
                        continue;
                    }
                    team.setIndex(index);
                    std::string removedPlayer = players[team.getIndex()].getName();
                    team.removePlayer();
                    std::cout << "Removed " << removedPlayer << std::endl;
                    break;
                }
            }
            break;
        }
        // ===============================================================================================
        //  CASE 3: CHECK ROSTER (Displays all player's names, positions, Numbers, and Cumulative Scores)
        // ===============================================================================================
        case 3: {

            // ========== Declarations ===========
            const std::string header[] = {"Name", "Position", "Number", "Score"};
            const std::vector<player> &players = team.getPlayers();

            size_t padName = team.getMaxName() + 4;             // Each category's padding is determined dynamically
            if (padName < 12) padName = 12;                     // The minimum padding per category must add up to
                                                                // 48 to match the Main Menu's border width
            size_t padPos = team.getMaxPos() + 8;
            if (padPos < 12) padPos = 12;

            size_t padNum = team.getMaxNum() + 6;
            if (padNum < 12) padNum = 12;

            size_t padScore = team.getMaxScore() + 5;
            if (padScore < 12) padScore = 12;

            size_t maxPadding = padName + padPos + padNum + padScore;

            // ============= Printer =============
            std::cout << "Selected: Check Roster" << std::endl;

            std::cout << std::string(maxPadding,'=') << std::endl;

            // Prints headers for each category
            std::cout << centerText(padName, header[0])
                      << centerText(padPos, header[1])
                      << centerText(padNum, header[2])
                      << centerText(padScore, header[3])
                      << std::endl;

            // Prints player's names, positions, numbers, and score
            for (const player &player : players) {
                std::cout << centerText(padName, player.getName())
                          << centerText(padPos, player.getPosition())
                          << centerText(padNum, player.getNumString())
                          << centerText(padScore, player.getScoreString())
                          << std::endl;
            }

            std::cout << std::string(maxPadding,'=') << std::endl;
            return true;
        }
        // ===============================================================================================
        //  CASE 4: EDIT PLAYER MENU (Allows the User to Edit a chosen player's current data)
        // ===============================================================================================
        case 4: {
            while (true) {

                // ================ Declarations ==================
                const std::string header[] = {"Name", "Position", "Number", "Score"};
                const std::vector<player> &players = team.getPlayers();

                size_t padName = team.getMaxName() + 4;        // Just like as Case 3, The minimum padding
                if (padName < 12) padName = 12;                // per category must add up to 48 to match
                                                               // the Main Menu's border width

                size_t padPos = team.getMaxPos() + 8;
                if (padPos < 12) padPos = 12;

                size_t padNum = team.getMaxNum() + 6;
                if (padNum < 12) padNum = 12;

                size_t padScore = team.getMaxScore() + 5;
                if (padScore < 12) padScore = 12;

                size_t maxPadding = padName + padPos + padNum + padScore;


                std::cout << std::string(maxPadding,'=') << std::endl;

                // Prints the headers for each category
                std::cout << centerText(padName, header[0])
                          << centerText(padPos, header[1])
                          << centerText(padNum, header[2])
                          << centerText(padScore, header[3])
                          << std::endl;

                // prints one player's data
                std::cout << centerText(padName, players[team.getIndex()].getName())
                          << centerText(padPos, players[team.getIndex()].getPosition())
                          << centerText(padNum, players[team.getIndex()].getNumString())
                          << centerText(padScore, players[team.getIndex()].getScoreString())
                          << std::endl;

                std::cout << std::string(maxPadding,'=') << std::endl;

                // Menu Options layout
                std::cout << "  [1]  Edit Name     \n"
                          << "  [2]  Edit Position \n"
                          << "  [3]  Edit Number   \n"
                          << "  [4]  Edit Score    \n"
                          << "                     \n"
                          << "  [0]  Go Back       \n";


                std::cout << std::string(maxPadding,'=') << std::endl;

                // ========== Prompts / Function Calls ===========

                std::string temp;
                size_t index = stringToUll(prompt("Option #"));
                switch (index) {
                case 0: {
                    return false;
                }
                case 1: {
                    team.editPlayerName(prompt("Player's new name"));
                    break;
                }
                case 2: {
                    team.editPlayerPosition(prompt("Player's new position"));
                    break;
                }
                case 3: {
                    team.editPlayerNumber(stringToUll(prompt("Player's new number")));
                    break;
                }
                case 4: {
                    team.editPlayerScore(stringToUll(prompt("Player's new score")));
                    break;
                }
                default:
                    std::cout << "Invalid Choice\n";
                    break;
                }
            }
        }
        // ===============================================================================================
        //  CASE 6: SAVE FILE (Saves data to a specified file. Already existing files are overwritten)
        // ===============================================================================================
        case 6: {
            std::cout << "Selected: Save\n";
            std::cout << std::string(48,'=') << std::endl;

            const std::vector<player> &players = team.getPlayers();
            std::ofstream saveFile;
            std::string filePath = prompt("File Path");

            saveFile.open(filePath, std::ofstream::out);

            if (saveFile.is_open()) {

                for (const player &player : players) {
                    saveFile << player.getName() << "\n"
                              << player.getPosition() << "\n"
                              << player.getNumString() << "\n"
                              << player.getScoreString() << "\n";
                }

                saveFile.close();
                std::cout << "Changes Saved.";
            } else {
                std::cerr << "Unable to open or create file";
            }
            break;
        }
        // ===============================================================================================
        //  CASE 7: LOAD FILE (Loads data to from a specified file. All current data is overwritten)
        // ===============================================================================================
        case 7: {
            std::cout << "Selected: Load\n";
            std::cout << std::string(48,'=') << std::endl;

            std::ifstream saveFile;
            std::string filePath = prompt("File Path");

            saveFile.open(filePath, std::ifstream::in);
            if (saveFile.is_open()) {
                std::cout << "file opened successfully\n";
                team.clearPlayers();

                std::string name;
                std::string position;
                std::string number;
                std::string score;

                while (getline(saveFile, name) &&
                       getline(saveFile, position) &&
                       getline(saveFile, number) &&
                       getline(saveFile, score)) {

                    team.addPlayer(name, position, stringToUll(number), stringToUll(score));
                }
            } else {
                std::cerr << "Unable to open specified file";
            }
            return true;
        }
        default:
            break;
    }
    return true;
}

// Confirm(): Pauses all Menu activity until the User is ready to move on.
//
// Preconditions: None
// Post-conditions: None
void confirm() {
    std::cout << "\nHit Enter to Continue\n";
    std::string x;
    getline(std::cin,x);
}


// =============== Input/Output ================

// prompt(): Takes a string, then inserts it in between " >> Enter"
//           and ": " to create an appropriate prompt, then takes the
//           user's input and returns it.
//
// Preconditions: Any string (Grammatically/Contextually sensical)
// Post-conditions: Returns User input
std::string prompt(const std::string& prompt) {
    std::string input;
    std::cout << ">> Enter " << prompt << ": ";
    getline(std::cin , input);
    return input;
}


// ============= Helper Functions =============

// toUpper(): A safer version of std::toupper without any narrowing
//            conversions to type int. its handling of non-alphabetical
//            and non-lowercase chars makes it loop friendly.
//
// Preconditions: Any char
// Post-conditions: Converts a lowercase char into it's uppercase counterpart,
//                  non-alphabetical or non-lowercase chars are not converted
//                  and are returned as they were passed
char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    return c;
}

// centerText(): Dynamically formats a given string to be centered within a block by whitespace
//
// Preconditions: Any non-negative integer, to be used as total padding, and any string
// Post-conditions: Centers the original string in a new string surrounded by whitespace
//                  determined dynamically by the padding integer
std::string centerText(const size_t padding, const std::string &text) {
    const size_t left = (padding - text.length()) / 2;
    const size_t right = padding - text.length() - left;
    return std::string(left, ' ') + text + std::string(right, ' ');
}

// stringToUll(): converts a string to an ull (unsigned long long)
//
// Preconditions: Any string
// Post-conditions: The string is stripped of all non-numerical
//                  characters and converted to an ull
unsigned long long stringToUll(const std::string &raw) {
    unsigned long long stripped = 0;
    for (const char i : raw) {
        if (i >= 48 && i <= 57) {
            stripped *= 10;
            stripped += (i - '0');
        }
    }
    return stripped;
}

// ullToString(): Converts an ull (unsigned long long) to a string
//
// Preconditions: Any valid ull
// Post-conditions: The ull is converted to a string with commas
//                  added in the correct digit separator slots
std::string ullToString(unsigned long long number) {
    if (number == 0) return "0";

    std::string result;
    size_t count = 0;
    while (number > 0) {
        if (count > 0 && count % 3 == 0) {
            result = ',' + result;
        }
        unsigned int digit = number % 10;
        char c = digit + '0';
        result = c + result;

        number /= 10;
        count++;
    }

    return result;
}