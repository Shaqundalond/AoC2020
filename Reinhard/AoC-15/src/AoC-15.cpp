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
int Puzzle_15_1(vector <string> &sList);
int Puzzle_15_2(vector <string> &sList);


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
    Puzzle_15_1(vs);

    // Second puzzle of the day
    // Puzzle_15_2(vs);

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
int Puzzle_15_1(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 15 Part 1",'=');

    vector<string> XS = explode(sList[0],",");
    vector<int> vCard;
    
    // First saying from input
    
    int iStep = 1;
    int iLast = 0;
    vCard.push_back(-1);
    for (auto ts: XS)
    {
        iLast = stoi(ts);
        vCard.push_back(iLast);
        iStep++;
    }

    for (  ; iStep <= 2020; iStep++ ) 
    {
        // find iLast
        int iNext = 0;
        int iFound = -1;
        for (int j = iStep-2; j >= 0; j--)
        {
            if (vCard[j] == iLast)
            {
                iNext = iStep-1-j;
                iFound = j;
                j = -1;
            }
        }
        //cout << iStep << " iLast: " << iLast << " Found at: " << iFound << " iNext:" << iNext << endl;

        iLast = iNext;
        vCard.push_back(iNext);
    }
    
    cout <<" -- Last call: " << iLast << endl;
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


