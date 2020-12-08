﻿/**
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

// Function declarations
// =====================
int MakeVectorOfBags(const vector<string> &vs, vector<Bag> &vbags);
int Puzzle_(const vector<Bag> &vbags, int iPuzzle);

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

    // Frist step: make a vector of bags, representing the whole input
    vector<Bag> vbags;
    int nBags = MakeVectorOfBags(vs, vbags);

    // first puzzle of day 
    cout << MakeHeadline(" ** Puzzle 1: Counting number of possible bags",'~') << endl;
    int npossibleBags = Puzzle_8(vbags,1);
    cout << " == Number of possible bags: " << npossibleBags << endl;

    return 0;
}


/**
 * @brief MakeVectorOfBags
 * 
 * Converts the input strings into a data structure defined by Bag
 *
 * For example, consider the following rules:
 * 
 * light red bags contain 1 bright white bag, 2 muted yellow bags.
 * dark orange bags contain 3 bright white bags, 4 muted yellow bags.
 * bright white bags contain 1 shiny gold bag.
 * muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.
 * shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.
 * dark olive bags contain 3 faded blue bags, 4 dotted black bags.
 * vibrant plum bags contain 5 faded blue bags, 6 dotted black bags, ...
 * faded blue bags contain no other bags.
 * dotted black bags contain no other bags.
 * 
 * 
 * @param vs        - vector<string> each string describes a bag: ID und number + ID of Sub Bags
 * @param vbags     - vector<Bag> konverted strings
 * @return int 
 */
int MakeVectorOfBags(const vector<string> &vs, vector<Bag> &vbags)
{
    int nBags = 0;
    int iLine = 0;

    for (string ts : vs)
    {
        Bag oneBag;
        // convert
        vector<string> tss = explode(ts," ");

        int is = 0;     // Index into tss
        // first, ther must be at least 7 string to identify myself
        if (tss.size() >= 7)
        {
            // no, 1, 2 sub-bags
            string iam = tss[0] + " " + tss[1];
            oneBag.m_ID = iam;
            is += 4;
        }

        // rest of the line
        while ((is+4) <= tss.size())
        {
            // not yet done
            // 1 sub-bag
            int nSub = atoi(tss[is].c_str());
            string SubID = tss[is+1] + " " + tss[is+2];
            oneBag.m_nBags.push_back(nSub);
            oneBag.m_BagsID.push_back(SubID);
            is += 4;
        }

        vbags.push_back(oneBag);

        if (is < tss.size())
        {
            cout << " ** (L:" << iLine << ") ERROR in input.txt. Unexpected format! is=" << is << " size=" << tss.size() << endl;
            cout << "       " << ts << endl;
        }

        iLine += 1;
    }

    return vbags.size();
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
int Puzzle_8(const vector<Bag> &vbags, int iPuzzle)
{
    int iCount = 0;
    if (iPuzzle == 1)
    {
        iCount = FindPathTo("shiny gold", vbags);
    }
    else
    {
        iCount = CountBags("shiny gold", vbags);
    }
    
    return iCount;
}

