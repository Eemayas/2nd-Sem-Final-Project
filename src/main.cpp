// including required header files
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <cmath>
#include "board.h"
#include "screen.h"
#include "player.h"
#include "enemy.h"
#include "game_logic.h"
#include "leaderboard_manager.h"

using namespace std;

int main()
{
    Board board;
    Player player;
    Enemy enemy;
    Screen screen;
    GameLogic functionality;
    LeaderboardManager leaderboardManager;
    screen.nameEntryMenu(); // calling the function ‘menu1’ from ‘parent’ class

    system("cls"); // clearing the whole window

    // creating do-while loop for starting the game
    do
    {

        screen.displayMenu(); // calling the function ‘menu2’ from’parent’ class

        // using switch() according to the passed value
        switch (menuOption)
        {
            // executing if option is ‘1’
        case 1:
            screen.levelSelection(); // calling a function ‘play’’ from class ‘modee‘

            // using switch() according to the passed value
            switch (selectedLevel)
            {
            // executing if option is ‘1’
            case 1:
                functionality.play(80, 1, 1); // calling a function ‘play’ from class ‘modee’
                break;
            // executing if option is ‘2’
            case 2:
                functionality.play(40, 2, 2); // calling a function ‘play’ from class ‘modee’
                break;
            // executing if option is ‘3’
            case 3:
                functionality.play(20, 3, 4); // calling a function ‘play’ from class ‘modee’

                break;
            }
            break;

            // executing if option is ‘2’
        case 2:
            screen.displayInstructions(); // calling the function ‘instruction’ from ’parent’ class
            std::cin.get();
            std::cin.get();
            break;

            // executing if option is ‘3’
        case 3:
            leaderboardManager.displayLeaderboard(); // calling the function ‘leaderboard’’ from ’parent’ class
            std::cin.get();
            std::cin.get();
            break;

            // executing if option is ‘4’
        case 4:
            exit(1); // exiting the program
            break;
        default:
            break;
        }
    } while (1);

    return 0;
}
