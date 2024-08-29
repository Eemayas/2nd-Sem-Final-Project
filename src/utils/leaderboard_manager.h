#ifndef _LEADERBOARD_MANAGER_H_
#define _LEADERBOARD_MANAGER_H_

#include <string>
#include <fstream> // For file stream operations

class LeaderboardManager
{
public:
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

private:
    std::ofstream fout;  ///< Output file stream for saving game results.
    std::ofstream fout1; ///< Output file stream for another purpose, if needed.
};

#endif // _LEADERBOARD_MANAGER_H_
