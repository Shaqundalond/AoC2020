/**
 * @file AoC-15.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #15
 * @version 0.1
 * @date 2020-12-15
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


// Function declarations
// =====================
int Puzzle_15(vector <string> &sList, int nSteps);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 15",'=');

    // Reading input strings
    vector<string> vs;
    if (ReadStrings("input.txt", vs) < 0)
    {
        cout << "---ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 
    Puzzle_15(vs, 2020);

    // Second puzzle of the day
    Puzzle_15(vs, 30000000);

    return 0;
}



/**
 * @brief           AoC Puzzle
 * 
 * Part 1: Plying memory
 * 
 * @param vector<string>   list of strings (only one string)
 * @return int             0
 */
int Puzzle_15(vector<string> &sList, int nSteps)
{
    vector<string> XS = explode(sList[0],",");
    vector<int> vCard;
    
    // First saying from input
    
    int iStep = 1;
    int iLast = 0;
    map<int,int> mCard;

    for (iStep=1; iStep < XS.size(); iStep++)
    {
        iLast = stoi(XS[iStep-1]);
        mCard[iLast] = iStep;
        iLast = stoi(XS[iStep]);
    }
    iStep++;

    for ( ; iStep <= nSteps; iStep++ ) 
    {
        // find iLast
        auto pos = mCard.find(iLast);
        int iNext = 0;
        if ( pos != mCard.end() )
        {
            iNext = iStep-1 - pos->second;
        }
 
        mCard[iLast] = iStep-1;
        iLast = iNext;
    }
    
    cout << endl;
    cout <<" -- Last call (" << nSteps << ") : " << iLast << endl;
    cout << endl;

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

int Puzzle_15_2(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 15 Part 2",'=');
 

    cout <<" -- Not yet implemented!" << endl;
    cout << endl;

    return 0;
}


