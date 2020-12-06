/**
 * @file AoC-05.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #05
 * @version 0.1
 * @date 2020-12-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"

// Fcuntion declarations
int Puzzle_5(const vector<string> &vs, int iPuzzle);
bool CheckForKeyOccurance(const string& string2check, const string& key);


/**
 * @brief main (what else?)
 * 
 * @return int 
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 05",'=') << endl;

    // Reading input strings
    vector<string> vs;
    if (ReadStrings("input.txt", vs) < 0)
    {
        cout << "--- ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 04
    cout << MakeHeadline(" ** Puzzle 1: Highest Seat-ID",'~') << endl;
    int iHS_ID = Puzzle_5(vs,1);
    cout << " == Highest seat ID: " << iHS_ID << endl << endl;

    cout << MakeHeadline(" ** Puzzle 2: MySeat",'~') << endl;
    int iMySeatID = Puzzle_5(vs,2);
    cout << endl << " == My seat ID: " << iMySeatID << endl << endl;

    return 0;
}


/**
 * @brief           AoC Puzzle
 * 
 * Calculating the seat ID from a string
 * Findign Row w/
 * - F Front half Row
 * - B Back half Row
 * - R Richt half Column
 * - L Left half Column
 * in total there are 128 Rows s/ 8 Columns each
 * 
 * Seat ID = row * 8 + col
 * 
 * @param vs        vector<string> with treemap
 * @param iPuzzle   - 1 oder - 2
 * @return int      n - highest seat ID
 */
int Puzzle_5(const vector<string> &vs, int iPuzzle)
{
    int iID = 0;
    int iIDMax = 0;
    int iMySeat = 0;
    vector <int> seatIDs(1024,0);
    for (string ts : vs)
    {
        if (ts.length() < 10)
        {
            cout << " *** Error in string: too short [" << ts << "]" << endl;
        }
        else
        {
            iID = 0;
            for (int i = 0; i < 10; i++)
            {
                iID <<= 1;
                if (ts[i] == 'B' || ts[i] == 'R')
                {
                    iID += 1;
                }
                else if (ts[i] == 'F' || ts[i] == 'L')
                {
                    iID += 0;
                }
                else
                {
                    cout << " *** Error in string: invalid character [" << ts << "]" << endl;
                }
            }
        }

        cout << ts << " = " << iID << endl;

        if (iID < seatIDs.size())
            seatIDs[iID]++;

        if (iID > iIDMax)
            iIDMax = iID;
    }

    // finding the seat not in the list but seatID +1 and seatID-1 are in the thist
    for (int i=0; i < 1024; i++)
    {
        if (seatIDs[i] == 0 && seatIDs[i-1] > 0 && seatIDs[i+1] > 0 && i >0 && i < 1023)
        {
            cout << "*";
            iMySeat = i;
        }
        else if (seatIDs[i] == 0)
        {
           cout << ".";
        }
         else
         {
            cout << seatIDs[i];             
         }

        if ((i+1) % 8 == 0)
            cout << endl;
        else
            cout << "  ";
    }

    if (iPuzzle == 1)
        return iIDMax;
    else
        return iMySeat;
        
}


