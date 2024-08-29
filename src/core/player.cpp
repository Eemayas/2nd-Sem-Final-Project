#include "player.h"
#include <board.h>
#include <iostream>
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
            board.setCursorPosition(carPosition + i, j + startcarY);
            cout << car[i][j];
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
            board.setCursorPosition(carPosition + i, j + startcarY);
            cout << " ";
        }
    }
}
