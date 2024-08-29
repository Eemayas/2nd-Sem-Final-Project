#ifndef SCREEN_H
#define SCREEN_H

/**
 * @class Screen
 * @brief Handles the display and interaction for various screens in the Car Race Game.
 *
 * This class includes methods for displaying menus, instructions, and game-over screens.
 * It provides functionality to capture user inputs and show relevant information.
 */
class Screen
{
public:
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
    void nameEntryMenu();

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
    void displayMenu();

    /**
     * @brief Displays the level selection menu for the Car Race Game.
     *
     * This function clears the screen, sets the text color to green,
     * and prints the level selection menu centered on the screen. It prompts the user
     * to select a difficulty level and stores the choice in the 'level' member variable.
     *
     * @param None
     * @return void
     */
    void levelSelection();

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
    void gameOver();

    /**
     * @brief Displays the instructions page for the Car Race Game.
     *
     * This function changes the text color to green and displays the instructions
     * for playing the game. It provides information on how to move and exit the game.
     *
     * @param None
     * @return void
     */
    void displayInstructions();
};

#endif // SCREEN_H
