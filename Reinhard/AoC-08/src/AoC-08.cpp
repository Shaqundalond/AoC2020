/**
 * @file AoC-07.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #08
 * @version 0.1
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"
#include "MyCPU.h"

// Function declarations
// =====================
int Puzzle_8( MyProgram &prog, int iPuzzle);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 08",'=') << endl;

    // Reading input strings
    vector<string> vs;
    if (ReadStrings("input.txt", vs) < 0)
    {
        cout << "---ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // Frist step: compile the inputstring to a program
    MyProgram prog(vs.size());
    for (int i=0; i < vs.size(); i++)
        prog[i].FromString(vs[i]);

    // first puzzle of day 
    cout << MakeHeadline(" ** Puzzle 1: content of acc",'~') << endl;
    int acc = Puzzle_8(prog,1);
    cout << " == Content of accumulator: " << acc << endl;

    return 0;
}




/**
 * @brief           AoC Puzzle
 * 
 * Count the numer of yes
 * - Readl als groups spread over more than one line and count the number of different characters
 * - add them all up to the result
 * 
 * @param vs        vector<bag>
 * @return int      n - number of yes
 */
int Puzzle_8( MyProgram &prog, int iPuzzle)
{
    int iResult = 0;
    MyCPU cpu;

    if (iPuzzle == 1)
    {
        iResult = cpu.Run(prog);
    }
    else
    {
        
    }
    
    return iResult;
}

