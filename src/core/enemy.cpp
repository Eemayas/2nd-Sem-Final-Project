
#include "enemy.h"
#include "board.h"
#include <iostream>
using namespace std;

/**
 * @brief Generates the x coordinate for generating the enemy car.
 *
 * This function generates a random x coordinate within a specified range
 * for placing the enemy car on the game board.
 *
 * @param enemyIndex The index of the enemy car.
 */
void Enemy::genEnemy(int enemyIndex)
{
    int s = rand();
    enemyXCoordinates[enemyIndex] = 17 + s % 33; // Set random x coordinate on the game board
}

/**
 * @brief Prints the enemy car on the game board.
 *
 * This function prints the enemy car on the game board at the specified coordinates.
 *
 * @param enemyIndex The index of the enemy car.
 */
void Enemy::printEnemy(int enemyIndex)
{
    Board board;
    board.setTextColor(12);

    if (enemyGenerationFlags[enemyIndex] == 1)
    {
        board.setCursorPosition(enemyXCoordinates[enemyIndex], enemyYCoordinates[enemyIndex]);
        cout << SHADE_DARK << "**" << SHADE_DARK;
        board.setCursorPosition(enemyXCoordinates[enemyIndex], enemyYCoordinates[enemyIndex] + 1);
        cout << " ** ";
        board.setCursorPosition(enemyXCoordinates[enemyIndex], enemyYCoordinates[enemyIndex] + 2);
        cout << SHADE_DARK << "**" << SHADE_DARK;
        board.setCursorPosition(enemyXCoordinates[enemyIndex], enemyYCoordinates[enemyIndex] + 3);
        cout << " " << SHADE_MEDIUM << SHADE_MEDIUM << " ";
    }
}

/**
 * @brief Erases the printed enemy car from the game board.
 *
 * This function erases the printed enemy car from the game board at the specified coordinates.
 *
 * @param enemyIndex The index of the enemy car.
 */
void Enemy::eraseEnemy(int enemyIndex)
{
    Board board;
    if (enemyGenerationFlags[enemyIndex] == true)
    {
        board.setCursorPosition(enemyXCoordinates[enemyIndex], enemyYCoordinates[enemyIndex]);
        cout << "    ";
        board.setCursorPosition(enemyXCoordinates[enemyIndex], enemyYCoordinates[enemyIndex] + 1);
        cout << "    ";
        board.setCursorPosition(enemyXCoordinates[enemyIndex], enemyYCoordinates[enemyIndex] + 2);
        cout << "    ";
        board.setCursorPosition(enemyXCoordinates[enemyIndex], enemyYCoordinates[enemyIndex] + 3);
        cout << "    ";
    }
}
/**
 * @brief Handles the movement of enemies in the game.
 *
 * This function controls the downward movement of the enemies on the screen.
 * It also manages the appearance of a second enemy when certain conditions are met.
 *
 * @param enemy Reference to the Enemy object representing the enemies.
 * @param enemyIndex Index of the enemy to move.
 * @param sleep Time in milliseconds to pause between movements, controlling the speed.
 * @return void
 */
void Enemy::enemyMovement(Enemy &enemy, int enemyIndex, int sleep)
{
    // Display the enemies on the screen
    enemy.printEnemy(enemyIndex);
    enemy.printEnemy(enemyIndex + 1);

    // Pause for a specified time to control the speed of enemy movement
    Sleep(sleep);

    // Erase the enemies from their current positions
    enemy.eraseEnemy(enemyIndex);
    enemy.eraseEnemy(enemyIndex + 1);

    // Check if the second enemy should appear and set the enemyGenerationFlags accordingly
    if (enemyYCoordinates[1] == 13 && enemyGenerationFlags[2] == 0)
    {
        enemyGenerationFlags[2] = 1; // Set enemyGenerationFlags to enable the second enemy
    }

    // Move the first enemy downwards if its enemyGenerationFlags is set
    if (enemyGenerationFlags[enemyIndex] == 1)
    {
        enemyYCoordinates[enemyIndex] += 1;
    }
    // Move the second enemy downwards if its enemyGenerationFlags is set
    if (enemyGenerationFlags[enemyIndex + 1] == 1)
    {
        enemyYCoordinates[enemyIndex + 1] += 1;
    }
}

/**
 * @brief Resets the position of the specified enemy and regenerates its coordinates.
 *
 * This function erases the specified enemy from its current position and sets
 * a new position for the enemy by updating its coordinates. The enemy is then
 * regenerated at the new position.
 *
 * @param enemyIndex The index of the enemy to reset.
 */
void Enemy::resetEnemy(int enemyIndex)
{
    Enemy enemy;

    enemy.eraseEnemy(enemyIndex);      // Remove the enemy from the screen
    enemyYCoordinates[enemyIndex] = 1; // Reset the enemy's Y-coordinate to the initial position
    enemy.genEnemy(enemyIndex);        // Generate new coordinates for the enemy
}