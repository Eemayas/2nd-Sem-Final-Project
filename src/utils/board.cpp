#include "board.h"
#include <windows.h>
#include <iostream>
using namespace std;

// function to point to the coordinates passed to the function
void Board::position(int x, int y)
{
    cursor.X = x;
    cursor.Y = y;
    SetConsoleCursorPosition(console, cursor);
}

/**defining function
 *@brief function to change the color of the text
 * @return void
 */
void Board::color(int i)
{
    SetConsoleTextAttribute(console, i);
}

/**defining function
 *@brief function to set the text in the center of the main screen
 * @return space
 */
int Board::center(string s)
{
    int spaces = (WIDTH - s.size()) / 2; // variable to store the center of width of the terminal
    return spaces;
}

/**defining function
 *@brief function to change the color of the text
 *@param tt variable to save local time
 * @return local time in character data type
 */

char *Board::timme()
{
    time_t t;
    struct tm *tt; // decalring variable for localtime()
    time(&t);      // passing argument to time()
    tt = localtime(&t);
    return asctime(tt);
}
/**defining function
 *@brief function to print the clock
 *@param seconds[a] array to save seconds
 *@param minutes[a] array to save minutes
 *@param hours[a] array to save hour
 *@param str string to save ‘AM’ or ‘PM’
 *@return void
 */

void Board::print_Clock(int a)
{

    int seconds[60], minutes[60], hours[24];
    string str;

    // storing total seconds passed
    time_t total_seconds = time(0);

    // getting values of seconds, minutes and hours
    struct tm *ct = localtime(&total_seconds);

    seconds[a] = ct->tm_sec;
    minutes[a] = ct->tm_min;
    hours[a] = ct->tm_hour;

    // converting it into 12 hour format
    if (hours[a] >= 12)
        str = "PM";
    else
        str = "AM";
    hours[a] = hours[a] > 12 ? hours[a] - 12 : hours[a];

    // printing the result
    color(10);
    if (seconds[a] == sec_prev + 1 || (sec_prev == 59 && seconds[a] == 0))
    {
        position(MAIN_SCREEN + 6, 19);
        cout << (hours[a] < 10 ? "0" : "") << hours[a] << ":" << (minutes[a] < 10 ? "0" : "") << minutes[a] << ":" << (seconds[a] < 10 ? "0" : "") << seconds[a] << " " << str;
    }

    sec_prev = seconds[a];
}

/**defining function
 *@brief function to print the border in the main scren
 *@return void
 */
void Board::draw_Border()
{
    system("Color 0A");

    // using for loop to print the border
    for (int j = 0; j < HEIGHT; j++)
    {
        position(16, j);
        cout << line2;
        position(54, j);
        cout << line2;
        for (int i = 0; i < 16; i++)
        {
            position(i, j);
            cout << block1;
            position(MAIN_SCREEN - i, j);
            cout << block1;
        }

        for (int j = 0; j < HEIGHT; j++)
        {
            position(WIDTH, j);
            cout << block << block2 << block1;
        }
    }
    for (int i = 0; i < WIDTH; i++)
    {
        position(i, HEIGHT + 1);
        cout << line;
    }
}

/**defining function
 *@brief function to print instruction at the side of the main screen
 *@return void
 */

void Board::side_Instruction()
{
    position(MAIN_SCREEN + 5, 4);
    cout << "-----------";
    position(MAIN_SCREEN + 5, 6);
    cout << "------------";
    position(MAIN_SCREEN + 5, 10);
    cout << "---------------";
    position(MAIN_SCREEN + 7, 11);
    cout << "INSTRUCTION";
    position(MAIN_SCREEN + 5, 12);
    cout << "---------------";
    position(MAIN_SCREEN + 5, 13);
    cout << "PRESS:";
    position(MAIN_SCREEN + 5, 14);
    cout << "A or <-- for left";
    position(MAIN_SCREEN + 5, 15);
    cout << "D or --> for right";
    position(MAIN_SCREEN + 5, 16);
    cout << "------------------";
    position(MAIN_SCREEN + 5, 18);
    cout << "-------------";
    position(MAIN_SCREEN + 5, 20);
    cout << "-------------";
}