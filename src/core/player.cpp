#include "player.h"
#include <board.h>
#include <iostream>
using namespace std;
/**defining function
 *@brief function to print the main car
 *@return void
 */
void Player::print_Car()
{
    Board board;
    board.color(10);

    // using for loop to print the appearance of the car
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            position(carposition + i, j + startcarY);
            cout << car[i][j];
        }
    }
}

/**defining function
 *@brief function to erase the printed car
 *@return void
 */
void Player::erase_Car()
{
    // using for loop to erase the printed car
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            position(carposition + i, j + startcarY);
            cout << " ";
        }
    }
}
