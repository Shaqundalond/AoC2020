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
int Puzzle_12_1(vector <string> &sList);
int Puzzle_12_2(vector <string> &sList);


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
    Puzzle_12_1(vs);

    // Second puzzle of the day
    Puzzle_12_2(vs);

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

int Puzzle_12_1(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 12 Part 1",'=');

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

/**
 * @brief  Rotates a point around a given Angle
 * 
 * @param cx        - Position X
 * @param cy        - Position Y
 * @param Angle     - Angle only multiples of 90
 * @param nx 
 * @param ny 
 * @return int 
 */
int Rotate( int &nx, int &ny, int Angle, bool bTurnLeft)
{
    int cx = nx;
    int cy = ny;

    int tA = Angle % 360;
    if (tA < 0)
        tA += 360;

    if (bTurnLeft == false)
        tA = 360 - tA;      // Now it is Left

    switch (tA)
    {
        case 0:
        case 360:
            // nothing to do
            nx = cx;
            ny = cy;
            break;
        case 90:
            nx = -cy;
            ny =  cx;
            break;
        case 180:
            nx = -cx;
            ny = -cy;
            break;
        case 270:
            nx =  cy;
            ny = -cx;
            break;
        default:
            cout << "  ** ERROR in Rotating: Unkonw Angle: " << Angle << endl;
            break;
    }

    return 0;
}

/**
 * @brief           Puzzöe_12_2
 * 
 * Part 1:
 * - Find Manhatten Distance to a list of navigation commands:
 * 
 * Same as puzzle 1 except that the commands are related to a waypoint
 * 
 * Almost all of the actions indicate how to move a waypoint which is relative to the ship's position:

    Action N means to move the waypoint north by the given value.
    Action S means to move the waypoint south by the given value.
    Action E means to move the waypoint east by the given value.
    Action W means to move the waypoint west by the given value.
    Action L means to rotate the waypoint around the ship left (counter-clockwise) the given number of degrees.
    Action R means to rotate the waypoint around the ship right (clockwise) the given number of degrees.
    Action F means to move forward to the waypoint a number of times equal to the given value.
    The waypoint starts 10 units east and 1 unit north relative to the ship. The waypoint is relative to the ship; 
    that is, if the ship moves, the waypoint moves with it.

        F10
        N3
        F7
        R90
        F11

    For example, using the same instructions as above:

    F10 moves the ship to the waypoint 10 times (a total of 100 units east and 10 units north), 
        leaving the ship at east 100, north 10. The waypoint stays 10 units east and 1 unit north of the ship.
    N3 moves the waypoint 3 units north to 10 units east and 4 units north of the ship. 
        The ship remains at east 100, north 10.
    F7 moves the ship to the waypoint 7 times (a total of 70 units east and 28 units north), 
        leaving the ship at east 170, north 38. The waypoint stays 10 units east and 4 units north of the ship.
    R90 rotates the waypoint around the ship clockwise 90 degrees, moving it to 4 units east and 10 units south of the ship. 
        The ship remains at east 170, north 38.
    F11 moves the ship to the waypoint 11 times (a total of 44 units east and 110 units south), 
        leaving the ship at east 214, south 72. The waypoint stays 4 units east and 10 units south of the ship.

    After these operations, the ship's Manhattan distance from its starting position is 214 + 72 = 286.
 * 
 * @param vector<string>   list of strings
 * @return int             0
 */

int Puzzle_12_2(vector<string> &sList)
{

    cout << MakeHeadline("Advent of Code 2020 Puzzle # 12 Part 2",'=');        

    int iLine = 0;

    // astronomical system (south = 0 Azimuth)
    // + -> North;  - -> South
    // + -> East;   - -> West
    // 0 = south; 90 = west; 180 = north; 270 = east

    // Position of the ship
    int cx = 0;     
    int cy = 0;   
    // position of the waypoint          
    int wx = 10;             
    int wy =  1;     

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
                wy += dist;
                break;
                
            case 'S':
                wy -= dist;
                break;

            case 'W':
                wx -= dist;
                break;

            case 'E':
                wx += dist;
                break;

            case 'L':
                Rotate(wx, wy, dist, true);
                break;

            case 'R':
                Rotate(wx, wy, dist, false);
                break;

            case 'F':
                cx += dist * wx;
                cy += dist * wy;
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

