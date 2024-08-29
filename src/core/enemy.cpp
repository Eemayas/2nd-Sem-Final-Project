
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
    enemyX[enemyIndex] = 17 + s % 33; // Set random x coordinate on the game board
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

    if (flag[enemyIndex] == 1)
    {
        board.setCursorPosition(enemyX[enemyIndex], enemyY[enemyIndex]);
        cout << block3 << "**" << block3;
        board.setCursorPosition(enemyX[enemyIndex], enemyY[enemyIndex] + 1);
        cout << " ** ";
        board.setCursorPosition(enemyX[enemyIndex], enemyY[enemyIndex] + 2);
        cout << block3 << "**" << block3;
        board.setCursorPosition(enemyX[enemyIndex], enemyY[enemyIndex] + 3);
        cout << " " << block2 << block2 << " ";
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
    if (flag[enemyIndex] == true)
    {
        board.setCursorPosition(enemyX[enemyIndex], enemyY[enemyIndex]);
        cout << "    ";
        board.setCursorPosition(enemyX[enemyIndex], enemyY[enemyIndex] + 1);
        cout << "    ";
        board.setCursorPosition(enemyX[enemyIndex], enemyY[enemyIndex] + 2);
        cout << "    ";
        board.setCursorPosition(enemyX[enemyIndex], enemyY[enemyIndex] + 3);
        cout << "    ";
    }
}
