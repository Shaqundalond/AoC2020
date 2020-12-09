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
int Puzzle_9(vector <int> iList);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main()
{

    cout << endl << MakeHeadline("Advent of Code 2020 Puzzle # 09",'*');

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
    int iResult = Puzzle_9(iList);

    return 0;
}




/**
 * @brief           AoC Puzzle
 * 
 * Part 1:
 * - searching a number which is NOT the sum of any two ints from the last 25 ints behind.
 * 
 * Part 2:
 * - searching a cobtigous set of numbers which sums up to this number; add the smallest und largest numer in this set.
 * 
 * 
 * @param vector<int>   list of ints
 * @return int          1 - finished part 1
 *                      2 - finished part 1 and part 2
 *                     -1 - Error solving part 1
 */
int Puzzle_9(vector<int> iList)
{
    int iResult = 0;
    int ci = 0;
    int iSpecial = 0;

    for (ci = 25; ci < iList.size(); ci++)
    {
        int iTarget = iList[ci];    // this should be the sum 
        bool found = false;
        for (int i = 0; i < (25-1); i++)
        {
            for (int j = i+1; j < 25; j++)
            {
                int ti = ci - 25 + i;
                int tj = ci - 25 + j;
                int iSum = iList[ti] + iList[tj];
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
            iSpecial = iList[ci];
            cout << " ** PART 1 -- @ i= " << ci << " Value is: " << iSpecial << endl;
            break;
        }
    }

    // Continuing w/ part 2
    int i1 = 0;
    int i2 = 0;

    int iMinMax = -1;

    for (i1 = 0; i1 < iList.size()-1; i1++)
    {
        i2 = i1+1;
        int iSum = iList[i1];
        for (i2 = i1+1; i2 < iList.size(); i2++)
        {
            iSum += iList[i2];
            if (iSum == iSpecial)
            {
                int iMin = iList[i1];
                int iMax = iMin;
                // set found - now find min and max
                for (int i=i1; i <=i2; i++)
                {
                    iMin = min(iMin,iList[i]);
                    iMax = max(iMax,iList[i]);
                }
                iMinMax = iMin + iMax;
                cout << " ** PART 2 (a) -- from " << i1 << " to " << i2 << " the sum of min and Max: " << iMinMax << endl; 
                i1 = i2 = iList.size();     // this will break all for loops
                break;                      // not really neaded
            }
        }
    } 

    // Variante zwei
    i1 = 0; 
    i2 = i1 + 1;
    int iSum = iList[i1];
    while (true)
    {
        if (iSum < iSpecial)
        {
            i2 += 1;
            if (i2 >= iList.size())
            {
                cout << " !! ERROR i2 > iList.size()" << endl;
                break;
            }
            iSum += iList[i2];
        }
        else if (iSum > iSpecial)
        {
            i1 += 1;
            if (i1 >= i2 || i1 >= iList.size())
            {
                cout << " !! ERROR i1 out of range: " << i1 << " i2: " << i2 << endl;
                break;
            }
            iSum -= iList[i1-1];
        }
        else
        {
            int iMin = iList[i1];
            int iMax = iMin;
            // set found - now find min and max
            for (int i=i1; i <=i2; i++)
            {
                iMin = min(iMin,iList[i]);
                iMax = max(iMax,iList[i]);
            }
            iMinMax = iMin + iMax;
            cout << " ** PART 2 (b) -- from " << i1 << " to " << i2 << " the sum of min and Max: " << iMinMax << endl; 
            i1 = i2 = iList.size();     // this will break all for loops
            break;                      // not really neaded
        }
        
    }


    return 0;
}

