#ifndef _GAMELOGIC_H_
#define _GAMELOGIC_H_

#include <fstream> // For file stream operations

class GameLogic
{
public:
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
     * @brief Moves the enemies and player, and updates the score if necessary.
     *
     * This function handles the movement of both enemies and the player. It checks if
     * any enemy has reached the bottom of the screen, resets its position, and increments
     * the score accordingly. The player's movement is also processed within this function.
     *
     * @param enemyIndex Index of the enemy to move.
     * @param sleep Time in milliseconds to pause between movements, controlling the speed of the enemies.
     * @param scoreIncrement Value by which the score is incremented when an enemy reaches the bottom.
     * @return void
     */
    void moveEnemiesPlayer(int enemyIndex, int sleep, int scoreIncrement);

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

#endif // _GAMELOGIC_H_
