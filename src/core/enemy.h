#ifndef _ENEMY_H_
#define _ENEMY_H_

/**
 * @file enemy.h
 * @brief Defines the Enemy class, which represents an enemy in the game.
 */

/**
 * @class Enemy
 * @brief Represents an enemy in the game.
 */
class Enemy
{
public:
    /**
     * @brief Generates the x coordinate for generating the enemy car.
     *
     * This function generates a random x coordinate within a specified range
     * for placing the enemy car on the game board.
     *
     * @param enemyIndex The index of the enemy car.
     */
    void genEnemy(int enemyIndex);

    /**
     * @brief Prints the enemy car on the game board.
     *
     * This function prints the enemy car on the game board at the specified coordinates.
     *
     * @param enemyIndex The index of the enemy car.
     */
    void printEnemy(int enemyIndex);

    /**
     * @brief Erases the printed enemy car from the game board.
     *
     * This function erases the printed enemy car from the game board at the specified coordinates.
     *
     * @param enemyIndex The index of the enemy car.
     */
    void eraseEnemy(int enemyIndex);

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
    void enemyMovement(Enemy &enemy, int enemyIndex, int sleep);

    /**
     * @brief Resets the position of the specified enemy and regenerates its coordinates.
     *
     * This function erases the specified enemy from its current position and sets
     * a new position for the enemy by updating its coordinates. The enemy is then
     * regenerated at the new position.
     *
     * @param enemyIndex The index of the enemy to reset.
     */
    void resetEnemy(int enemyIndex);
};

#endif
