/**
 * @file AoC.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #17
 * @version 0.1
 * @date 2020-12-17
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


// Function declarations
// =====================
int Puzzle_17(vector <string> &sList);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main(int argc, char** argv)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 17",'*');

    // Reading input strings
    string fn = "input.txt";
    if (argc > 1)
        fn.assign(argv[1]);

    vector<string> vs;
    if (ReadStrings(fn, vs) < 0)
    {
        cout << "---ERROR Reading strings from file ["<<fn<<"] Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 
    Puzzle_17(vs);

    // Second puzzle of the day
    // Puzzle_17(vs);

    return 0;
}


/**
 * @brief Typedefinitions
 * 
 */

typedef vector<char> line_t;
typedef vector<line_t> slice_t;
typedef vector<slice_t> space_t;

int SetupSpace(space_t s, const vector<string> &sList)
{


    return 0;
}

/**
 * @brief           AoC Puzzle
 * 
 * Part 1: Playing game of life in 3Dim
 * 
 * @param vector<string>   list of strings
 * @return int             0
 */
int Puzzle_17(vector<string> &sList)
{

    space_t space_a;
    space_t space_b;
    
    int nGrow = 6;
    int s_line  = sList[0].size() + 2*nGrow;
    int s_slice = sList.size() + 2*nGrow;
    int s_space = 1 + 2*nGrow;

    line_t line_0(' ',s_line);
    slice_t slice_0(line_0,s_slice);
    // Setup
    for (int i = 0; i < s_space; i++)
        for (int j = 0; j < s_slice; j++)
            space_a[j][j].push_back()

    SetupSpace(space_a,sList);

    // Initialice
    return 0;
}
