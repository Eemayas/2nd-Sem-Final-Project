#ifndef _TIMER_H_
#define _TIMER_H_

#include <fstream> // For file stream operations

class Timer
{
public:
    /**
     * @brief Retrieves the current local time as a string.
     *
     * This function obtains the current local time and returns it as a
     * string in a human-readable format. The time is formatted according
     * to the system's locale and returned as a character array.
     *
     * @return char* A string representing the current local time.
     */
    char *getCurrentTime();

    /**
     * @brief Displays a countdown from 3 to 1 before the game starts.
     *
     * This function displays the numbers 3, 2, and 1 in sequence, each for a short duration.
     * The numbers are centered on the screen and are erased after being displayed.
     *
     * @return void
     */
    void displayCountdown();
};

#endif // _TIMER_H_
