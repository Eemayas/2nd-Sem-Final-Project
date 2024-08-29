#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <string>

using std::string;

#define WIDTH 100	   // main screen width (to the sidemost)
#define HEIGHT 30	   // total height
#define MAIN_SCREEN 70 // width of the playing field

// Declaration of global variables
extern int testscore;  // variable for testing score
extern int highest[3]; // array for highest value
extern int level;	   // variable for choosing levels
extern int speed;	   // variable for choosing speed

extern std::string Name; // variable for saving player’s name

extern int enemyX[3]; // array for storing coordinates of the enemy car
extern int enemyY[3]; // array for storing coordinates of the enemy car

extern int flag[3];		 // array for checking whether to generate enemy or not
extern int startcarY;	 // initial y coordinate for the generated car
extern int carposition;	 // initial x coordinate for the generated car
extern int score;		 // variable for score
extern int option;		 // variable for storing user’s input option
extern int sec_prev;	 // variable for starting time (seconds)
extern int A;			 // variable
extern int diff;		 // variable for saving the total played time
extern char *start_time; // variable for starting time

// ASCII values of needed symbols
const char full = 219; // dark full block
const char top = 223;
const char bottom = 220;
const char block = 219; // dark full block
const char block1 = 176;
const char block2 = 177;
const char block3 = 178;
const char line = 205;
const char line2 = 186;
const char O = 233;
const char S = 48;

// Appearance of the car
const char car[4][4] = {
	{' ', block3, ' ', block3},
	{'*', '*', '*', '*'},
	{'*', '*', '*', '*'},
	{' ', block3, ' ', block3}};

// Appearance of the number ‘1’
const char one[6][6] = {
	{' ', ' ', ' ', ' ', '#', ' '},
	{' ', ' ', ' ', '#', '#', ' '},
	{' ', ' ', '#', ' ', '#', ' '},
	{' ', '#', ' ', ' ', '#', ' '},
	{' ', ' ', ' ', ' ', '#', ' '},
	{' ', ' ', ' ', ' ', '#', ' '}};

// Appearance of the number ‘2’
const char two[6][6] = {
	{' ', ' ', '#', ' ', ' ', ' '},
	{' ', '#', ' ', '#', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' '},
	{' ', ' ', ' ', '#', ' ', ' '},
	{' ', ' ', '#', ' ', ' ', ' '},
	{' ', '#', '#', '#', '#', '#'}};

// Appearance of the number ‘3’
const char three[7][7] = {
	{' ', '#', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', '#', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', '#', ' ', ' ', ' ', '#'},
	{' ', ' ', '#', '#', '#', ' ', ' '},
	{' ', '#', '#', ' ', ' ', ' ', ' '}};

// defining structure to store player info
struct contacts
{
	string name;
	int score;
	string time;
};

extern contacts a[10], b[10]; // assigning initial values

#endif // _GLOBAL_H_
