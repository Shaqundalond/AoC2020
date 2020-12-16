/**
 * @file AoC-16.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #16
 * @version 0.1
 * @date 2020-12-16
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"


// Function declarations
// =====================
int Puzzle_16(vector <string> &sList);


/**
 * @brief main (what else?)
 * 
 * @return int 1 - Error
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 16",'*');

    // Reading input strings
    vector<string> vs;
    if (ReadStrings("input.txt", vs) < 0)
    {
        cout << "---ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 
    Puzzle_16(vs);

    // Second puzzle of the day
    // Puzzle_16(vs);

    return 0;
}


/**
 * @brief Typedefinitions
 * 
 */

typedef vector<int> ticket_t;
typedef struct rule_s
{
    string m_key;
    int m_from1;
    int m_to1;
    int m_from2;
    int m_to2;
} rule_t;

int GetTicket(string ts, ticket_t &t)
{
    int iCount = 0;
    vector<string> xts = explode(ts,",");
    for(auto tts : xts)
    {
        if (iCount == 0)
            t.clear();
        t.push_back(stoi(tts));
        iCount++;
    }
    return iCount;
}

bool IsValidNumber(int number, vector<rule_t> &rules)
{
    int bValid = false;
    for(auto r:rules)
    {
        if ((number >= r.m_from1) && (number <= r.m_to1) ||
            (number >= r.m_from2) && (number <= r.m_to2))
        {
            bValid = true;
            break;
        }
    }

    return bValid;
}

/**
 * @brief           AoC Puzzle
 * 
 * Part 1: Checking valid tickets
 * 
 * @param vector<string>   list of strings (only one string)
 * @return int             0
 */
int Puzzle_16(vector<string> &sList, int nSteps)
{
    vector<string> XS = explode(sList[0],",");

    int iSum = 0;

    // Data from Input.txt
    vector<rule_t> rules;
    vector<ticket_t> tickets;
    ticket_t myTicket;

    // Analysing input file
    int section = 1;        // starting w/ rules
    for (auto ts:XS)
    {
        if (ts.size() == 0) {
            section += 1;
            continue;
        }

        if (section == 1)
        {
            vector<string> xr = explode(ts,":");
            if (xr.size() == 2)
            {
                rule_t r;
                r.m_key = xr[0];
                vector<string> xxr = explode(xr[1]," or-");
                if (xxr.size() == 4)
                {
                    r.m_from1 = stoi(xxr[0]);
                    r.m_to1   = stoi(xxr[1]);
                    r.m_from2 = stoi(xxr[2]);
                    r.m_to2   = stoi(xxr[3]);
                }
            }
        }

        if (section == 2)
        {
            GetTicket(ts,myTicket);
        }

        if (section == 3)
        {
            ticket_t t;
            if (1 < GetTicket(ts,t))
                tickets.push_back(t);
        }
    }

    // Now count the invalid tickets
    for ( auto t : tickets)
    {
        for ( auto in : t)
        {
            if (!IsValidNumber(in,tickets))
                iSum += in;
        }
    }

    // Finally write the results
    cout << endl;
    cout <<" -- sum of invalid ticketnumbers: " << iSum << endl;
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

int Puzzle_15_2(vector<string> &sList)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 15 Part 2",'=');
 

    cout <<" -- Not yet implemented!" << endl;
    cout << endl;

    return 0;
}


