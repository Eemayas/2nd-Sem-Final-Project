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
};

#endif
