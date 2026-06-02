// *******************************************************************************************
//   Solo Project 01 - Team Manager Tool: Main.cpp
//   Author: Luke Drago
//
//   Description:
//   This tool is intended for team manager use. While not particularly in depth, it includes
//   the basic features one might need to efficiently and dynamically assemble and manage any
//   type of team.
//
//   Supports:
//   - Adding Players
//   - Editing Players
//   - Removing Players
//   - Displaying a full view of your roster
//   - Saving to and Loading from files
// *******************************************************************************************

#include "functions.h"

#include <iostream>

// Global Constants (Used for Clarity)
const int MAIN = 0, ADD = 1, SELECT = 2, ROSTER = 3;
const int EDIT = 4, REMOVE = 5, SAVE = 6, LOAD = 7;

int main() {
    teamRoster team;
    bool status = true;

    // ========== Main loop ===========
    do {
        // Main Menu
        team.setActionState(MAIN);
        printMenu(MAIN, team);

        std::string input = prompt("Choice");

        // Menu Choice Processor
        switch (char choice = toUpper(input[0])) {

        // Case C: CHECK ROSTER
        case 'C':
            team.setActionState(ROSTER);
            if (printMenu(ROSTER, team)) confirm();
            break;

        // Case A: ADD PLAYER
        case 'A':
            team.setActionState(ADD);
            if (printMenu(ADD, team)) confirm();
            break;

        // Case E: EDIT PLAYER
        case 'E':
            team.setActionState(EDIT);
            if (printMenu(SELECT, team)) confirm();
            break;

        // Case R: REMOVE PLAYER
        case 'R':
            team.setActionState(REMOVE);
            if (printMenu(SELECT, team)) confirm();
            break;

        // Case S: SAVE TO FILE
        case 'S':
            team.setActionState(SAVE);
            if (printMenu(SAVE, team)) confirm();
            break;

        // Case L: LOAD FROM FILE
        case 'L':
            team.setActionState(LOAD);
            if (printMenu(LOAD, team)) confirm();
            break;

        // Case Q: QUIT
        case 'Q':
            std::cout << "Quiting..." << std::endl;
            status = false;
            break;

        // Default: Invalid Choice
        default:
            std::cout << "Invalid Choice" << std::endl;
            break;
        }
    } while (status);

    return 0;
}