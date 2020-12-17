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
    const int nGrow = 6;
    const int wx = 8 + 2 * nGrow;
    const int wy = 8 + 2 * nGrow;
    const int wz = 1 + 2 * nGrow;

    int space_a[wx][wy][wz];
    int space_b[wx][wy][wz];

    // Initialize
    for (int ix = 0; ix < wx; ix++)
        for (int iy = 0; iy < wy; iy++)
            for (int iz = 0; iz < wz; iz++)
                space_a[ix][iy][iz] = space_b[ix][iy][iz] = 0;

    // Setup Generation
    for (int i=0;i<6;i++)
    {
        
    }
    return 0;
}
