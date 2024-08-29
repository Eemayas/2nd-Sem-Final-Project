#include "screen.h"
#include <stdio.h>
#include <iostream>
#include <board.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

/**
 * @brief Displays the main menu for the Car Race Game.
 *
 * This function clears the screen, sets the text color to green,
 * and prints the main menu centered on the screen. It prompts the user
 * to enter their name and stores it in the 'Name' member variable.
 *
 * @param None
 * @return void
 */
void Screen::nameEntryMenu()
{
    Board board;
    system("Color 0A"); // Set text color to green
    system("cls");      // Clear the screen

    const std::vector<string> menuLines = {
        "-----------------------------",
        "|        Car Race Game        |",
        "-----------------------------",
        " ",
        "ENTER THE PLAYER'S NAME: "};

    // Print each line of the menu at the appropriate position
    for (size_t i = 0; i < menuLines.size(); ++i)
    {
        board.setCursorPosition(board.calculateCenterOffset(menuLines[i]), static_cast<int>(i) + 4);
        cout << menuLines[i];
        if (i < menuLines.size() - 1)
        {
            cout << endl;
        }
    }
    getline(cin, playerName); // storing the user’s name
}

/**
 * @brief Displays the secondary menu for the Car Race Game.
 *
 * This function clears the screen, sets the text color to green,
 * and prints the secondary menu centered on the screen. It prompts the user
 * to select an option and stores the choice in the 'option' member variable.
 *
 * @param None
 * @return void
 */
void Screen::displayMenu()
{
    Board board;
    system("Color 0A"); // Set text color to green
    system("cls");      // Clear the screen

    const vector<string> menuItems = {
        "-----------------------------",
        "|        Car Race Game        |",
        "-----------------------------",
        "1. Start Game",
        "2. Instructions",
        "3. Leaderboard",
        "4. Quit",
        " ",
        "Select option:"};

    while (true)
    {
        // Print each line of the menu at the appropriate position
        for (size_t i = 0; i < menuItems.size(); ++i)
        {
            board.setCursorPosition(board.calculateCenterOffset(menuItems[i]), static_cast<int>(i) + 4);
            cout << menuItems[i];
            if (i < menuItems.size() - 1)
            {
                cout << endl;
            }
        }

        cin >> menuOption; // Store the user’s option

        // Validate input
        if (menuOption >= 1 && menuOption <= 4)
        {
            system("cls"); // Clear the screen
            break;         // Exit the loop if input is valid
        }
        else
        {
            cout << "Invalid option. Please select a valid option (1-4)." << endl;
            system("cls"); // Clear the screen for re-display
        }
    }
}

/**
 * @brief Displays the selectedLevel selection menu for the Car Race Game.
 *
 * This function clears the screen, sets the text color to green,
 * and prints the selectedLevel selection menu centered on the screen. It prompts the user
 * to select a difficulty selectedLevel and stores the choice in the 'selectedLevel' member variable.
 *
 * @param None
 * @return void
 */
void Screen::levelSelection()
{
    Board board;
    system("Color 0A"); // Set text color to green
    system("cls");      // Clear the screen

    const vector<string> menuLines = {
        "-----------------------------",
        "|        Car Race Game        |",
        "-----------------------------",
        "1. EASY MODE",
        "2. MEDIUM MODE",
        "3. HARD MODE",
        " ",
        "Select option:"};

    while (true)
    {
        // Print each line of the menu at the appropriate position
        for (size_t i = 0; i < menuLines.size(); ++i)
        {
            board.setCursorPosition(board.calculateCenterOffset(menuLines[i]), static_cast<int>(i) + 4);
            cout << menuLines[i];
            if (i < menuLines.size() - 1)
            {
                cout << endl;
            }
        }

        cin >> selectedLevel; // Store the user’s selected selectedLevel

        // Validate input
        if (selectedLevel >= 1 && selectedLevel <= 3)
        {
            system("cls"); // Clear the screen
            break;         // Exit the loop if input is valid
        }
        else
        {
            cout << "Invalid selectedLevel. Please select a valid selectedLevel (1-3)." << endl;
            system("cls"); // Clear the screen for re-display
        }
    }
}

/**
 * @brief Displays the Game Over screen.
 *
 * This function clears the screen, changes the text color to red, and displays
 * the Game Over message, player's name, score, and time played. It then waits
 * for the user to press a key before continuing.
 *
 * @param None
 * @return void
 */
void Screen::gameOver()
{
    Board board;
    time_t endTime = time(0); // Record the end time of the game
    string gameOverText, playerNameText;

    board.setTextColor(12); // Set text color to red

    // Display the Game Over header
    const vector<string> headerLines = {
        "-----------------------",
        "|        GAME OVER        |",
        "-----------------------"};

    for (size_t i = 0; i < headerLines.size(); ++i)
    {
        board.setCursorPosition(board.calculateCenterOffset(headerLines[i]), static_cast<int>(i) + 4);
        cout << headerLines[i] << endl;
    }

    board.setTextColor(10); // Set text color to green

    // Display player's name
    gameOverText = "PLAYER'S NAME: ";
    playerNameText = playerName;
    int playerNameOffset = (SCREEN_WIDTH - (gameOverText.size() + playerNameText.size())) / 2;
    board.setCursorPosition(playerNameOffset, 10);
    cout << gameOverText << playerNameText << endl;

    // Display score and time played
    gameOverText = "SCORE ==> ";
    board.setCursorPosition(board.calculateCenterOffset(gameOverText), 12);
    cout << gameOverText << currentScore << endl;

    gameOverText = "PLAYED TIME ==> ";
    board.setCursorPosition(board.calculateCenterOffset(gameOverText), 14);
    cout << gameOverText << timeDifference << " sec" << endl;

    // Prompt user to continue
    gameOverText = "PRESS ANY KEY AND ENTER TO CONTINUE";
    board.setCursorPosition(board.calculateCenterOffset(gameOverText), 17);
    cout << gameOverText;

    char dummyChar;
    cin >> dummyChar; // Wait for user input
    fflush(stdin);    // Clear input buffer
}

/**
 * @brief Displays the instructions page for the Car Race Game.
 *
 * This function changes the text color to green and displays the instructions
 * for playing the game. It provides information on how to move and exit the game.
 *
 * @param None
 * @return void
 */
void Screen::displayInstructions()
{
    Board board;
    system("Color 0A"); // Set text color to green

    const vector<string> instructions = {
        "----------------------------",
        "|        Instructions        |",
        "----------------------------",
        "Avoid Cars by moving left or right",
        "Press 'A' or '<==' to move left",
        "Press 'D' or '==>' to move right",
        "Press 'Esc' to exit",
        "Press any key to go back to menu"};

    // Print each line of instructions at the appropriate position
    for (size_t i = 0; i < instructions.size(); ++i)
    {
        board.setCursorPosition(board.calculateCenterOffset(instructions[i]), static_cast<int>(i) + 4);
        cout << instructions[i] << endl;
    }
}
