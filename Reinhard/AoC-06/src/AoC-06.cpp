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
int Puzzle_6(const vector<string> &vs);


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
    if (ReadMultilineStrings("input.txt", vs, "") < 0)
    {
        cout << "--- ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 
    cout << MakeHeadline(" ** Puzzle 1: Counting valid Yes-answers",'~') << endl;
    int iYes = Puzzle_6(vs);

    cout << " == Nnumber of Yes: " << iYes << endl;

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
int Puzzle_6(const vector<string> &vs)
{
    int iN = 0;
    int iCountYes = 0;

    for (string ts : vs)
    {
        vector<int> nchar(26,0);
 
        // getting index of each character (never trust any data at this point, since our array is limited in size)
        for (char tch :ts)
        {
            int ich = tch - 'a';
            if (ich >= 0 && ich < 26)
                nchar[ich] += 1;
            else
                cout << " *** ERROR unknown character in line " << iN << " [" << ts << "]  char='" << tch << "]" << endl;
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




