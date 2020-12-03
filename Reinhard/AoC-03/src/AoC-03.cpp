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
 * @param vs        vector<string> with treemap
 * @return int      errornumer
 *                  0 - no error
 *                 -1 - file opening error
 */
int Puzzle_3_1(const vector<string> &vs, const int dx, const int dy)
{
    int ix = 0;
    int iy = 0;
    int iCountTrees = 0;

    for (iy = 0; iy < vs.size(); iy+= dy)
    {
        int cxSize = vs[iy].length();        // should be always the same, but - who knows
        int ii = ix % cxSize;
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

    cout << MakeHeadline("** Puzzle 1: Counting trees",'-') << endl;

    vector<string> vs;

    if (ReadStrings("input.txt", vs) > 0)
    {
        Puzzle_3_1(vs, 3, 1);
    }

    return 0;
}