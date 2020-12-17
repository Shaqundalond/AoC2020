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
#include "StopWatch.h"


// Function declarations
// =====================
int Puzzle_17(vector <string> &sList);
int Puzzle_17_2(vector <string> &sList);


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

    StopWatch watch;

    // first puzzle of day 
    Puzzle_17(vs);

    cout << "Part One takes " << watch.Lap() << " sec." << endl << endl;

    // Second puzzle of the day
    Puzzle_17_2(vs);

    cout << "Part Two takes " << watch.Lap() << " sec." << endl << endl;

    return 0;
}

const int nGrow = 6;
const int wx0 = 8;
const int wy0 = 8;
const int wx = wx0 + 2 * nGrow;
const int wy = wy0 + 2 * nGrow;
const int wz = 1 + 2 * nGrow;
const int ww = 1 + 2 * nGrow;

// three dim
int space_a[wx][wy][wz];
int space_b[wx][wy][wz];

// four dim
int space_4a[wx][wy][wz][ww];
int space_4b[wx][wy][wz][ww];


int CountNeighbors(int x, int y, int z)
{
    int nn= 0;
    for (int ix = (x-1); ix <= (x+1); ix++)
    {
        if (ix < 0 || ix >= wx)
            continue;
        for(int iy = (y-1); iy <= (y+1); iy++)
        {
            if (iy < 0 || iy >= wy)
                continue;
            for(int iz = (z-1); iz <= (z+1); iz++)
            {
                if (iz < 0 || iz >= wz)
                    continue;
                if (ix == x && iy == y && iz == z)
                    continue;

                if (space_a[ix][iy][iz] == 1)
                    nn++;             
            }
        }
    }
    return nn;
}

int CountNeighbors_4(int x, int y, int z, int w)
{
    int nn= 0;
    for (int ix = (x-1); ix <= (x+1); ix++)
    {
        if (ix < 0 || ix >= wx)
            continue;
        for(int iy = (y-1); iy <= (y+1); iy++)
        {
            if (iy < 0 || iy >= wy)
                continue;
            for(int iz = (z-1); iz <= (z+1); iz++)
            {
                if (iz < 0 || iz >= wz)
                    continue;
                for (int iw =(w-1); iw <= (w+1); iw++)
                {
                    if (ix == x && iy == y && iz == z && iw == w)
                        continue;

                    if (space_4a[ix][iy][iz][iw] == 1)
                        nn++;   
                }          
            }
        }
    }
    return nn;
}


int NextGen()
{
    int nCount = 0;
    for(int ix = 0; ix < wx; ix++)
        for(int iy = 0; iy < wy; iy++)
            for(int iz = 0; iz < wz; iz++)
            {
                int nn = CountNeighbors(ix,iy,iz);
                if (space_a[ix][iy][iz] == 1)
                {
                    if (nn == 2 || nn == 3)
                    {
                        space_b[ix][iy][iz] = 1;
                        nCount++;
                    }
                    else
                    {
                        space_b[ix][iy][iz] = 0; 
                    }                   
                }
                else
                {
                    if (nn == 3)
                    {
                        space_b[ix][iy][iz] = 1;
                        nCount++;
                    }
                    else
                    {
                        space_b[ix][iy][iz] = 0;
                    }
                }
            }

    return nCount;
}

int NextGen4()
{
    int nCount = 0;
    for(int ix = 0; ix < wx; ix++)
        for(int iy = 0; iy < wy; iy++)
            for(int iz = 0; iz < wz; iz++)
                for(int iw = 0; iw < ww; iw++)
                {
                    int nn = CountNeighbors_4(ix,iy,iz,iw);
                    if (space_4a[ix][iy][iz][iw] == 1)
                    {
                        if (nn == 2 || nn == 3)
                        {
                            space_4b[ix][iy][iz][iw] = 1;
                            nCount++;
                        }
                        else
                        {
                            space_4b[ix][iy][iz][iw] = 0; 
                        }                   
                    }
                    else
                    {
                        if (nn == 3)
                        {
                            space_4b[ix][iy][iz][iw] = 1;
                            nCount++;
                        }
                        else
                        {
                            space_4b[ix][iy][iz][iw] = 0;
                        }
                    }
                }

    return nCount;
}


int CopySpace()
{
    for (int ix = 0; ix < wx; ix++)
        for (int iy = 0; iy < wy; iy++)
            for (int iz = 0; iz < wz; iz++)
                space_a[ix][iy][iz] = space_b[ix][iy][iz];
    return 0;
}

int CopySpace4()
{
    for (int ix = 0; ix < wx; ix++)
        for (int iy = 0; iy < wy; iy++)
            for (int iz = 0; iz < wz; iz++)
                for(int iw = 0; iw < ww; iw++)
                    space_4a[ix][iy][iz][iw] = space_4b[ix][iy][iz][iw];
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

    cout << MakeHeadline("Conways life in 3 Dim",'-');

    // Initialize
    for (int ix = 0; ix < wx; ix++)
        for (int iy = 0; iy < wy; iy++)
            for (int iz = 0; iz < wz; iz++)
                space_a[ix][iy][iz] = space_b[ix][iy][iz] = 0;

    // Setup Generation
    for (int i=0;i<sList.size();i++)
        for (int j=0;j<sList[i].size();j++)
            space_a[i+6][j+6][6] = ((sList[i][j] == '#') ? 1:0);


    // Now 6 Generations
    int nCount = 0;
    for (int iGen = 0; iGen < 6; iGen++)
    {
        nCount = NextGen();      // a-> b
        cout << " Generation: " << iGen << " Counting active cubes: " << nCount << endl;

        CopySpace();             // b -> a   
    }

    return 0;
}

int Puzzle_17_2(vector<string> &sList)
{
    cout << MakeHeadline("Conways life in 4 Dim",'=');

    // Initialize
    for (int ix = 0; ix < wx; ix++)
        for (int iy = 0; iy < wy; iy++)
            for (int iz = 0; iz < wz; iz++)
                for(int iw = 0; iw < ww; iw++)
                    space_4a[ix][iy][iz][iw] = space_4b[ix][iy][iz][iw] = 0;

    // Setup Generation
    for (int i=0;i<sList.size();i++)
        for (int j=0;j<sList[i].size();j++)
            space_4a[i+6][j+6][6][6] = ((sList[i][j] == '#') ? 1:0);


    // Now 6 Generations
    int nCount = 0;
    for (int iGen = 0; iGen < 6; iGen++)
    {
        nCount = NextGen4();      // a-> b
        cout << " Generation: " << iGen << " Counting active cubes in 4Dim: " << nCount << endl;

        CopySpace4();             // b -> a   
    }

    return 0;
}