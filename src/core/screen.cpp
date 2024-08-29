#include "screen.h"
#include <stdio.h>
#include <iostream>
#include <board.h>

/**defining function
 *@brief function to print main menu1 at the start
 *@param text_1 string to save certain texts as required
 * @return void
 */
void Screen::menu1()
{
    Board board;
    system("Color 0A"); // changes the text color to green
    system("cls");      // clearing the whole screen

    // printing the text in the center of the main screen
    string text_1 = "-----------------------------";
    position(board.center(text_1), 4); // calling the position() function
    cout << text_1;
    text_1 = "|        Car Race Game        |";
    position(board.center(text_1), 5);
    cout << text_1;
    text_1 = "-----------------------------";
    position(board.center(text_1), 6);
    cout << text_1;
    text_1 = "ENTER THE PLAYER'S NAME:";
    position(board.center(text_1), 10);
    cout << text_1;
    getline(cin, Name); // storing the user’s name
}

/**defining function
 *@brief function to print menu 2
 *@param text_1 string to save certain texts as required
 * @return void
 */

void Screen::menu2()
{
    Board board;
    system("Color 0A"); // changes the text color to green
    system("cls");      // clearing the whole screen

    // printing the text in the center of the main screen
    string text_1 = "-----------------------------";
    position(board.center(text_1), 4);
    cout << text_1;
    text_1 = "|        Car Race Game        |";
    position(board.center(text_1), 5);
    cout << text_1;
    text_1 = "-----------------------------";
    position(board.center(text_1), 6);
    cout << text_1;
    text_1 = "1. Start Game";
    position(board.center(text_1), 10);
    cout << text_1;
    text_1 = "2. Instructions";
    position(board.center(text_1), 12);
    cout << text_1;
    text_1 = "3. Leaderboard";
    position(board.center(text_1), 14);
    cout << text_1;
    text_1 = "4. Quit";
    position(board.center(text_1), 16);
    cout << text_1;
    text_1 = "Select option:";
    position(board.center(text_1), 18);
    cout << text_1;
    cin >> option; // stores the user’s option
    system("cls"); // clearing the whole screen
}

void Screen::levelSelection()
{
    Board board;
    system("Color 0A");
    system("cls");
    string text_1 = "-----------------------------";
    position(board.center(text_1), 4); // calling the position() function to align at the center
    cout << text_1;
    text_1 = "|        Car Race Game        |";
    position(board.center(text_1), 5);
    cout << text_1;
    text_1 = "-----------------------------";
    position(board.center(text_1), 6);
    cout << text_1;
    text_1 = "1.EASY  MODE";
    position(board.center(text_1), 10);
    cout << text_1;
    text_1 = "2. MEDIUM MODE";
    position(board.center(text_1), 12);
    cout << text_1;
    text_1 = "3.HARD MODE";
    position(board.center(text_1), 14);
    cout << text_1;
    text_1 = "Select option:";
    position(board.center(text_1), 16);
    cout << text_1;
    cin >> level; // take the user input option to set the level
    system("cls");
}

/**defining function
 *@brief function to print Game Over page
 *@param text_2 string to save certain texts as required
 *@param text_3 string to save certain texts as required
 *@param text_2_length int data type to save the size of the text entered
 *@param text_3_length int data type to save the size of the text entered
 *@param end variable to save the game over time
 *@return void
 */

void Screen::game_Over()
{
    Board board;
    time_t end = time(0);
    string text_2, text_3;

    board.color(12); // calling the color function to change the color to red

    // printing the text in the center of the main screen
    text_2 = "-----------------------";
    position(board.center(text_2), 4);
    cout << text_2;
    text_2 = "|        GAME OVER        |";
    position(board.center(text_2), 5);
    cout << text_2;
    text_2 = "-----------------------";
    position(board.center(text_2), 6);
    cout << text_2;

    board.color(10); // calling the color function

    text_2 = "PLAYER'S NAME: ";
    text_3 = Name;

    // defining the variable to save the length of text_2 and name
    int text_2_length = text_2.size();
    int text_3_length = Name.size();

    // to align the text at the center
    int text_length = (WIDTH - (text_2_length + text_3_length)) / 2;
    position(text_length, 10);

    // printing the text
    cout << text_2;
    cout << text_3;

    text_2 = "SCORE ==> ";
    position(board.center(text_2), 12);
    cout << text_2 << score;
    text_2 = "PLAYED TIME ==> ";
    position(board.center(text_2), 14);
    cout << text_2;
    cout << diff << " sec";

    text_2 = "PRESS ANY KEY AND ENTER TO CONTINUE";
    position(board.center(text_2), 17);
    cout << text_2;
    char c;
    cin >> c;
    fflush(stdin);
}

/**defining function
 *@brief function to print Instruction page
 *@param text_1 string to save certain texts as required
 *@return void
 */

void Screen::instruction()
{
    Board board;
    system("Color 0A"); // change the text color to green
    string text1 = "----------------------------";
    position(board.center(text1), 4);
    cout << text1;
    text1 = "|        Instructions        |";
    position(board.center(text1), 5);
    cout << text1;
    text1 = "----------------------------";
    position(board.center(text1), 6);
    cout << text1;
    text1 = "Avoid Cars by moving left or right ";
    position(board.center(text1), 9);
    cout << text1;
    text1 = "Press 'A' or '<==' to move left";
    position(board.center(text1), 11);
    cout << text1;
    text1 = "Press 'D' or '==>' to move right";
    position(board.center(text1), 13);
    cout << text1;
    text1 = "Press 'Esc' to exit";
    position(board.center(text1), 15);
    cout << text1;
    text1 = "Press any key to go back to menu";
    position(board.center(text1), 19);
    cout << text1;
}
