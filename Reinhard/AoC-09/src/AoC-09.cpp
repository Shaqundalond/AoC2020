/**
 * @file AoC-09.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #09
 * @version 0.1
 * @date 2020-12-09
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


// Function declarations
// =====================
int Puzzle_9(vector <int> iList, int iPuzzle);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 09",'=');

    // Reading input strings
    vector<string> vs;
    if (ReadStrings("input.txt", vs) < 0)
    {
        cout << "---ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // Frist step: convert string to int
    vector <int> iList (vs.size());
    for (int i=0; i < vs.size(); i++)
        iList[i] = atoi(vs[i].c_str());

    // first puzzle of day 
    cout << MakeHeadline(" ** Puzzle 1: finding sum of 2 ints from last 25 ints behind",'~') << endl;
    int iResult = Puzzle_9(iList,1);
    cout << " == Value : " << iResult << endl;

    return 0;
}




/**
 * @brief           AoC Puzzle
 * 
 * searching a number which is NOT the sum of any two ints from the last 25 ints behind
 * 
 * @param vector<int>   list of ints
 * @return int          n - number of yes
 */
int Puzzle_9(vector<int> iList, int iPuzzle)
{
    int iResult = 0;
    int ci = 0;

    for (ci = 25; ci < iList.size(); ci++)
    {
        int iTarget = iList[ci];    // this should be the sum 
        bool found = false;
        for (int i = 0; i < (25-1); i++)
        {
            for (int j = i+1; j < 25; j++)
            {
                int iSum = iList[i] + iList[j];
                if (iSum == iTarget)
                {
                    found = true; // Hipp hipp
                    j=24;
                    i=23;
                }
            }
        }
        if (!found)
        {
            // this number is not the sum of two of the last 25 ints
            return iList[ci];
        }
    }

    // should be unreachable
    cout << " ERROR: F***! no two ints found!" << endl;
    return -1;
}

