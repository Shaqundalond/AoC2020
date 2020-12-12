/**
 * @file AoC-12.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #12
 * @version 0.1
 * @date 2020-12-12
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


// Function declarations
// =====================
int Puzzle_12(vector <string> &sList, int iPuzzle);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 12",'=');

    // Reading input strings
    vector<string> vs;
    if (ReadStrings("input.txt", vs) < 0)
    {
        cout << "---ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 
    Puzzle_12(vs,1);

    // Second puzzle of the day
    // Puzzle_12(vs,2);

    return 0;
}




/**
 * @brief           AoC Puzzle
 * 
 * Part 1:
 * - Find Manhatten Distance to a list of navigation commands:
 * 
 * The navigation instructions (your puzzle input) consists of a sequence of single-character actions paired with integer input values. After staring at them for a few minutes, you work out what they probably mean:

    Action N means to move north by the given value.
    Action S means to move south by the given value.
    Action E means to move east by the given value.
    Action W means to move west by the given value.
    Action L means to turn left the given number of degrees.
    Action R means to turn right the given number of degrees.
    Action F means to move forward by the given value in the direction the ship is currently facing.
    The ship starts by facing east. Only the L and R actions change the direction the ship is facing. (That is, if the ship is facing east and the next instruction is N10, the ship would move north 10 units, but would still move east if the following action were F.)

    For example:

    F10
    N3
    F7
    R90
    F11

 * 
 * @param vector<string>   list of strings
 * @return int             0
 */

int Puzzle_12(vector<string> &sList, int iPuzzle)
{
    if (iPuzzle == 1)
        cout << MakeHeadline("Advent of Code 2020 Puzzle # 12 Part 1",'=');
    else
        cout << MakeHeadline("Advent of Code 2020 Puzzle # 12 Part 2",'=');        

    int iLine = 0;

    // astronomical system (south = 0 Azimuth)
    int cx = 0;             // + -> North;  - -> South
    int cy = 0;             // + -> East;   - -> West
    int heading = 270;      // 0 = south; 90 = west; 180 = north; 270 = east

    char cmd;
    int dist;
    
    for (string ts: sList)
    {
        iLine += 1;

        // Decoding command and dist
        stringstream sst(ts);
        sst >> cmd >> dist;

        // cout << "-Moving form: " << cx << "," << cy <<" head= " << heading << " cmd: " << cmd << " dist= " << dist ; 

        // lets do it
        switch (cmd)
        {
            case 'N':
                cy += dist;
                break;
                
            case 'S':
                cy -= dist;
                break;

            case 'W':
                cx -= dist;
                break;

            case 'E':
                cx += dist;
                break;

            case 'L':
                heading -= dist;
                while (heading < 0)
                    heading += 360;
                break;

            case 'R':
                heading += dist;
                while (heading >= 360)
                    heading -= 360;
                break;

            case 'F':
                switch (heading)
                {
                    case   0: cy -= dist; break;
                    case  90: cx -= dist; break;
                    case 180: cy += dist; break;
                    case 270: cx += dist; break;
                    default:
                        cout << " Error in heading : " << heading << endl;
                }
                break;

            default:
                cout << " Error in Command : " << iLine << " :: "<< ts <<  " :: " << endl;
        }

    //    cout << " to: " << cx << "," << cy <<" head= " << heading << endl; 

    }

    int manhatten = abs(cx) + abs(cy);

    cout << " Manhattendistance = " << manhatten << endl;

    return 0;
}

