#ifndef _PLAYER_H_
#define _PLAYER_H_

// This header file defines the Player class, which represents a player in the game.

class Player
{
public:
    /**
     * @brief Function to print the main car on the board.
     *
     * This function uses a for loop to print the appearance of the car on the board.
     *
     * @return void
     */
    void printCar();

    /**
     * @brief Function to erase the printed car from the board.
     *
     * This function uses a for loop to erase the appearance of the car from the board.
     *
     * @return void
     */
    void eraseCar();

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
    void playerMovement(Player &player);
};

#endif
