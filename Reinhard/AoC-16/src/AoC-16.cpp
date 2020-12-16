﻿/**
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
int main(int argc, char** argv)
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 16",'*');

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
    int m_Index;
    string m_key;
    int m_from1;
    int m_to1;
    int m_from2;
    int m_to2;
} rule_t;

int GetTicket(string ts, ticket_t &t)
{
    // cout << "GetTicket : " << ts << endl;
    int iCount = 0;
    vector<string> xts = explode(ts,",");
    if (xts.size() > 2) {
        for(auto tts : xts)
        {
            if (iCount == 0)
                t.clear();
            t.push_back(stoi(tts));
            iCount++;
        }
    }
    return iCount;
}

bool IsValidNumber(int number, vector<rule_t> &rules)
{
    for(auto r:rules)
    {
        if ((number >= r.m_from1) && (number <= r.m_to1) ||
            (number >= r.m_from2) && (number <= r.m_to2))
        {
            return true;
        }
    }

    return false;
}


bool CheckTicketsForRule(int i, int j, const vector<ticket_t> &t, vector<rule_t> &rules)
{
    // check in al tickets element tt[j] for matching rule[i]

    rule_t r = rules[i];

    for (auto tt : t)
    {
        int number = tt[j];

        if ((number >= r.m_from1) && (number <= r.m_to1) ||
            (number >= r.m_from2) && (number <= r.m_to2))
        {
            // OK, looks like valid
        }
        else
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief           AoC Puzzle
 * 
 * Part 1: Checking valid tickets
 * 
 * @param vector<string>   list of strings (only one string)
 * @return int             0
 */
int Puzzle_16(vector<string> &sList)
{
    //vector<string> XS = explode(sList[0],",");

    int iSum = 0;

    // Data from Input.txt
    vector<rule_t> rules;
    vector<ticket_t> tickets;
    ticket_t myTicket;

    // Analysing input file
    int section = 1;        // starting w/ rules
    for (auto ts:sList)
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
                    rules.push_back(r);
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

    // Debugging
    // for (auto r : rules)
    //    cout << " -- Rule: " << r.m_key << " " << r.m_from1 << " - " << r.m_to1 << " OR " << r.m_from2 << " - "<< r.m_to2 << endl;

    // Now count the invalid tickets
    vector<ticket_t> ctickets;

    for ( auto t : tickets)
    {
        bool bValid = true;
        for ( auto in : t)
        {
            if (!IsValidNumber(in,rules))
            {
                cout << "-- Invalid: " << in << endl;
                iSum += in;
                bValid = false;
            }
        }
        if (bValid)
            ctickets.push_back(t);
    }
    // Finally write the results
    cout << endl;
    cout << " *** sum of invalid ticketnumbers: " << iSum << endl;
    cout << endl;

    cout << " *** Valid Tickets: " << ctickets.size() << endl << endl;

    bool bCandid[20][20];

    // check the first 
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            bool bOK = CheckTicketsForRule(i,j,ctickets,rules);
            bCandid[i][j] = bOK;

            if (bOK)
                cout << " X ";
            else
                cout << " . ";
             
        }
        cout << endl;
    }

    // check all rules
    for (int l = 0; l< 20; l++) {
        for (int i= 0; i< 20 ; i++)
        {
            // find column with one element
            int n = 0;
            int tj=-1;
            for (int j=0; j < 20; j++)
            {
                if (bCandid[i][j])
                {
                    n++;
                    tj = j;
                }
            }
            if (n==1)
            {
                // found => Rule i is Column j
                rules[i].m_Index = tj;
                // remove all in row j
                for (int k=0;k<20;k++)
                    bCandid[k][tj] = false;
            }        
        }
    }

    // kontrollausgabe
    for (int ir = 0; ir< 20; ir++)
    {
        cout << rules[ir].m_Index << "   - " << myTicket[ir] << endl;
    }

    cout << endl;

    // finally find the values in myTicket
    long Prod = 1;

    for (int iv = 0; iv < 6; iv++)
    {
            Prod *= myTicket[rules[iv].m_Index];
            cout << Prod << endl;
    }


    return 0;
}
