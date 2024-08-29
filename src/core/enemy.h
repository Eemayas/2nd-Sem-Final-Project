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
};

#endif
