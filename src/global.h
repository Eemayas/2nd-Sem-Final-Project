#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>

using std::string;

// Define screen dimensions and gameplay area
#define SCREEN_WIDTH 100   // Full width of the screen
#define SCREEN_HEIGHT 30   // Full SCREEN_HEIGHT of the screen
#define PLAY_AREA_WIDTH 70 // Width of the playable area

// Global variables
extern int testScore;		 // For storing the current test score
extern int highestScores[3]; // Array to hold the top 3 highest scores
extern int selectedLevel;	 // Player-selected difficulty selectedLevel
extern int gameSpeed;		 // Speed of the game

extern std::string playerName; // variable for saving player’s name

extern int enemyXCoordinates[3]; // array for storing coordinates of the enemy car
extern int enemyYCoordinates[3]; // array for storing coordinates of the enemy car

// Flags and position trackers
extern int enemyGenerationFlags[3]; // Flags to control enemy generation
extern int playerInitialY;			// Initial Y-coordinate of the player's car
extern int playerXPosition;			// X-coordinate of the player's car
extern int currentScore;			// Player's current score
extern int menuOption;				// Selected menu option by the player
extern int previousSecond;			// Variable to store the previous second for timing
extern int timeAccumulator;			// Accumulator for tracking total playtime
extern int timeDifference;			// Total time difference between the start and current time
extern char *gameStartTime;			// Time when the game starts

// // ASCII values of needed symbols
// const char full = 219; // dark full block
// const char top = 223;
// const char bottom = 220;
// const char block = 219; // dark full block
// const char SHADE_LIGHT = 176;
// const char SHADE_MEDIUM = 177;
// const char SHADE_DARK = 178;
// const char line = 205;
// const char VERTICAL_LINE = 186;
// const char O = 233;
// const char S = 48;
// ASCII values of symbols used in the game
const char FULL_BLOCK = 219;	  // Dark full block
const char TOP_BLOCK = 223;		  // Top half block
const char BOTTOM_BLOCK = 220;	  // Bottom half block
const char SHADE_LIGHT = 176;	  // Light shade block
const char SHADE_MEDIUM = 177;	  // Medium shade block
const char SHADE_DARK = 178;	  // Dark shade block
const char HORIZONTAL_LINE = 205; // Horizontal line
const char VERTICAL_LINE = 186;	  // Vertical line
const char CHAR_O = 233;		  // Character 'O'
const char CHAR_S = '0';		  // Character 'S'

// Appearance of the player’s car
const char carDesign[4][4] = {
	{' ', SHADE_DARK, ' ', SHADE_DARK},
	{'*', '*', '*', '*'},
	{'*', '*', '*', '*'},
	{' ', SHADE_DARK, ' ', SHADE_DARK}};

// Appearance of the digit '1'
const char digitOne[6][6] = {
	{' ', ' ', ' ', ' ', '#', ' '},
	{' ', ' ', ' ', '#', '#', ' '},
	{' ', ' ', '#', ' ', '#', ' '},
	{' ', '#', ' ', ' ', '#', ' '},
	{' ', ' ', ' ', ' ', '#', ' '},
	{' ', ' ', ' ', ' ', '#', ' '}};

// Appearance of the digit '2'
const char digitTwo[6][6] = {
	{' ', ' ', '#', ' ', ' ', ' '},
	{' ', '#', ' ', '#', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' '},
	{' ', ' ', ' ', '#', ' ', ' '},
	{' ', ' ', '#', ' ', ' ', ' '},
	{' ', '#', '#', '#', '#', '#'}};

// Appearance of the digit '3'
const char digitThree[7][7] = {
	{' ', '#', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', '#', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', '#', ' ', ' ', ' ', '#'},
	{' ', ' ', '#', '#', '#', ' ', ' '},
	{' ', '#', '#', ' ', ' ', ' ', ' '}};

// Structure to store player information
struct PlayerInfo
{
	std::string name; // Player's name
	int currentScore; // Player's score
	std::string time; // Time of the play session
};

// extern PlayerInfo a[10], b[10]; // assigning initial values
extern PlayerInfo currentPlayers[10]; // Array of current player information
extern PlayerInfo leaderboard[10];	  // Array of leaderboard information

#endif // _GLOBAL_H_
