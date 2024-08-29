#include "functionality.h"
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
void Functionality::updateScore()
{
    const int cursorX = MAIN_SCREEN + 7;
    const int cursorY = 5;
    const int textColor = 10;

    Board board;
    board.setCursorPosition(cursorX, cursorY);
    board.setTextColor(textColor);

    std::cout << "Score: " << score << std::endl; // Display the current score
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
bool Functionality::checkCollision(int enemyIndex)
{
    const int collisionThreshold = HEIGHT - 2;
    const int enemyWidth = 4;
    const int carWidth = 9;

    // Check if the enemy car is within the collision threshold
    if (enemyY[enemyIndex] + enemyWidth >= collisionThreshold)
    {
        // Check if the enemy car's x position overlaps with the player's car
        if (enemyX[enemyIndex] + enemyWidth > carPosition && enemyX[enemyIndex] < carPosition + carWidth)
        {
            return true;
        }
    }

    return false;
}

/**
 * @brief Resets the position of the specified enemy and regenerates its coordinates.
 *
 * This function erases the specified enemy from its current position and sets
 * a new position for the enemy by updating its coordinates. The enemy is then
 * regenerated at the new position.
 *
 * @param enemyIndex The index of the enemy to reset.
 */
void Functionality::resetEnemy(int enemyIndex)
{
    Enemy enemy;

    enemy.eraseEnemy(enemyIndex); // Remove the enemy from the screen
    enemyY[enemyIndex] = 1;       // Reset the enemy's Y-coordinate to the initial position
    enemy.genEnemy(enemyIndex);   // Generate new coordinates for the enemy
}

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
void Functionality::moveEnemiesDown(int enemyIndex, int sleep, int scoreIncrement)
{
    Enemy enemy;
    Player player;

    // Display the enemies
    enemy.printEnemy(enemyIndex);
    enemy.printEnemy(enemyIndex + 1);

    Sleep(sleep); // Control the speed of enemy movement

    // Erase the enemies from their current positions
    enemy.eraseEnemy(enemyIndex);
    enemy.eraseEnemy(enemyIndex + 1);

    // Check and update the flag for the second enemy's appearance
    if (enemyY[1] == 13 && flag[2] == 0)
    {
        flag[2] = 1;
    }

    // Move enemies downwards if their flags are set
    if (flag[enemyIndex] == 1)
    {
        enemyY[enemyIndex] += 1;
    }
    if (flag[enemyIndex + 1] == 1)
    {
        enemyY[enemyIndex + 1] += 1;
    }

    // Process user input for car movement
    if (kbhit())
    {
        char userInput = getch();
        if (userInput == 'a' || userInput == 'A' || userInput == 75) // Move left
        {
            if (carPosition > 19)
            {
                player.eraseCar();
                carPosition -= 4;
                player.printCar();
            }
        }
        else if (userInput == 'd' || userInput == 'D' || userInput == 77) // Move right
        {
            if (carPosition < 50)
            {
                player.eraseCar();
                carPosition += 4;
                player.printCar();
            }
        }
    }

    // Check if enemies have reached the bottom and update score
    if (enemyY[enemyIndex] > HEIGHT - 4)
    {
        resetEnemy(enemyIndex);
        score += scoreIncrement;
        updateScore();
    }

    if (enemyY[enemyIndex + 1] > HEIGHT - 4)
    {
        resetEnemy(enemyIndex + 1);
        score += scoreIncrement;
        updateScore();
    }
}

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
void Functionality::updateLeaderboard()
{
    const std::string fileName = "highest.csv";
    const int maxEntries = 3;

    // Prepare new score data
    std::string newName = Name;
    std::string newTime = std::to_string(diff);
    int newScore = testscore;

    std::ifstream file(fileName, std::ios::in);
    if (!file.is_open())
    {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }

    // Read existing leaderboard data
    struct LeaderboardEntry
    {
        std::string name;
        int score;
        std::string time;
    };

    LeaderboardEntry leaderboard[maxEntries];
    std::string line;
    int index = 0;
    while (index < maxEntries && std::getline(file, line))
    {
        std::stringstream ss(line);
        std::getline(ss, leaderboard[index].name, ',');
        std::getline(ss, line, ',');
        ss.clear();
        ss.str(line);
        ss >> leaderboard[index].score;
        std::getline(ss, leaderboard[index].time);
        ++index;
    }
    file.close();

    // Insert new score into the leaderboard
    index = 0;
    while (index < maxEntries && leaderboard[index].score >= newScore)
    {
        ++index;
    }

    if (index < maxEntries)
    {
        for (int i = maxEntries - 1; i > index; --i)
        {
            leaderboard[i] = leaderboard[i - 1];
        }
        leaderboard[index].score = newScore;
        leaderboard[index].name = newName;
        leaderboard[index].time = newTime;
    }

    // Write updated leaderboard back to file
    std::ofstream fout(fileName, std::ios::trunc);
    if (!fout.is_open())
    {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (int i = 0; i < maxEntries; ++i)
    {
        fout << leaderboard[i].name << ","
             << leaderboard[i].score << ","
             << leaderboard[i].time << std::endl;
    }
    fout.close();
}

/**
 * @brief Displays the leaderboard page with the top scores.
 *
 * This function reads the leaderboard data from a CSV file and prints it on the screen.
 * It displays the top three scores along with the names and times associated with those scores.
 * The display is centered on the terminal and uses a green text color.
 *
 * @return void
 */
void Functionality::displayLeaderboard()
{
    Board board;
    const int headerRow = 4;
    const int columnWidth = MAIN_SCREEN / 4;
    const int numberOfEntries = 3;

    system("Color 0A"); // Set text color to green

    // Print the leaderboard header
    std::string headerLine = "----------------------------";
    board.setCursorPosition(board.calculateCenterOffset(headerLine), headerRow);
    std::cout << headerLine;

    std::string headerTitle = "|        Leaderboard        |";
    board.setCursorPosition(board.calculateCenterOffset(headerTitle), headerRow + 1);
    std::cout << headerTitle;

    board.setCursorPosition(board.calculateCenterOffset(headerLine), headerRow + 2);
    std::cout << headerLine;

    std::ifstream file("highest.csv", std::ios::in);
    if (!file.is_open())
    {
        board.setCursorPosition(MAIN_SCREEN / 2, headerRow + 3);
        std::cout << "Error opening leaderboard file.";
        return;
    }

    // Print the column headers
    board.setCursorPosition(columnWidth, headerRow + 4);
    std::cout << "S.N.";
    board.setCursorPosition(2 * columnWidth, headerRow + 4);
    std::cout << "NAME";
    board.setCursorPosition(3 * columnWidth, headerRow + 4);
    std::cout << "SCORE";
    board.setCursorPosition(4 * columnWidth, headerRow + 4);
    std::cout << "TIME";

    // Read and display the leaderboard entries
    struct LeaderboardEntry
    {
        std::string name;
        int score;
        std::string time;
    };

    LeaderboardEntry entries[numberOfEntries];
    std::string scoreStr;
    int entryIndex = 0;

    while (entryIndex < numberOfEntries && std::getline(file, entries[entryIndex].name, ','))
    {
        std::getline(file, scoreStr, ',');
        std::getline(file, entries[entryIndex].time);
        std::stringstream scoreStream(scoreStr);
        scoreStream >> entries[entryIndex].score;
        ++entryIndex;
    }
    file.close();

    // Print the leaderboard entries
    for (int i = 0; i < numberOfEntries; ++i)
    {
        int rowOffset = headerRow + 5 + (3 * i);
        board.setCursorPosition(columnWidth, rowOffset);
        std::cout << i + 1;
        board.setCursorPosition(2 * columnWidth, rowOffset);
        std::cout << entries[i].name;
        board.setCursorPosition(3 * columnWidth, rowOffset);
        std::cout << entries[i].score;
        board.setCursorPosition(4 * columnWidth, rowOffset);
        std::cout << entries[i].time << " sec.";
    }

    // Wait for user input before closing
    std::cin.get();
    std::cin.get();
}

// TODO: refracting
/**
 * @brief Displays a countdown from 3 to 1 before the game starts.
 *
 * This function displays the numbers 3, 2, and 1 in sequence, each for a short duration.
 * The numbers are centered on the screen and are erased after being displayed.
 *
 * @return void
 */
void Functionality::displayCountdown()
{
    Board board;
    // using two for loops; one for the appearance of the number and another to erase for each of the three numbers
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            board.setCursorPosition(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3); // calling the board.position() function
            std::cout << one[j][i];                                               // prints '1'
        }
    }
    Sleep(1);
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            board.setCursorPosition(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3);
            std::cout << " "; // erases '1'
        }
    }

    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            board.setCursorPosition(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3); // calling the board.position() function
            std::cout << two[j][i];                                               // prints '2'
        }
    }
    Sleep(1);
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            board.setCursorPosition(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3);
            std::cout << " "; // erases '2'
        }
    }

    for (int j = 0; j < 7; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            board.setCursorPosition(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3);
            std::cout << three[j][i]; // prints '3'
        }
    }
    Sleep(1);
    for (int j = 0; j < 7; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            board.setCursorPosition(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3);
            std::cout << " "; // erses '3'
        }
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
void Functionality::play(int initialSpeed, int scoreIncrement, int speedFactor)
{
    Board board;
    Player player;
    Enemy enemy;
    Screen screen;

    // Initialize game state
    board.drawBorder();              // Draw the game border
    updateScore();                   // Display the current score
    board.displaySideInstructions(); // Show instructions on the side
    enemyY[1] = enemyY[2] = 0;       // Initialize enemy Y-coordinates
    player.printCar();               // Display the player's car
    flag[1] = 1;                     // Set flags for enemies
    flag[2] = 0;
    enemy.genEnemy(1); // Generate the first enemy
    enemy.genEnemy(2); // Generate the second enemy

    time_t startTime = time(0);          // Record the start time
    start_time = board.getCurrentTime(); // Initialize current time

    static int currentSpeed = initialSpeed;
    Sleep(1);
    displayCountdown(); // Display countdown before the game starts

    while (true)
    {
        board.printClock(); // Print the current game time

        // Adjust enemy speed based on the score
        if (score <= 10)
        {
            moveEnemiesDown(1, currentSpeed, scoreIncrement); // Move enemies at initial speed
        }
        else if (score > 10 && score <= 50)
        {
            moveEnemiesDown(1, currentSpeed - (20 / speedFactor), scoreIncrement); // Increase speed
        }
        else if (score > 50 && score <= 100)
        {
            moveEnemiesDown(1, currentSpeed - (40 / speedFactor), scoreIncrement); // Further increase speed
        }

        int collisionStatus = checkCollision(1); // Check for collision with the first enemy
        if (checkCollision(1) || checkCollision(2))
        {
            system("cls");              // Clear the screen
            time_t endTime = time(0);   // Record the end time
            diff = endTime - startTime; // Calculate the duration of the game
            testscore = score;          // Store the score for saving

            // Save the score to a file
            fout.open("Leaderboard.csv", std::ios::app);
            fout << Name << ",";        // Save the player's name
            fout << score << std::endl; // Save the score
            fout.close();               // Close the file

            screen.gameOver();   // Display the game over screen
            updateLeaderboard(); // Update the leaderboard
            score = 0;           // Reset the score
            break;               // Exit the game loop
        }
    }
}
