/**
 * @file AoC-12.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #13
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


// Function declarations
// =====================
int Puzzle_13_1(vector <string> &sList);
int Puzzle_13_2(vector <string> &sList);


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
    Puzzle_13_1(vs);

    // Second puzzle of the day
    Puzzle_13_2(vs);

    return 0;
}




/**
 * @brief           AoC Puzzle
 * 
 * Part 1: Finding departure of next bus and it's ID
 * 
 * 
 * 
 * @param vector<string>   list of strings
 * @return int             0
 */

int Puzzle_13_1(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 13 Part 1",'=');

    int iNextBus = 0;
    int iNextDeparture = 0;
    int iCount = 0;

    int tNow = atoi(sList[0].c_str());
    vector<string> busses = explode(sList[1],","); 

    for (auto tbus : busses)
    {
        if (tbus == "x")
            continue;

        int iLine = atoi(tbus.c_str());
        int nextDeparture = iLine - (tNow % iLine);
 
        cout << "  -- Testing " << iLine << " nextDep=" << nextDeparture << endl;

        if (iCount == 0 || nextDeparture < iNextDeparture)
        {
            iNextBus = iLine;
            iNextDeparture = nextDeparture;
        }

        iCount++;        
    }

    int iCode = iNextBus * iNextDeparture;
    cout << " ** Results:" << endl;
    cout << "    Now:            " << tNow << endl;
    cout << "    Next Departure: " << iNextDeparture << endl;
    cout << "    w/ Bus Line:    " << iNextBus << endl;
    cout << "    Code:           " << iCode << endl;

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

int Puzzle_13_2(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 13 Part 2",'=');

    int iLine = 0;
    return 0;
}


