/**
 * @file AoC-06.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #06
 * @version 0.1
 * @date 2020-12-06
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"

// Function declarations
int Puzzle_6_1(const vector<string> &vs);
int Puzzle_6_2(const vector<string> &vs);


/**
 * @brief main (what else?)
 * 
 * @return int 
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 06",'=') << endl;

    // Reading input strings
    vector<string> vs;
    if (ReadMultilineStrings("input.txt", vs, " ") < 0)
    {
        cout << "--- ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 
    cout << MakeHeadline(" ** Puzzle 1: Counting anyone Yes-answers",'~') << endl;
    int iYes = Puzzle_6_1(vs);
    cout << " == Number of Yes from anyone: " << iYes << endl;

    // second puzzle of day 
    cout << MakeHeadline(" ** Puzzle 2: Counting everyone Yes-answers",'~') << endl;
    iYes = Puzzle_6_2(vs);
    cout << " == Number of Yes from everyone: " << iYes << endl;

    return 0;
}


/**
 * @brief           AoC Puzzle
 * 
 * Count the numer of yes
 * - Readl als groups spread over more than one line and count the number of different characters
 * - add them all up to the result
 * 
 * @param vs        vector<string> with treemap
 * @return int      n - number of yes
 */
int Puzzle_6_1(const vector<string> &vs)
{
    int iN = 0;
    int iCountYes = 0;

    for (string ts : vs)
    {
        vector<int> nchar(26,0);
 
        // getting index of each character (there could be other characters i.e. separators in each line)
        for (char tch :ts)
        {
            int ich = tch - 'a';
            if (ich >= 0 && ich < 26)
                nchar[ich] += 1;
        }

        // Counting entries > 0
        int nyes = 0;
        for (int nch : nchar)
        {
            if (nch > 0)
                nyes += 1;
        }
        iCountYes += nyes;

        // Debugging only
        cout << nyes << " -- " << ts << endl;

        // next Line
        iN += 1;
    }
    return iCountYes;
}

/**
 * @brief           AoC Puzzle
 * 
 * Count the numer of yes
 * - Read als groups spread over more than one line and count the number of different characters
 * - add them all up to the result
 * 
 * @param vs        vector<string> with treemap
 * @return int      n - number of yes
 */
int Puzzle_6_2(const vector<string> &vs)
{
    int iN = 0;
    int iCountYes = 0;

    for (string ts : vs)
    {
        vector<int> nchar(26,0);
 
        // explode the line
        vector<string> tsx = explode (ts, " ");

        int ii = 0;
        for (auto ttsx : tsx)
        {
            // getting index of each character (never trust any data at this point, since our array is limited in size)
            vector<int> tnchar(26,0);
            for (char tch :ttsx)
            {
                int ich = tch - 'a';
                if (ich >= 0 && ich < 26)
                {
                    tnchar[ich] = 1;
                }
            }

            // Vergleich mit den bisherigen Antworten
            for(int k=0; k<26; k++)
            {
                if (ii == 0)
                    nchar[k] = tnchar[k];
                else
                    nchar[k] = nchar[k] * tnchar[k];                
            }

            ii += 1;
        }

        // Counting entries > 0
        int nyes = 0;
        for (int nch : nchar)
        {
            if (nch > 0)
                nyes += 1;
        }
        iCountYes += nyes;

        // Debugging only
        cout << nyes << " -- " << ts << endl;
        for (auto ttsx : tsx)
            cout << "    + " << ttsx << endl;

        // next Line
        iN += 1;
    }
    return iCountYes;
}







