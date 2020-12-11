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
int Puzzle_11(vector <string> &sList);


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
    int iResult = Puzzle_11(vs);

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
bool NextGen(vector<string> &va, vector<string> &vb)
{
    bool bChanged = false;
    int nS=0;
    for (int i = 0; i < va.size(); i++)
    {
        for (int j = 0; j < va[i].size(); j++)
        {
            char ta = va[i][j];
            if (ta == 'L')
            {
                nS = count_surrounding(va,i,j,'#');
                if (nS == 0) {
                    vb[i][j] = '#';
                    bChanged = true;
                }
            }
            else if (ta == '#')
            {
                nS = count_surrounding(va,i,j,'#');
                if (nS >= 4) {
                    vb[i][j] = 'L';
                    bChanged = true;
                }
            }
            cout << nS;
        }
        cout << endl;
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
int Puzzle_11(vector<string> &sList)
{
    bool bChange = true;
    int iCount = 0;

    vector<string> aL(sList.size());
    vector<string> bL(sList.size());

    for (int i = 0; i < sList.size(); i++) {
        aL[i] = sList[i];
        bL[i] = sList[i];
    }

    int iState = 0;     // no special meaning; just r1 -> aL and r2 -> bL
    int nGen = 0;       // Number of generations
        
    while (bChange)
    {
        nGen++;
        if (iState == 0) {
            bChange = NextGen(aL,bL);
            iState = 1;
        } else {
            bChange = NextGen(bL,aL);
            iState = 0;
        }

        iCount = count_cX(bL,'#');
        cout << " -- Gen: " << nGen; 
        cout << " iState: " << iState; 
        cout << " Count: " << iCount;
        cout << " cChange: " << bChange << endl;
        int iWait =0;
        cin >> iWait;
    }


    cout << " ** Number of occupied seats: " << iCount << endl;
    cout << "    Number of generations:    " << nGen << endl;
    return iCount;
}

