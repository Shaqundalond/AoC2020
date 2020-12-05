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

// Fcuntion declarations
int Puzzle_4_1(const vector<string> &vs);
bool CheckForKeyOccurance(const string& string2check, const string& key);


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
    int iN = 0;
    int iCountValid = 0;
    for (string ts : vs)
    {
        cout << iN++ << " (" << ts << ")" <<endl;

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

        if (bValid)
        {
            cout << "  +++ " << ts << endl;
        }
        else
        {
            cout << "  --- " << ts << endl;
        }

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
    string::size_type found = string2check.find(key);
    bool bFound = (found != string::npos);

    cout << "      " << key << " " ;
    
    if (bFound)
    {
        try {

            string sVal = string2check.substr(found+4);

            cout << sVal << " ";

            if (key == "byr")
            {
                int yr = atoi(sVal.c_str());
                if (yr < 1920 || yr > 2002)
                    bFound = false;
            }
            else if (key == "iyr")
            {
                int yr = atoi(sVal.c_str());
                if (yr < 2010 || yr > 2020)
                    bFound = false;            
            }
            else if (key == "eyr")
            {
                int yr = atoi(sVal.c_str());
                if (yr < 2020 || yr > 2030)
                    bFound = false;                       
            }
            else if (key == "hgt")
            {
                int h = atoi(sVal.c_str());
                if (2 == sVal.find("in"))
                {
                    if ( h < 59 || h > 76)
                        bFound = false;
                }
                else if ( 3 == sVal.find("cm"))
                {
                if ( h < 150 || h > 193)
                        bFound = false;
                }
                else
                {
                    bFound = false;
                }           
            }
            else if (key == "hcl")
            {
                string validchars = "0123456789abcdef";
                if (sVal.at(0) != '#')
                {
                    bFound = false;
                }
                else
                {
                    for (int i=0; i<6; i++)
                    {
                        if (string::npos == validchars.find(sVal.at(i+1)))
                            bFound = false;
                    }
                    if (sVal.length() > 7)
                    {
                        // no more than 6 digits allowed!
                        if (string::npos != validchars.find(sVal.at(7)))
                            bFound = false;
                    }
                }
            }
            else if (key == "ecl")
            {
                bool bOK = false;
                if (sVal.find("amb") == 0 ||
                    sVal.find("blu") == 0 ||
                    sVal.find("brn") == 0 ||
                    sVal.find("gry") == 0 ||
                    sVal.find("grn") == 0 ||
                    sVal.find("hzl") == 0 ||
                    sVal.find("oth") == 0)
                    bOK = true;
                bFound = bOK;            
            }
            else if (key == "pid")
            {
                string validchars = "0123456789";
                for (int i=0; i<9; i++)
                {
                    if (string::npos == validchars.find(sVal.at(i)))
                        bFound = false;
                }
                if (sVal.length() > 9)
                {
                    // no more than 9 digits allowed!
                    if (string::npos != validchars.find(sVal.at(9)))
                        bFound = false;
                }

            }
            else if (key == "cid")
            {
                // nobody cares
            }

        }
        catch(out_of_range)
        {
            cout << " EXCEPTION: Out-of-range!" << endl;
            bFound = false;
        }

    }

    cout << bFound << endl;
    
    return bFound;    
}


