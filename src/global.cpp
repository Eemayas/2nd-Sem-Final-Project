#include "global.h"

// Definitions of global variables

// Test score variable
int testScore = 0;

// Array to store highest scores for three levels
int highestScores[3] = {0, 0, 0};

// Variable to track the selected level
int selectedLevel = 0;

// Variable to control the speed of the game
int gameSpeed = 0;

// Variable to store the player's name
std::string playerName;

// Arrays to store the X and Y coordinates of enemies
int enemyXCoordinates[3] = {0};
int enemyYCoordinates[3] = {0};

// Flags to check whether to generate enemies
int enemyGenerationFlags[3] = {0};

// Initial Y coordinate for the player's car
int playerInitialY = SCREEN_HEIGHT - 4;

// Initial X coordinate for the player's car (centered in the play area)
int playerXPosition = (PLAY_AREA_WIDTH / 2) - 1;

// Current score of the player
int currentScore = 0;

// User's input option
int menuOption = 0;

// Variable to track the previous second for timing purposes
int previousSecond = 0;

// Accumulator variable (purpose to be defined)
int accumulator = 0;

// Variable to store the total played time
int timeDifference = 0;

// Pointer to store the game's start time
char *gameStartTime = nullptr;

// Array of player contact information for leaderboard and current players
PlayerInfo currentPlayers[10];
PlayerInfo leaderboard[10];
