// *******************************************************************************************
//   Solo Project 01 - Team Manager Tool: functions.h
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
//
//   Explicit details are commented below
// *******************************************************************************************

#ifndef INTERN_PROJECT_FUNCTIONS_H
#define INTERN_PROJECT_FUNCTIONS_H

#include "teamRoster.h"

// ========== UI and Menus ===========

// printMenu(): Takes input gathered from the Main File, then
//              prints the desired menu
//
// Precondition: An integer and a teamRoster object
// Post-condition: Prints the menu associated with each integer value and
//                 returns a bool that determines whether or not a pause is
//                 triggered.
//
// Notes: Currently requires the call to pass the teamRoster object
//        being used to track all player data. I plan to change this
//        approach to shorten each call as more functionality is added.
bool printMenu(const int &menu, teamRoster &team);

// Confirm(): Pauses all Menu activity until the User is ready to move on.
//
// Preconditions: None
// Post-conditions: None
void confirm();

// =============== Input/Output ================

// prompt(): Takes a string, then inserts it in between " >> Enter"
//           and ": " to create an appropriate prompt, then takes the
//           user's input and returns it.
//
// Preconditions: Any string (Grammatically/Contextually sensical)
// Post-conditions: Returns User input
std::string prompt(const std::string &prompt);


// ============= Helper Functions =============

// toUpper(): A safer version of std::toupper without any narrowing
//            conversions to type int. its handling of non-alphabetical
//            and non-lowercase chars makes it loop friendly.
//
// Preconditions: Any char
// Post-conditions: Converts a lowercase char into it's uppercase counterpart,
//                  non-alphabetical or non-lowercase chars are not converted
//                  and are returned as they were passed
char toUpper(char c);

// centerText(): Dynamically formats a given string to be centered within a block by whitespace
//
// Preconditions: Any non-negative integer, to be used as total padding, and any string
// Post-conditions: Centers the original string in a new string surrounded by whitespace
//                  determined dynamically by the padding integer
std::string centerText(size_t padding, const std::string &text);

// stringToUll(): converts a string to an ull (unsigned long long)
//
// Preconditions: Any string
// Post-conditions: The string is stripped of all non-numerical
//                  characters and converted to an ull
unsigned long long stringToUll(const std::string &raw);

// ullToString(): Converts an ull (unsigned long long) to a string
//
// Preconditions: Any valid ull
// Post-conditions: The ull is converted to a string with commas
//                  added in the correct digit separator slots
std::string ullToString(unsigned long long number);


#endif //INTERN_PROJECT_FUNCTIONS_H
