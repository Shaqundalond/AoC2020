/**
 * @file AoC-14.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #14
 * @version 0.1
 * @date 2020-12-14
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


// Function declarations
// =====================
int Puzzle_14_1(vector <string> &sList);
int Puzzle_14_2(vector <string> &sList);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 14",'=');

    // Reading input strings
    vector<string> vs;
    if (ReadStrings("input.txt", vs) < 0)
    {
        cout << "---ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 
    Puzzle_14_1(vs);

    // Second puzzle of the day
    Puzzle_14_2(vs);

    return 0;
}


/**
 * @brief           AoC Puzzle
 * 
 * Part 1: Analysing a commandfile
 * 
 * Each memory pos has 36 Bits
 * there ist always a mask active:
 *      0 - Bit is set to 0
 *      1 - Bit is set to 1
 *      x - Bit is left as it is
 * File:
 * Mask = xxxx1xxxx0xx
 * mem[pos] = value (dec)
 * :
 * 
 * Remarks:
 * pos can be high (up to 100.000)
 * 
 * 
 * @param vector<string>   list of strings
 * @return int             0
 */
int Puzzle_14_1(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 14 Part 1",'=');

    string mask(36,'x');
    long mask_0 = 0L;
    long mask_1 = 0L;

    // 
    for (auto ts : sList)
    {
        vector<string> Xline = explode(ts,"[] =");
    }

    return 0;
}

/**
 * @brief           AoC Puzzle
 * 
 * Part 2:
 * 
 * @param vector<string>   list of strings
 * @return int             0
 */

int Puzzle_14_2(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 14 Part 2",'=');

    cout << " -- Nor yet implemented" << endl;

    return 0;
}


