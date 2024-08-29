#include "board.h"
#include "timer.h"
#include <windows.h>
#include <iostream>
using namespace std;
/**
 * @brief Retrieves the current local time as a string.
 *
 * This function obtains the current local time and returns it as a
 * string in a human-readable format. The time is formatted according
 * to the system's locale and returned as a character array.
 *
 * @return char* A string representing the current local time.
 */
char *Timer::getCurrentTime()
{
    time_t rawTime;
    struct tm *localTime;

    time(&rawTime);                  // Get the current time
    localTime = localtime(&rawTime); // Convert to local time structure

    return asctime(localTime); // Convert to string and return
}

/**
 * @brief Displays a countdown from 3 to 1 before the game starts.
 *
 * This function displays the numbers 3, 2, and 1 in sequence, each for a short duration.
 * The numbers are centered on the screen and are erased after being displayed.
 *
 * @return void
 */
void Timer::displayCountdown()
{
    Board board;
    const int countdownDuration = 1; // Duration to display each number (in seconds)
    const int numSize = 6;           // Size of the numbers 1 and 2
    const int largerNumSize = 7;     // Size of the number 3

    // Display and erase the number '1'
    for (int y = 0; y < numSize; y++)
    {
        for (int x = 0; x < numSize; x++)
        {
            board.setCursorPosition(PLAY_AREA_WIDTH / 2 + x - 3, SCREEN_HEIGHT / 2 + y - 3);
            std::cout << digitOne[y][x]; // Display '1'
        }
    }
    Sleep(countdownDuration);
    for (int y = 0; y < numSize; y++)
    {
        for (int x = 0; x < numSize; x++)
        {
            board.setCursorPosition(PLAY_AREA_WIDTH / 2 + x - 3, SCREEN_HEIGHT / 2 + y - 3);
            std::cout << " "; // Erase '1'
        }
    }

    // Display and erase the number '2'
    for (int y = 0; y < numSize; y++)
    {
        for (int x = 0; x < numSize; x++)
        {
            board.setCursorPosition(PLAY_AREA_WIDTH / 2 + x - 3, SCREEN_HEIGHT / 2 + y - 3);
            std::cout << digitTwo[y][x]; // Display '2'
        }
    }
    Sleep(countdownDuration);
    for (int y = 0; y < numSize; y++)
    {
        for (int x = 0; x < numSize; x++)
        {
            board.setCursorPosition(PLAY_AREA_WIDTH / 2 + x - 3, SCREEN_HEIGHT / 2 + y - 3);
            std::cout << " "; // Erase '2'
        }
    }

    // Display and erase the number '3'
    for (int y = 0; y < largerNumSize; y++)
    {
        for (int x = 0; x < largerNumSize; x++)
        {
            board.setCursorPosition(PLAY_AREA_WIDTH / 2 + x - 3, SCREEN_HEIGHT / 2 + y - 3);
            std::cout << digitThree[y][x]; // Display '3'
        }
    }
    Sleep(countdownDuration);
    for (int y = 0; y < largerNumSize; y++)
    {
        for (int x = 0; x < largerNumSize; x++)
        {
            board.setCursorPosition(PLAY_AREA_WIDTH / 2 + x - 3, SCREEN_HEIGHT / 2 + y - 3);
            std::cout << " "; // Erase '3'
        }
    }
}
