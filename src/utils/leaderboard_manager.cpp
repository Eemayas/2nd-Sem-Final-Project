#include "leaderboard_manager.h"
#include "board.h"
#include <iostream>
#include <sstream>

void checkAndCreateFile(const std::string &fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        // File doesn't exist, so create it
        std::ofstream newFile(fileName);
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
void LeaderboardManager::updateLeaderboard()
{
    const std::string fileName = "TopThree.csv";
    const int maxEntries = 3;

    // Prepare new score data
    std::string newName = playerName;
    std::string newTime = std::to_string(timeDifference);
    int newScore = testScore;

    // Check if the leaderboard file exists, and create it if it doesn't
    checkAndCreateFile(fileName);

    // Open the leaderboard file for reading
    std::ifstream leaderboardFile(fileName, std::ios::in);
    if (!leaderboardFile.is_open())
    {
        std::cerr << "Error opening leaderboard file for reading." << std::endl;
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
    // Read existing leaderboard data
    int entryIndex = 0;
    while (entryIndex < maxEntries && std::getline(leaderboardFile, line))
    {
        std::stringstream ss(line);
        std::getline(ss, leaderboard[entryIndex].name, ',');

        // Convert score from string to integer
        std::string scoreStr;
        std::getline(ss, scoreStr, ',');
        leaderboard[entryIndex].score = std::stoi(scoreStr);

        std::getline(ss, leaderboard[entryIndex].time);
        ++entryIndex;
    }
    leaderboardFile.close();

    // Insert new score into the leaderboard if it qualifies
    bool inserted = false;
    for (int i = 0; i < maxEntries; ++i)
    {
        if (newScore > leaderboard[i].score)
        {
            // Shift lower scores down
            for (int j = maxEntries - 1; j > i; --j)
            {
                leaderboard[j] = leaderboard[j - 1];
            }
            // Insert new score
            leaderboard[i].score = newScore;
            leaderboard[i].name = newName;
            leaderboard[i].time = newTime;
            inserted = true;
            break;
        }
    }

    // If new score is not high enough to enter the leaderboard, return
    if (!inserted)
    {
        return;
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
void LeaderboardManager::displayLeaderboard()
{
    Board board;
    const int headerRow = 4;
    const int columnWidth = PLAY_AREA_WIDTH / 4;
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

    std::ifstream file("TopThree.csv", std::ios::in);
    if (!file.is_open())
    {
        board.setCursorPosition(PLAY_AREA_WIDTH / 2, headerRow + 3);
        std::cout << "Error opening leaderboard file.";
        return;
    }

    // Print the column headers
    board.setCursorPosition(columnWidth, headerRow + 4);
    std::cout << "S.N.";
    board.setCursorPosition(2 * columnWidth, headerRow + 4);
    std::cout << "NAME";
    board.setCursorPosition(4 * columnWidth, headerRow + 4);
    std::cout << "SCORE";
    board.setCursorPosition(5 * columnWidth, headerRow + 4);
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
    if (entries[1].name == "")
    {
        board.setCursorPosition(board.calculateCenterOffset("No Data to Display"), headerRow + 8);
        std::cout << "No Data to Display";
    }
    else
    {
        // Print the leaderboard entries
        for (int i = 0; i < numberOfEntries; ++i)
        {
            if (entries[i].name == "")
            {
                break;
            }
            int rowOffset = headerRow + 5 + (3 * i);
            board.setCursorPosition(columnWidth, rowOffset);
            std::cout << i + 1;
            board.setCursorPosition(2 * columnWidth, rowOffset);
            std::cout << entries[i].name;
            board.setCursorPosition(4 * columnWidth, rowOffset);
            std::cout << entries[i].score;
            board.setCursorPosition(5 * columnWidth, rowOffset);
            std::cout << entries[i].time << " sec.";
        }
    }
}
