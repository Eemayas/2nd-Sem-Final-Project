#include "player.h"
#include <board.h>
#include <iostream>
#include <conio.h>

using namespace std;
/**
 * @brief Function to print the main car on the board.
 *
 * This function uses a for loop to print the appearance of the car on the board.
 *
 * @return void
 */
void Player::printCar()
{
    Board board;
    board.setTextColor(10);

    // Using nested for loops to iterate over the car array and print each character on the board
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            board.setCursorPosition(playerXPosition + i, j + playerInitialY);
            cout << carDesign[i][j];
        }
    }
}

/**
 * @brief Function to erase the printed car from the board.
 *
 * This function uses a for loop to erase the appearance of the car from the board.
 *
 * @return void
 */
void Player::eraseCar()
{
    Board board;
    // Using nested for loops to iterate over the car array and erase each character from the board
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            board.setCursorPosition(playerXPosition + i, j + playerInitialY);
            cout << " ";
        }
    }
}

/**
 * @brief Handles the player's car movement based on user input.
 *
 * This function checks for user input and moves the player's car left or right
 * on the screen based on the key pressed. The car moves within the boundaries
 * of the game screen.
 *
 * @param player Reference to the Player object representing the car.
 * @return void
 */
void Player::playerMovement(Player &player)
{
    // Check if a key has been pressed
    if (kbhit())
    {
        char userInput = getch(); // Get the pressed key

        // Move left if 'a', 'A', or the left arrow key is pressed
        if (userInput == 'a' || userInput == 'A' || userInput == 75)
        {
            if (playerXPosition > 19) // Ensure the car doesn't move out of bounds
            {
                player.eraseCar();    // Erase the car from its current position
                playerXPosition -= 4; // Move the car to the left
                player.printCar();    // Reprint the car at the new position
            }
        }
        // Move right if 'd', 'D', or the right arrow key is pressed
        else if (userInput == 'd' || userInput == 'D' || userInput == 77)
        {
            if (playerXPosition < 50) // Ensure the car doesn't move out of bounds
            {
                player.eraseCar();    // Erase the car from its current position
                playerXPosition += 4; // Move the car to the right
                player.printCar();    // Reprint the car at the new position
            }
        }
    }
}
