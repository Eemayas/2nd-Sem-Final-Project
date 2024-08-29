#ifndef BOARD_H
#define BOARD_H

#include "global.h"
#include <wtypes.h>
#include <string>

using std::string;

/**
 * @class Board
 * @brief Manages console display and interface for the Car Race Game.
 *
 * This class handles various aspects of the console display including cursor positioning,
 * text color changes, and drawing borders. It also provides functionality to display
 * instructions and the current time.
 */
class Board
{
public:
    /**
     * @brief Console handle for output operations.
     */
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    /**
     * @brief Cursor position structure.
     */
    COORD cursor;

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
    void setCursorPosition(int x, int y);

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
    void setTextColor(int colorCode);

    /**
     * @brief Calculates the number of leading spaces needed to center text.
     *
     * This function computes the number of spaces required to center a given
     * string `text` within a console width defined by `SCREEN_WIDTH`. The number of
     * leading spaces is returned to position the text in the center.
     *
     * @param text The string to be centered.
     * @return int The number of leading spaces needed to center the text.
     */
    int calculateCenterOffset(const std::string &text) const;

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
    void printClock();

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
    void drawBorder();

    /**
     * @brief Displays instructions on the side of the main screen.
     *
     * This function sets the cursor position and prints instructional text on the side
     * of the main screen. The instructions guide the user on how to interact with the game.
     *
     * @param None
     * @return void
     */
    void displaySideInstructions();
};

#endif // BOARD_H
