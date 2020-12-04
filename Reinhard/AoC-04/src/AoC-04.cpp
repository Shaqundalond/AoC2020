/**
 * @file AoC-04.cpp
 * @author Reinhard Pfaff
 * @brief AoC Puzzle 2020 #04
 * @version 0.1
 * @date 2020-12-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"

/**
 * @brief main (what else?)
 * 
 * @return int 
 */
int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 04",'=') << endl;

    // Reading input strings
    vector<string> vs;
    if (ReadStrings4P04("input.txt", vs) < 0)
    {
        cout << "--- ERROR Reading strings. Aborting!" << endl;
        return 1;
    }   

    // first puzzle of day 04
    cout << MakeHeadline(" ** Puzzle 1: Counting valid entries",'~') << endl;
    int iValidEntries = Puzzle_4_1(vs);

    cout << endl;
    cout << " == Nnumber of valid Entries: " << iValidEntries << endl << endl;

    return 0;
}


/**
 * @brief           AoC Puzzle
 * 
 * Count the strings which contains all entries
 * The automatic passport scanners are slow because they're having trouble detecting which passports have all required fields. 
 * The expected fields are as follows:
 *  
 *         byr (Birth Year)
 *         iyr (Issue Year)
 *         eyr (Expiration Year)
 *         hgt (Height)
 *         hcl (Hair Color)
 *         ecl (Eye Color)
 *         pid (Passport ID)
 *         cid (Country ID)        - this entry is optional
 * 
 * 
 * @param vs        vector<string> with treemap
 * @return int      n - number of valid entries
 */
int Puzzle_4_1(const vector<string> &vs)
{
    int iCountValid = 0;
    for (string ts : vs)
    {
        bool bValid = true;
        bValid &= CheckForKeyOccurance(ts,"byr");
        bValid &= CheckForKeyOccurance(ts,"iyr");
        bValid &= CheckForKeyOccurance(ts,"eyr");
        bValid &= CheckForKeyOccurance(ts,"hgt");
        bValid &= CheckForKeyOccurance(ts,"hcl");
        bValid &= CheckForKeyOccurance(ts,"ecl");
        bValid &= CheckForKeyOccurance(ts,"pid");
        if (bValid)
            iCountValid += 1;
#ifdef DEBUG
        if (bValid)
        {
            cout << "  +++ " << ts << endl;
        }
        else
        {
            cout << "  --- " << ts << end;
        }
#endif
    }
    return iCountValid;
}


/**
 * @brief   searches a string for occurance of another string (a "key")
 * 
 * @param string2check  - string to look at
 * @param key           - string to look for
 * @return true         - string2check contains key
 * @return false        - ssring2check doen't contain key
 */
bool CheckForKeyOccurance(const string& string2check, const string& key)
{
    string::size_type found = string2check.find(key))
    return (found != string::npos);    
}


