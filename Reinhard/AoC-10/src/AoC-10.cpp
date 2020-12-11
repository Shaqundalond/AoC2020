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
long mysearch(vector<int> &vect, vector<long> &sCount, int iStep);


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

    // And don't forget:
    // Am Anfang haben wir eine Stufe von 0 auf 1
    // und Am Ende der interne Adapter nochmal eine Stufe um 3 Jolts
    iResult = (n_i1+1) * (n_i3+1);

    // should be unreachable
    cout << " ** Result Part 1: " << iResult << endl;


    // Step 2: find all paht to the end
    vector<long> sCount(iList.back() + 1, -1);
    for (auto ii : iList)
        sCount[ii] = 0;

    long lResult = mysearch(iList, sCount, iList.back());

    cout << " ** Result part 2: " << lResult << endl;

    return iResult;
}

long mysearch(vector<int> &vect, vector<long> &sCount, int iStep)
{
	long lCount = 0;

	// End of searching
	if (iStep == 0) 
        return 1;
	if (iStep < 0) 
        return 0;

    // is this a valid step ??
	if (sCount[iStep] == -1)
        // Nope - no wa to this step
        return 0;

	//has this step already been caluclated
	if (sCount[iStep] > 0 ) 
        return sCount[iStep];

	//recursive stearch
	lCount += mysearch(vect, sCount, iStep - 1);
	lCount += mysearch(vect, sCount, iStep - 2);
	lCount += mysearch(vect, sCount, iStep - 3);

	sCount[iStep] = lCount;
	return lCount;
}

