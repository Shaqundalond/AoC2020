/**
 * @file AoC-Tools.cpp
 * @author Reinhard Pfaff
 * @brief Collection of tools for Advent of Code Puzzles
 * @version 0.1
 * @date 2020-12-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "AoC.h"
using namespace std;

#include "AoC-Tools.h"




/**
 * @brief Generate a std::string with three lines, containing a "framed" head-string
 * 
 * looks like:
 * 
 * ========
 * = head =
 * ========
 * 
 * @param head          string to be framed
 * @param char_frame    charachter used for framing (i.e. '*','-','=',...)
 * @return string       three line string
 */
string MakeHeadline(const string head, const char char_frame)
{
    stringstream ts;
    int ls = head.length() + 4;
    ts << endl;
    ts << string(ls,char_frame) << endl;
    ts << char_frame << " " << head << " " << char_frame << endl;
    ts << string(ls,char_frame) << endl;
    ts << endl;
    return ts.str();
}

/**
 * @brief Read Strings from file and store them in a vector<string>
 * 
 * the stings are appended to the given vector<string>
 * 
 * @param fn    - filename
 * @param v_s   - vector<string> to store 
 * @return int  - errorcode oder numer of strings
 *              -1 ERROR: file open error
 *              >= 0 Number of read lines
 */
int ReadStrings(const string fn, vector<string>& v_s)
{
    int count = 0;
    ifstream fil(fn);

    // open the input file
    if (!fil.is_open())
    {
        cout << "Could not open file: [" << fn << "]" << endl;
        return -1;
    }

    // read all lines
    string line;
    while (getline(fil, line))
    {
        v_s.push_back(line);
        count++;
    }
    return count;
}

