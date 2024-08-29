#ifndef _BOARD_H_
#define _BOARD_H_
#include "global.h"
#include <wtypes.h>
#include <string>

class Board
{
public:
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    void color(int i);

    int center(string s);

    char *timme();

    void print_Clock(int a);

    void draw_Border();

    void side_Instruction();
};

#endif
