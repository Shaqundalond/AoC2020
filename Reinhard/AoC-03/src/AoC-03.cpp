/**
 * @file AoC-03.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #03
 * @version 0.1
 * @date 2020-12-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


/**
 * @brief       AoC Puzzle Day 02
 * 
 * Results for both puzzles are calculatet while readin th input-file and are written to std::cout.
 * 
 * @param fn        filename for input
 * @return int      errornumer
 *                  0 - no error
 *                 -1 - file opening error
 */
int Puzzle_3_1(const string fn)
{
    cout << MakeHeadline("** Puzzle 1: Counting trees",'-') << endl;

    vector<string> vs;

    if (ReadStrings(fn, vs) < 0)
        return -1;

    const int dx = 3;
    const int dy = 1;

    int ix = 0;
    int iy = 0;
    int iCountTrees = 0;

    for (iy = 0; iy < vs.size(); iy+= dy)
    {
        int iySize = vs[iy].length();        // should be always the same
        int ii = ix % iySize;
        char tc = (vs[iy]).at(ii);
        if (tc == '#')
            iCountTrees += 1;
        ix += dx;
    }

    // Writing results to std::cout
    cout << endl;
    cout << "**** Number of trees    : " << iCountTrees << endl;
 
    return 0;
}


int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 03",'=') << endl;

    Puzzle_3_1("input.txt");

    return 0;
}