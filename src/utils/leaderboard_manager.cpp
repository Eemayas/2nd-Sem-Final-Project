#include "leaderboard_manager.h"
#include "board.h"
#include <iostream>
#include <sstream>

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
