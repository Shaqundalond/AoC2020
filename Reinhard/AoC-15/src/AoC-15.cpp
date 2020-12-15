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
    vector<int> t_iCard(2021,-1);        // 2021 entries, initialized w/ -1

    // First saying from input
    int iStep  = 1;
    int iCard = 0;
    int iNextCard = 0;

    for (auto ts: XS)
    {
        iCard = stoi(ts); 
        t_iCard[iCard] = iStep++;    // the number iCard was called at iStep
    }

    for (  ; iStep <= 2020; iStep++ ) 
    {
        int iLastStep = t_iCard[iCard];

        if (iLastStep >= 0)
            iNextCard = iStep - iLastStep;
        else
            iNextCard = 0;
        
        t_iCard[iNextCard] = iStep;
        iCard = iNextCard;
    }
    
    cout <<" -- Last call: " << iCard << endl;
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


