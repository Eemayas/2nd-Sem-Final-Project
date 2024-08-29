#ifndef _FUNCTIONALITY_H_
#define _FUNCTIONALITY_H_

#include <fstream> // include the <fstream> header file
// #include "global.h" // including header file
// ofstream fout1;
// ofstream fout;
class Functionality
{
public:
    int testscore;
    int highest[3] = {0, 0, 0}; // initializing array for highest value and assigning initial //value 0
    void updateScore();
    int collision(int enemy_number);
    void reset(int enemy_number);

    void downward(int enemy_number, int Sleep, int q);
    void calculate_highest();
    void leaderboard();
    void countdown();
    void play(int x, int s, int z);

private:
    std::ofstream fout;
    std::ofstream fout1;
};

#endif