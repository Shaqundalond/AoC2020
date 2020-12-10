/**
 * @file AoC-10.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #10
 * @version 0.1
 * @date 2020-12-10
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


// Function declarations
// =====================
int Puzzle_10(vector <int> iList, int iPuzzle);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 10",'=');

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
    int iResult = Puzzle_10(iList,1);

    return 0;
}




/**
 * @brief           AoC Puzzle
 * 
 * Counting all pairs with increments of 1 and 3. Multiply these numbers
 * 
 * @param vector<int>   list of ints
 * @return int          n - number of yes
 */
int Puzzle_10(vector<int> iList, int iPuzzle)
{
    int iResult = 0;
    
    // Step 0: Insert 0, since we begin at 0
    iList.push_back(0);

    // Step 1: Sort the List
    sort (iList.begin(), iList.end());

    // Step 2: count inc1 and inc3
    int n_i1 = 0;
    int n_i3 = 0;

    for (int i = 1; i < iList.size(); i++)
    {
        int inc = iList[i] - iList[i-1];
        if (inc == 1)
            n_i1++;
        else if (inc == 3)
            n_i3++;
    }

    iResult = n_i1 * n_i3;

    // should be unreachable
    cout << " ** Result: " << iResult << endl;
    return iResult;
}

