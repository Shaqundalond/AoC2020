/**
 * @file AoC-11.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #11
 * @version 0.1
 * @date 2020-12-11
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


// Function declarations
// =====================
int Puzzle_11(vector <string> &sList, int iMethod);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 11",'=');

    // Reading input strings
    vector<string> vs;
    if (ReadStrings("input.txt", vs) < 0)
    {
        cout << "---ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 
    Puzzle_11(vs,1);

    // Second puzzle of the day
    Puzzle_11(vs,2);

    return 0;
}


/**
 * @brief       Transforms va into vb
 * 
 * @param va 
 * @param vb 
 * @return true     - there are changes
 * @return false    - there are NO changes
 */
bool NextGen(vector<string> &va, vector<string> &vb, int iPuzzle)
{
    bool bChanged = false;
    int nS=0;
    int nMax = 0;
    if (iPuzzle == 1)
        nMax = 4;
    else
        nMax = 5;
    
    for (int i = 0; i < va.size(); i++)
    {
        for (int j = 0; j < va[i].size(); j++)
        {
            char ta = va[i][j];
            vb[i].at(j) = ta;
            if (ta == 'L')
            {
                nS = count_surrounding(va,i,j,'#',iPuzzle);
                if (nS == 0) {
                    vb[i].at(j) = '#';
                    bChanged = true;
                }
            }
            else if (ta == '#')
            {
                nS = count_surrounding(va,i,j,'#',iPuzzle);
                if (nS >= nMax) {
                    vb[i].at(j) = 'L';
                    bChanged = true;
                }
            }            
        }
    }

    return bChanged;
}

/**
 * @brief           AoC Puzzle
 * 
 * Part 1:
 * - Play special Version of "game of life"
 * 
 * @param vector<string>   list of strings
 * @return int             0
 */
int Puzzle_11(vector<string> &sList, int iPuzzle)
{
    if (iPuzzle == 1)
        cout << MakeHeadline("Advent of Code 2020 Puzzle # 11 Part 1",'=');
    else
        cout << MakeHeadline("Advent of Code 2020 Puzzle # 11 Part 2",'=');        

    bool bChange = true;
    int iCount = 0;

    vector<string> aL = sList;
    vector<string> bL = sList;

    int iState = 0;     // no special meaning; just r1 -> aL and r2 -> bL
    int nGen = 0;       // Number of generations
    
    while (bChange)
    {
        cout << endl << " --Looking for Gerneration: " << nGen+1 << endl;
        nGen++;
        if (iState == 0) {
            bChange = NextGen(aL,bL,iPuzzle);
            iState = 1;
        } else {
            bChange = NextGen(bL,aL,iPuzzle);
            iState = 0;
        }

        iCount = count_cX(bL,'#');
        cout << " ** Number of occupied seats: " << iCount << endl;
    }

    return iCount;
}

