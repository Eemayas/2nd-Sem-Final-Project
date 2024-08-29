#ifndef _FUNCTIONALITY_H_
#define _FUNCTIONALITY_H_

#include <fstream>  // include the <fstream> header file
#include "global.h" // including header file
ofstream fout1;
ofstream fout;
class Functionality
{
public:
    void updateScore();
    int collision(int enemy_number);
    void reset(int enemy_number);

    void downward(int enemy_number, int Sleep, int q);
    void highest();
    void leaderboard();
    void countdown();
    void play(int x, int s, int z);
};

#endif