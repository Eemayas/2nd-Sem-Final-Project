#include "game_logic.h"
#include "global.h"
#include <iostream>
#include "board.h"
#include "enemy.h"
#include <conio.h>
#include "player.h"
#include <sstream>
#include "screen.h"
#include <fstream>
#include <string>
#include "leaderboard_manager.h"
#include "timer.h"

using std::getline;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;
using std::stringstream;

/**
 * @brief Updates and displays the current score on the main screen.
 *
 * This function sets the cursor position to a predefined location on the
 * main screen, sets the text color, and prints the current score.
 */
void GameLogic ::updateScore()
{
    const int cursorX = PLAY_AREA_WIDTH + 7;
    const int cursorY = 5;
    const int textColor = 10;

    Board board;
    board.setCursorPosition(cursorX, cursorY);
    board.setTextColor(textColor);

    std::cout << "Score: " << currentScore << std::endl; // Display the current score
}

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
bool GameLogic ::checkCollision(int enemyIndex)
{
    const int collisionThreshold = SCREEN_HEIGHT - 2;
    const int enemyWidth = 4;
    const int carWidth = 9;

    // Check if the enemy car is within the collision threshold
    if (enemyYCoordinates[enemyIndex] + enemyWidth >= collisionThreshold)
    {
        // Check if the enemy car's x position overlaps with the player's car
        if (enemyXCoordinates[enemyIndex] + enemyWidth > playerXPosition && enemyXCoordinates[enemyIndex] < playerXPosition + carWidth)
        {
            return true;
        }
    }

    return false;
}

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
void GameLogic ::moveEnemiesPlayer(int enemyIndex, int sleep, int scoreIncrement)
{
    Enemy enemy;
    Player player;

    // Move the enemies on the screen
    enemy.enemyMovement(enemy, enemyIndex, sleep);

    // Process player movement based on user input
    player.playerMovement(player);

    // Check if the first enemy has reached the bottom of the screen
    if (enemyYCoordinates[enemyIndex] > SCREEN_HEIGHT - 4)
    {
        enemy.resetEnemy(enemyIndex);   // Reset the position of the first enemy
        currentScore += scoreIncrement; // Increment the score
        updateScore();                  // Update the score display
    }

    // Check if the second enemy has reached the bottom of the screen
    if (enemyYCoordinates[enemyIndex + 1] > SCREEN_HEIGHT - 4)
    {
        enemy.resetEnemy(enemyIndex + 1); // Reset the position of the second enemy
        currentScore += scoreIncrement;   // Increment the score
        updateScore();                    // Update the score display
    }
}

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
void GameLogic ::play(int initialSpeed, int scoreIncrement, int speedFactor)
{
    Board board;
    Player player;
    Enemy enemy;
    Screen screen;
    LeaderboardManager leaderboardManager;
    Timer timer;

    // Initialize game state
    board.drawBorder();                              // Draw the game border
    updateScore();                                   // Display the current score
    board.displaySideInstructions();                 // Show instructions on the side
    enemyYCoordinates[1] = enemyYCoordinates[2] = 0; // Initialize enemy Y-coordinates
    player.printCar();                               // Display the player's car
    enemyGenerationFlags[1] = 1;                     // Set flags for enemies
    enemyGenerationFlags[2] = 0;
    enemy.genEnemy(1); // Generate the first enemy
    enemy.genEnemy(2); // Generate the second enemy

    time_t startTime = time(0);             // Record the start time
    gameStartTime = timer.getCurrentTime(); // Initialize current time

    static int currentSpeed = initialSpeed;
    Sleep(1);
    timer.displayCountdown(); // Display countdown before the game starts

    while (true)
    {
        board.printClock(); // Print the current game time

        // Adjust enemy speed based on the score
        if (currentScore <= 10)
        {
            moveEnemiesPlayer(1, currentSpeed, scoreIncrement); // Move enemies at initial speed
        }
        else if (currentScore > 10 && currentScore <= 50)
        {
            moveEnemiesPlayer(1, currentSpeed - (20 / speedFactor), scoreIncrement); // Increase speed
        }
        else if (currentScore > 50 && currentScore <= 100)
        {
            moveEnemiesPlayer(1, currentSpeed - (40 / speedFactor), scoreIncrement); // Further increase speed
        }

        int collisionStatus = checkCollision(1); // Check for collision with the first enemy
        if (checkCollision(1) || checkCollision(2))
        {
            system("cls");                        // Clear the screen
            time_t endTime = time(0);             // Record the end time
            timeDifference = endTime - startTime; // Calculate the duration of the game
            testScore = currentScore;             // Store the score for saving

            // Save the score to a file
            fout.open("PlayerList.csv", std::ios::app);
            fout << playerName << ",";         // Save the player's name
            fout << currentScore << std::endl; // Save the score
            fout.close();                      // Close the file

            screen.gameOver();                      // Display the game over screen
            leaderboardManager.updateLeaderboard(); // Update the leaderboard
            currentScore = 0;                       // Reset the score
            break;                                  // Exit the game loop
        }
    }
}
