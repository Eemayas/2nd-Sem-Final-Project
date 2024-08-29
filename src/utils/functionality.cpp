#include "functionality.h"
#include <iostream>
#include "board.h"
#include <enemy.h>
#include <conio.h>
#include <player.h>
#include <sstream>
#include <screen.h>
/**defining function
 *@brief function to print score
 *@return void
 */

void Functionality::updateScore()
{
    Board board;
    position(MAIN_SCREEN + 7, 5);
    board.color(10);
    cout << "Score: " << score << endl; // printing the score
}

/**defining function
 *@brief function to check whether the cars collide or not
 *@param x integer data type containing value of 1 or 0
 *@return true if collision happens, otherwise return false
 */

int Functionality::collision(int enemy_number)
{
    int x;
    if (enemyY[enemy_number] + 4 >= HEIGHT - 2)
    {
        if (enemyX[enemy_number] + 4 - carposition >= 0 && enemyX[enemy_number] + 4 - carposition < 9)
        {
            x = 1;
        }
    }
    return x;
}

/**defining function
 *@brief function to erase the enemy and set the coordinate for new enemy
 *@return 0
 */

void Functionality::reset(int enemy_number)
{
    Enemy enemy;
    enemy.erase_Enemy(enemy_number); // erases the enemy
    enemyY[enemy_number] = 1;        // coordinate of new enemy of y axis
    enemy.gen_Enemy(enemy_number);   // generates the enemy coordinate
}

/**defining function
 *@brief function to erase the enemy and set the coordinate for new enemy
 *@return 0
 */

void Functionality::reset(int enemy_number)
{
    Enemy enemy;
    enemy.erase_Enemy(enemy_number); // erases the enemy
    enemyY[enemy_number] = 1;        // coordinate of new enemy of y axis
    enemy.gen_Enemy(enemy_number);   // generates the enemy coordinate
}

/**defining function
 *@brief function to move the enemy car downwards
 *@param sleep integer data type to set the speed of enemy car
 *@param q integer data type to increase the score according to the level
 *@return void
 */

void Functionality::downward(int enemy_number, int sleep, int q)
{
    Enemy enemy;
    Player player;
    enemy.print_Enemy(enemy_number);     // print the first enemy
    enemy.print_Enemy(enemy_number + 1); // print the second enemy
    Sleep(sleep);                        // sets the speed for the enemy
    enemy.erase_Enemy(enemy_number);     // erase the first enemy
    enemy.erase_Enemy(enemy_number + 1); // erase the second enemy

    // checking the condition for appearance of second enemy
    if (enemyY[1] == 13)
    {
        if (flag[2] == 0)
        {
            flag[2] = 1;
        }
    }

    // moving the enemy downwards
    if (flag[enemy_number] == 1)
    {
        enemyY[enemy_number] += 1;
    }
    if (flag[enemy_number + 1] == 1)
    {
        enemyY[enemy_number + 1] += 1;
    }

    // moving the car left or right as the user wants
    if (kbhit() == 1)
    {
        // taking the input from the user
        char ch = getch();
        // char ch=cin.get();
        // Moving the car towards the left
        if (ch == 'a' || ch == 'A' || ch == 75)
        {
            if (carposition > 19)
            {
                player.erase_Car();
                carposition -= 4;
                player.print_Car();
            }
        }
        // Moving the car towards the right
        if (ch == 'd' || ch == 'D' || ch == 77)
        {
            if (carposition < 50)
            {
                player.erase_Car();
                carposition += 4;
                player.print_Car();
            }
        }
    }

    // checking the condition if the enemy has reached the bottom or not
    if (enemyY[enemy_number] > HEIGHT - 4)
    {
        reset(enemy_number); // calling reset() function
        score = score + q;   // increasing the score
        // Beep(1000,10);
        updateScore(); // calling
    }

    if (enemyY[enemy_number + 1] > HEIGHT - 4)
    {
        reset(enemy_number + 1);
        score = score + q;
        // Beep(1000,10);
        updateScore();
    }
}

/**defining function
 *@brief function to print highest score using file handling in excel
 *@param testname string to name
 *@param testtime string to store the played time
 *@return void
 */

void Functionality::highest()
{
    string testname = Name;
    string testtime = to_string(diff); // to_string changes the integer to string type
    ifstream file;
    file.open("highest.csv", ios::app); // opening the file
    string s;
    // checking if file is open or not
    if (file.is_open())
    {
        // getting the data from the excel
        for (int i = 0; i <= 3; i++)
        {
            getline(file, a[i].name, ',');
            getline(file, s, ',');
            getline(file, a[i].time);
            stringstream qw(s);
            qw >> a[i].score;
        }
    }

    else
    {
        cout << "Error"; // if not opened
    }
    int i = 0;

    // while loop to sort the leaderboard for the first three highest scorers in excel
    while (i < 3)
    {
        if (a[i].score < testscore)
        {

            a[i + 2].score = a[i + 1].score;
            a[i + 2].name = a[i + 1].name;
            a[i + 2].time = a[i + 1].time;

            a[i + 1].score = a[i].score;
            a[i + 1].name = a[i].name;
            a[i + 1].time = a[i].time;

            a[i].score = testscore;
            a[i].name = testname;
            a[i].time = testtime;

            // cout<<i<<endl;
            break;
        }
        else
        {
            i++;
        }
    }
    file.close();
    // for (int i = 0; i < 3; i++) {
    //    cout << "Name :      " << a[i].name << endl;
    //
    // cout<< "Nick :   " << a[i].score << endl;}

    // clearing the previous old file and opening a new file
    fout1.open("highest.csv", ios::trunc);
    // putting the data in excel
    for (int i = 0; i < 3; i++)
    {
        fout1 << a[i].name << ",";
        fout1 << a[i].score << ",";
        fout1 << a[i].time << endl;
    }
    fout1.close(); // closes the file
}

/**defining function
 *@brief function to print the leaderboard page
 *@return void
 */

void Functionality::leaderboard()
{
    Board board;
    system("Color 0A"); // changes the text board.color to green
    // printing the text in board.center if the terminal
    string text1 = "----------------------------";
    position(board.center(text1), 4);
    cout << text1;
    text1 = "|        Leaderboard        |";
    position(board.center(text1), 5);
    cout << text1;
    text1 = "----------------------------";
    position(board.center(text1), 6);
    cout << text1;
    ifstream file1;
    file1.open("highest.csv", ios::app); // opening the file
    string s1;
    if (file1.is_open())
    {
        // getting the data from the excel and saving it into the structure
        for (int i = 0; i <= 3; i++)
        {
            getline(file1, b[i].name, ',');
            getline(file1, s1, ',');
            getline(file1, b[i].time);
            stringstream qw1(s1);
            qw1 >> b[i].score;

            position((MAIN_SCREEN / 4), 8);
            cout << "S.N.";
            position((2) * (MAIN_SCREEN / 4), 8);
            cout << "NAME";
            position((3) * (MAIN_SCREEN / 4), 8);
            cout << "SCORE";
            position((4) * (MAIN_SCREEN / 4), 8);
            cout << "TIME";
            // printing the data from the structure
            for (int i = 0; i < 3; i++)
            {
                int j = 1;

                position((j) * (MAIN_SCREEN / 4), 10 + (3 * i));
                cout << i + 1;
                position((j + 1) * (MAIN_SCREEN / 4), 10 + (3 * i));
                cout << b[i].name;
                position((j + 2) * (MAIN_SCREEN / 4), 10 + (3 * i));
                cout << b[i].score;
                position((j + 3) * (MAIN_SCREEN / 4), 10 + (3 * i));
                cout << b[i].time << " sec.";
            }
        }
    }
    // if file is not openedd
    else
    {
        position(MAIN_SCREEN / 2, 7);
        cout << "Error";
    }

    // getch
    cin.get();
    cin.get();
}

/**
*@define function for the coutdown before the game starts


*@return void
*/
void Functionality::countdown()
{
    // using two for loops; one for the appearance of the number and another to erase for each of the three numbers
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            position(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3); // calling the position() function
            cout << one[j][i];                                     // prints '1'
        }
    }
    Sleep(1);
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            position(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3);
            cout << " "; // erases '1'
        }
    }

    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            position(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3); // calling the position() function
            cout << two[j][i];                                     // prints '2'
        }
    }
    Sleep(1);
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            position(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3);
            cout << " "; // erases '2'
        }
    }

    for (int j = 0; j < 7; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            position(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3);
            cout << three[j][i]; // prints '3'
        }
    }
    Sleep(1);
    for (int j = 0; j < 7; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            position(MAIN_SCREEN / 2 + i - 3, HEIGHT / 2 + j - 3);
            cout << " "; // erses '3'
        }
    }
}

/**
 *@define function to play the actual game
 *@param x integer to set the speed as required
 *@param s integer for the added scores in different levels
 *@param z integer
 */
void Functionality::play(int x, int s, int z)
{
    Board board;
    Player player;
    Enemy enemy;
    Screen screen;
    board.draw_Border();       // calling function to draw border
    updateScore();             // calling function to update score
    board.side_Instruction();  // calling function to print side instruction
    enemyY[1] = enemyY[2] = 0; // initializing the y coordinate of two enemy
    player.print_Car();        // calling function to print car
    flag[1] = 1;
    flag[2] = 0;
    enemy.gen_Enemy(1);     // calling function to generate first enemy
    enemy.gen_Enemy(2);     // calling function to generate second enemy
    time_t start = time(0); // variable for saving starting time
    start_time = board.timme();

    static int a = x;
    Sleep(1);
    countdown(); // calling function to start countdown
    while (1)
    {
        board.print_Clock(A); // calling function to  print the digital clock

        speed = x;

        // using for loop for the condition to speed up
        // execute if score is less than 5
        if (score <= 10)
        {
            downward(1, speed, s); // calling function to move enemy downwards
        }
        // execute if score is greater than 10, less than 50
        if (score > 10 && score <= 50)
        {
            downward(1, speed - (20 / z), s);
        }
        // execute if score is greater than 50, less than 100
        if (score > 50 && score <= 100)
        {
            downward(1, speed - (40 / z), s);
        }
        A++;
        int c = collision(1); // assigning the value to check the collision
        if (collision(1) == 1 || collision(2) == 1)
        {
            system("cls"); // clears the whole window
            time_t end = time(0);
            diff = end - start; // calculating the total played time
            testscore = score;

            // opening the file named ‘sample14’
            fout.open("sample14.csv", ios::app);
            fout << Name << ",";   // saving the name in a cell of excel
            fout << score << endl; // saves start time and end time in two corresponding cells
            fout.close();          // closes the opened file
            screen.game_Over();    // calling the function game_Over
            highest();             // calling highest() function from parent class
            score = 0;             // re-initializing the value of ‘score’ as 0
            break;
        }
    }
}
