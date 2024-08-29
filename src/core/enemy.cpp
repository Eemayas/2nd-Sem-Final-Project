
#include "enemy.h"
#include "board.h"
#include <iostream>
using namespace std;
/**defining function
 *@brief function to give the x coordinate for generating the enemy car
 *@return void
 */
void Enemy::gen_Enemy(int enemy_number)
{
    int s = rand();
    enemyX[enemy_number] = 17 + s % (33); // setting random position on the main field
}

/**defining function
 *@brief function to print the enemy car
 *@param flag[enemy_number] variable to check whether to print the next enemy car or not
 *@return void
 */
void Enemy::print_Enemy(int enemy_number)
{
    Board board;
    board.color(12);
    // if the condition is fulfilled then print the enemy
    if (flag[enemy_number] == 1)
    {
        position(enemyX[enemy_number], enemyY[enemy_number]);
        cout << block3 << "**" << block3;
        position(enemyX[enemy_number], enemyY[enemy_number] + 1);
        cout << " ** ";
        position(enemyX[enemy_number], enemyY[enemy_number] + 2);
        cout << block3 << "**" << block3;
        position(enemyX[enemy_number], enemyY[enemy_number] + 3);
        cout << " " << block2 << block2 << " ";
    }
}

/**defining function
 *@brief function to erase the printed enemy
 *@return void
 */

void Enemy::erase_Enemy(int enemy_number)
{
    if (flag[enemy_number] == true)
    {
        position(enemyX[enemy_number], enemyY[enemy_number]);
        cout << "    "; // x,1
        position(enemyX[enemy_number], enemyY[enemy_number] + 1);
        cout << "    "; // x,2
        position(enemyX[enemy_number], enemyY[enemy_number] + 2);
        cout << "    "; // x,3
        position(enemyX[enemy_number], enemyY[enemy_number] + 3);
        cout << "    "; // x,4
    }
}
