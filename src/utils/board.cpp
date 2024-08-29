#include "board.h"
#include <windows.h>
#include <iostream>
using namespace std;

/**
 * @brief Sets the console cursor position to the specified coordinates.
 *
 * This function updates the cursor's position in the console window
 * to the given x and y coordinates. It uses the Windows API function
 * `SetConsoleCursorPosition` to move the cursor.
 *
 * @param x The x-coordinate (horizontal position) of the cursor.
 * @param y The y-coordinate (vertical position) of the cursor.
 * @return void
 */
void Board::setCursorPosition(int x, int y)
{
    COORD position = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(console, position);
}

/**
 * @brief Sets the text color for the console output.
 *
 * This function changes the color of the text displayed in the console
 * by using the Windows API function `SetConsoleTextAttribute`. The color
 * attribute is specified by the parameter `colorCode`.
 *
 * @param colorCode The color code to set for the text. This should be a
 *                  valid console text attribute value.
 * @return void
 */
void Board::setTextColor(int colorCode)
{
    SetConsoleTextAttribute(console, colorCode);
}

/**
 * @brief Calculates the number of leading spaces needed to center text.
 *
 * This function computes the number of spaces required to center a given
 * string `text` within a console width defined by `WIDTH`. The number of
 * leading spaces is returned to position the text in the center.
 *
 * @param text The string to be centered.
 * @return int The number of leading spaces needed to center the text.
 */
int Board::calculateCenterOffset(const std::string &text) const
{
    int textWidth = static_cast<int>(text.size());
    int offset = (WIDTH - textWidth) / 2;
    return offset;
}

// TODO: Shift this to functionalities
/**
 * @brief Retrieves the current local time as a string.
 *
 * This function obtains the current local time and returns it as a
 * string in a human-readable format. The time is formatted according
 * to the system's locale and returned as a character array.
 *
 * @return char* A string representing the current local time.
 */
char *Board::getCurrentTime()
{
    time_t rawTime;
    struct tm *localTime;

    time(&rawTime);                  // Get the current time
    localTime = localtime(&rawTime); // Convert to local time structure

    return asctime(localTime); // Convert to string and return
}

/**
 * @brief Displays the current time in 12-hour format on the screen.
 *
 * This function retrieves the current local time, formats it in 12-hour
 * format with "AM" or "PM" indicators, and prints it to the screen. It
 * updates the displayed time only if a second has elapsed since the last
 * update to minimize redundant prints.
 *
 * @param None
 * @return void
 */
void Board::printClock()
{
    // Retrieve the current time
    time_t currentTime = time(0);
    struct tm *timeStruct = localtime(&currentTime);

    // Convert to 12-hour format
    string period = (timeStruct->tm_hour >= 12) ? "PM" : "AM";
    int hour = (timeStruct->tm_hour > 12) ? timeStruct->tm_hour - 12 : timeStruct->tm_hour;
    hour = (hour == 0) ? 12 : hour; // Adjust hour to 12 if it's zero

    // Print the formatted time if a second has elapsed
    if (timeStruct->tm_sec == sec_prev + 1 || (sec_prev == 59 && timeStruct->tm_sec == 0))
    {
        setTextColor(10);                       // Set text color
        setCursorPosition(MAIN_SCREEN + 6, 19); // Position cursor
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (timeStruct->tm_min < 10 ? "0" : "") << timeStruct->tm_min << ":"
             << (timeStruct->tm_sec < 10 ? "0" : "") << timeStruct->tm_sec << " "
             << period;
    }

    sec_prev = timeStruct->tm_sec; // Update previous second
}

/**
 * @brief Draws the border around the main screen.
 *
 * This function sets the text color to green, clears the screen, and then draws
 * a border around the main screen using different characters for different
 * parts of the border. The border is drawn along the top, bottom, and sides
 * of the main screen area.
 *
 * @param None
 * @return void
 */
void Board::drawBorder()
{
    system("Color 0A"); // Set text color to green

    // Draw the vertical lines on the left and right sides of the screen
    for (int y = 0; y < HEIGHT; ++y)
    {
        setCursorPosition(16, y); // Position cursor for left border
        cout << line2;
        setCursorPosition(54, y); // Position cursor for right border
        cout << line2;

        // Draw the horizontal lines on the top and bottom of the main screen
        for (int x = 0; x < 16; ++x)
        {
            setCursorPosition(x, y); // Position cursor for the top-left corner
            cout << block1;
            setCursorPosition(MAIN_SCREEN - x, y); // Position cursor for the top-right corner
            cout << block1;
        }

        // Draw the bottom border lines
        setCursorPosition(WIDTH, y);
        cout << block << block2 << block1;
    }

    // Draw the bottom border line
    for (int x = 0; x < WIDTH; ++x)
    {
        setCursorPosition(x, HEIGHT + 1); // Position cursor for the bottom border
        cout << line;
    }
}

/**
 * @brief Displays instructions on the side of the main screen.
 *
 * This function sets the cursor position and prints instructional text on the side
 * of the main screen. The instructions guide the user on how to interact with the game.
 *
 * @param None
 * @return void
 */
void Board::displaySideInstructions()
{
    // Set cursor position and print border lines
    setCursorPosition(MAIN_SCREEN + 5, 4);
    cout << "-----------";
    setCursorPosition(MAIN_SCREEN + 5, 6);
    cout << "------------";
    setCursorPosition(MAIN_SCREEN + 5, 10);
    cout << "---------------";

    // Print the instruction header
    setCursorPosition(MAIN_SCREEN + 7, 11);
    cout << "INSTRUCTION";

    // Print the border line below the header
    setCursorPosition(MAIN_SCREEN + 5, 12);
    cout << "---------------";

    // Print instruction details
    setCursorPosition(MAIN_SCREEN + 5, 13);
    cout << "PRESS:";
    setCursorPosition(MAIN_SCREEN + 5, 14);
    cout << "A or <-- for left";
    setCursorPosition(MAIN_SCREEN + 5, 15);
    cout << "D or --> for right";

    // Print border lines at the bottom
    setCursorPosition(MAIN_SCREEN + 5, 16);
    cout << "------------------";
    setCursorPosition(MAIN_SCREEN + 5, 18);
    cout << "-------------";
    setCursorPosition(MAIN_SCREEN + 5, 20);
    cout << "-------------";
}
