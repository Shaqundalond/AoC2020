/**
 * @file AoC-13.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #13
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


// Function declarations
// =====================
int Puzzle_13_1(vector <string> &sList);
int Puzzle_13_2(vector <string> &sList);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 13",'=');

    // Reading input strings
    vector<string> vs;
    if (ReadStrings("input.txt", vs) < 0)
    {
        cout << "---ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 
    Puzzle_13_1(vs);

    // Second puzzle of the day
    Puzzle_13_2(vs);

    return 0;
}




/**
 * @brief           AoC Puzzle
 * 
 * Part 1: Finding departure of next bus and it's ID
 * 
 * 
 * 
 * @param vector<string>   list of strings
 * @return int             0
 */

int Puzzle_13_1(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 13 Part 1",'=');

    int iNextBus = 0;
    int iNextDeparture = 0;
    int iCount = 0;

    int tNow = atoi(sList[0].c_str());
    vector<string> busses = explode(sList[1],","); 

    for (auto tbus : busses)
    {
        if (tbus == "x")
            continue;

        int iLine = atoi(tbus.c_str());
        int nextDeparture = iLine - (tNow % iLine);
 
        cout << "  -- Testing " << iLine << " nextDep=" << nextDeparture << endl;

        if (iCount == 0 || nextDeparture < iNextDeparture)
        {
            iNextBus = iLine;
            iNextDeparture = nextDeparture;
        }

        iCount++;        
    }

    int iCode = iNextBus * iNextDeparture;
    cout << " ** Results:" << endl;
    cout << "    Now:            " << tNow << endl;
    cout << "    Next Departure: " << iNextDeparture << endl;
    cout << "    w/ Bus Line:    " << iNextBus << endl;
    cout << "    Code:           " << iCode << endl;

    return 0;
}

/**
 * @brief Aber Hallo
 * 
 * Suche das erste gemeinsame Vielfache von zwei Perioden, wenn die erste einen Startpunkt t0 hat
 * und die zweite eine offset von d1 haben soll
 * Es ist zu erwarten, dass p0 deutlich größer sein kann als p1
 * 
 * @param t0        - Startpunkt von p0
 * @param p0        - Periode von p0
 * @param d1        - Offset von p1
 * @param p1        - Periode von p1
 * @return long     - Anzahl perioden von p1
 */
long find_n1(long t0, long p0, long d1, long p1)
{
    long n0 = 0;
    long n1 = 0;

    while (true)
    {
        long e0 = t0 + n0 * p0 + d1;
        long e1 = n1 * p1;

        if (e0 == e1)
            break;      // Ooooh - What a lucky man you are
        else if (e0 > e1)
            n1 += max(1L,(e0 - e1) / p1);
        else 
            n0 += max(1L,(e1 - e0) / p0);
    }
    return n1;
}

/**
 * @brief           AoC Puzzle
 * 
 * Part 2:
 * 
 * @param vector<string>   list of strings
 * @return int             0
 */

int Puzzle_13_2(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 13 Part 2",'=');

    vector<string> vsBusses = explode(sList[1],","); 

    vector<int> vBus;
    vector<int> vOffset;
    int ti = 0;
    for (auto sB : vsBusses)
    {
        if (sB != "x") {
            vBus.push_back(atoi(sB.c_str()));
            vOffset.push_back(ti);
        }
        ti++;
    }

    for (int i = 0; i < vBus.size(); i++ )
        cout << " -- " << i << " Busline: " << vBus[i] << " Offset: " << vOffset[i] << endl;

    cout << " *** sizeof(long) :" << sizeof(long) << " Max Long: " << endl;

    long t0 = 0;
    long n0 = 0;
    long p0 = vBus[0];

    for (int i = 1; i < vBus.size(); i++)
    {
        int d1 = vOffset[i] - vOffset[i-1];
        int p1 = vBus[i];
        long n1 = find_n1(t0,p0,d1,p1);
        t0 = n1*p1;
        p0 = p0*p1;

        cout << "   Next step: t0: " << t0 << " p0: " << p0 << endl;
    }

    long iResult = t0 - vOffset.back();
    cout << " ** Ergebnis: " << iResult << endl;

    return 0;
}


