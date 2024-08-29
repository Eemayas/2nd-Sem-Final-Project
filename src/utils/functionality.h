#ifndef _FUNCTIONALITY_H_
#define _FUNCTIONALITY_H_

#include <fstream> // For file stream operations

class Functionality
{
public:
    int testscore;              ///< The score achieved in the current game session.
    int highest[3] = {0, 0, 0}; ///< Array to store the top 3 highest scores, initialized to 0.
    /**
     * @brief Updates and displays the current score on the main screen.
     *
     * This function sets the cursor position to a predefined location on the
     * main screen, sets the text color, and prints the current score.
     */
    void updateScore();
    /**
     * @brief Checks for a collision between an enemy car and the player's car.
     *
     * This function determines if there is a collision based on the position of
     * the enemy car and the player's car. It returns `true` if a collision is detected,
     * otherwise `false`.
     *
     * @param enemyIndex The index of the enemy car to check for collision.
     * @return true if a collision occurs, false otherwise.
     */
    bool checkCollision(int enemyIndex);

    /**
     * @brief Resets the position of the specified enemy and regenerates its coordinates.
     *
     * This function erases the specified enemy from its current position and sets
     * a new position for the enemy by updating its coordinates. The enemy is then
     * regenerated at the new position.
     *
     * @param enemyIndex The index of the enemy to reset.
     */
    void resetEnemy(int enemyIndex);

    /**
     * @brief Moves the enemy cars downwards and handles user input for car movement.
     *
     * This function moves the enemy cars down the screen based on the provided speed.
     * It also processes user input to move the player's car left or right and updates
     * the score when an enemy reaches the bottom of the screen.
     *
     * @param enemyIndex The index of the enemy car to move.
     * @param sleep Duration in milliseconds to control the speed of the enemy movement.
     * @param scoreIncrement The amount to increase the score when an enemy reaches the bottom.
     */
    void moveEnemiesDown(int enemyIndex, int sleep, int scoreIncrement);

    /**
     * @brief Updates the leaderboard by recording the highest scores and their corresponding details.
     *
     * This function reads the current leaderboard from a CSV file, updates it with new score data,
     * and writes the updated leaderboard back to the file. It maintains only the top three scores.
     *
     * @param newName The name associated with the new score.
     * @param newTime The time associated with the new score, converted to a string.
     * @param newScore The new score to be added to the leaderboard.
     */
    void updateLeaderboard();

    /**
     * @brief Displays the leaderboard page with the top scores.
     *
     * This function reads the leaderboard data from a CSV file and prints it on the screen.
     * It displays the top three scores along with the names and times associated with those scores.
     * The display is centered on the terminal and uses a green text color.
     *
     * @return void
     */
    void displayLeaderboard();

    // TODO: refracting
    /**
     * @brief Displays a countdown from 3 to 1 before the game starts.
     *
     * This function displays the numbers 3, 2, and 1 in sequence, each for a short duration.
     * The numbers are centered on the screen and are erased after being displayed.
     *
     * @return void
     */
    void displayCountdown();

    /**
     * @brief Function to play the actual game.
     *
     * This function manages the game loop, including initializing the game state,
     * handling enemy movements, checking for collisions, and updating scores.
     * It also manages game speed based on the player's score and handles game over
     * scenarios by updating the leaderboard and saving the score.
     *
     * @param initialSpeed Integer to set the initial speed of the enemies.
     * @param scoreIncrement Integer representing the score increment for different levels.
     * @param speedFactor Integer used to adjust the speed of enemies.
     * @return void
     */
    void play(int initialSpeed, int scoreIncrement, int speedFactor);

private:
    std::ofstream fout;  ///< Output file stream for saving game results.
    std::ofstream fout1; ///< Output file stream for another purpose, if needed.
};

#endif // _FUNCTIONALITY_H_
