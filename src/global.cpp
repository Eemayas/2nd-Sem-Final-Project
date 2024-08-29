#include "global.h"

// Definition of global variables
int testscore = 0;          // Initializing test score
int highest[3] = {0, 0, 0}; // Initializing array for highest values
int level = 0;              // Initializing level
int speed = 0;              // Initializing speed

std::string Name; // Variable for saving player’s name

int enemyX[3] = {0}; // Initializing array for enemy X coordinates
int enemyY[3] = {0}; // Initializing array for enemy Y coordinates

int flag[3] = {0};                       // Initializing array for checking enemy generation
int startcarY = HEIGHT - 4;              // Initializing y coordinate for the generated car
int carPosition = (MAIN_SCREEN / 2) - 1; // Initializing x coordinate for the generated car
int score = 0;                           // Initializing score
int option = 0;                          // Initializing user’s input option
int sec_prev = 0;                        // Initializing starting time (seconds)
int A = 0;                               // Initializing variable
int diff = 0;                            // Initializing variable for saving the total played time
char *start_time = nullptr;              // Initializing starting time

contacts a[10], b[10];
// Additional initialization if needed
// e.g., int lives = 3;
