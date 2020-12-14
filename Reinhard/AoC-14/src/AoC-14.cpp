/**
 * @file AoC-14.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #14
 * @version 0.1
 * @date 2020-12-14
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


// Function declarations
// =====================
int Puzzle_14_1(vector <string> &sList);
int Puzzle_14_2(vector <string> &sList);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 14",'=');

    // Reading input strings
    vector<string> vs;
    if (ReadStrings("input.txt", vs) < 0)
    {
        cout << "---ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 
    Puzzle_14_1(vs);

    // Second puzzle of the day
    Puzzle_14_2(vs);

    return 0;
}

/**
 * @brief Create a mask for AND Operation
 * 
 * All Bits are 1 except those, which have to be 0
 * 
 * @param s         x=leave as is; 0=set to 0; 1=set to one
 * @return long 
 */
long make_mask_0(string s)
{
    long m = 0L;
    for (auto tc:s) {
        m <<= 1;
        if (tc == '0')
            m += 0;
        else
            m += 1;
    }
    return m;
}

/**
 * @brief Create a mask for OR Operation
 * 
 * All Bits are 0 except those, which have to be 1
 * 
 * @param s         x=leave as is; 0=set to 0; 1=set to one
 * @return long 
 */
long make_mask_1(string s)
{
    long m = 0L;
    for (auto tc:s) {
        m <<= 1;
        if (tc == '1')
            m += 1;
        else
            m += 0;
    }
    return m;
}



/**
 * @brief           AoC Puzzle
 * 
 * Part 1: Analysing a commandfile
 * 
 * Each memory pos has 36 Bits
 * there ist always a mask active:
 *      0 - Bit is set to 0
 *      1 - Bit is set to 1
 *      x - Bit is left as it is
 * File:
 * Mask = xxxx1xxxx0xx
 * mem[pos] = value (dec)
 * :
 * 
 * Remarks:
 * pos can be high (up to 100.000)
 * 
 * 
 * @param vector<string>   list of strings
 * @return int             0
 */
int Puzzle_14_1(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 14 Part 1",'=');

    string mask(36,'x');
    long mask_0 = 0L;
    long mask_1 = 0L;

    int iLine = 0;

    // 
    map<int,long> mem;

    for (auto ts : sList)
    {
        vector<string> xts = explode(ts,"[] =");
        if (xts.size() < 1)
            continue;

        if (xts[0] == "mask")
        {
            if (xts.size() < 2) {
                cout << " ** ERROR in Line: " << iLine+1 << " Invalid command: \"" << ts << "\"" << endl;
            }
            mask_0 = make_mask_0(xts[1]);
            mask_1 = make_mask_1(xts[0]);
        }
        else if (xts[0] == "mem")
        {
            if (xts.size() < 3) {
                cout << " ** ERROR in Line: " << iLine+1 << " Invalid command: \"" << ts << "\"" << endl;
            }
            int addr = stoi(xts[1]);
            long val = stol(xts[2]);

            val = val | mask_1;     // Set the 1 using binary or
            val = val & mask_0;     // Set the 0 using binay and
            mem[addr] = val;        // Store the value
        }
        iLine++;
    }

    // Add up all values
    long lResult = 0L;
    for (auto m : mem)
        lResult += m.second;

    cout <<" -- Sum of all Mem: " << lResult << endl;
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

int Puzzle_14_2(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 14 Part 2",'=');

    cout << " -- Nor yet implemented" << endl;

    return 0;
}


