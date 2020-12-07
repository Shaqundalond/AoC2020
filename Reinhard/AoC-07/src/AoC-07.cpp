/**
 * @file AoC-07.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #07
 * @version 0.1
 * @date 2020-12-07
 * 
 * @copyright Copyright (c) 2020 Reinhard Pfaff
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"

#include "Bag.h" 

// Function declarations
// =====================
int MakeVectorOfBags(const vector<string> &vs, vector<Bags> &vbags);
int Puzzle_7(const vector<string> &vs);


/**
 * @brief main (what else?)
 * 
 * @return int 
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 07",'=') << endl;

    // Reading input strings
    vector<string> vs;
    if (ReadMultilineStrings("input.txt", vs, "") < 0)
    {
        cout << "--- ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // Frist step: make a vector of bags, representing the whole input
    vector<Bag> vbags;
    int nBags = MakeVectorOfBags(vs, vbags);


    // first puzzle of day 
    cout << MakeHeadline(" ** Puzzle 1: Counting valid Yes-answers",'~') << endl;
    int iYes = Puzzle_6(vs);

    cout << " == Nnumber of Yes: " << iYes << endl;

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
 * vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.
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

        if (tss.size() == 7 || tss.size() == 8 || tss.size() == 12)
        {
            if (tss.size() >= 7)
            {
                // no, 1, 2 sub-bags
                string iam = tss[0] + " " + tss[1];
                oneBag.m_ID = iam;
            }

            if (tss.size() >= 8)
            {
                // 1 sub-bag
                int nSub = atoi(tss[4]);
                string SubID = tss[5] + " " + tss[6];
                oneBag.m_nBags.push_back(nSub);
                oneBag.m_BagsID.push_back(SubID);
            }

            if (tss.size() == 12)
            {
                // 1 sub-bag
                int nSub = atoi(tss[4]);
                string SubID = tss[5] + " " + tss[6];
                oneBag.m_nBags.push_back(nSub);
                oneBag.m_BagsID.push_back(SubID);
            }

            vbags.push_back(oneBag);
        }
        else
        {
            cout << " ** (L:" << iLine << "ERROR in input.txt. Unexpected format " << endl;
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




