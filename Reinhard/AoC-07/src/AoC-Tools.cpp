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

/**
 * @brief Read Strings from file and store them in a vector<string>
 * 
 * the stings are appended to the given vector<string>
 * 
 * Remark:
 * - Strings for Puzzle 04 are spread over more than one line
 * - Empty lines are string delimiters: 
 *   For example:
 *       <BOF>
 *       ecl:gry pid:860033327 eyr:2020 hcl:#fffffd
 *       byr:1937 iyr:2017 cid:147 hgt:183cm
 *       
 *       iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884
 *       hcl:#cfa07d byr:1929
 *       
 *       hcl:#ae17e1 iyr:2013
 *       eyr:2024
 *       ecl:brn pid:760753108 byr:1931
 *       hgt:179cm
 *       <EOF>
 *   results in a vector w/ three strings
 * 
 * @param fn    - filename
 * @param v_s   - vector<string> to store 
 * @return int  - errorcode oder numer of strings
 *              -1 ERROR: file open error
 *              >= 0 Number of read lines in file (incl. empty lines)
 */
int ReadStrings4P04(const string fn, vector<string>& v_s)
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
    string cline;   // compount line
    while (getline(fil, line))  // line delimiters are NOT stored
    {
        if (line.length() > 0)
        {
            // append the current read line to the cline (don't forget a separator)
            cline += line;
            cline += " ";
        }
        else
        {
            // this is a new line, so push back the collected strings
            v_s.push_back(cline);
            // and prepare the cline
            cline.clear();
        }
        count++;
    }
    // maybe there was no empty line at the end of the file
    if (cline.length() > 0)
    {
        v_s.push_back(cline);
    }
    return count;
}

/**
 * @brief Read Strings from file and store them in a vector<string>
 * 
 * the stings are appended to the given vector<string>
 * 
 * Remark:
 * - Strings are spread over more than one line
 * - Empty lines are string delimiters: 
 *   For example:
 *       <BOF>
 *       ecl:gry pid:860033327 eyr:2020 hcl:#fffffd
 *       byr:1937 iyr:2017 cid:147 hgt:183cm
 *       
 *       iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884
 *       hcl:#cfa07d byr:1929
 *       
 *       hcl:#ae17e1 iyr:2013
 *       eyr:2024
 *       ecl:brn pid:760753108 byr:1931
 *       hgt:179cm
 *       <EOF>
 *   results in a vector w/ three strings. The new string is optionaly separated by sep
 * 
 * @param fn    - filename
 * @param v_s   - vector<string> to store 
 * @param sep   - separator
 * @return int  - errorcode oder numer of strings
 *              -1 ERROR: file open error
 *              >= 0 Number of read lines in file (incl. empty lines)
 */
int ReadMultilineStrings(const string fn, vector<string>& v_s, const string sep)
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
    string cline;   // compount line
    while (getline(fil, line))  // line delimiters are NOT stored
    {
        if (line.length() > 0)
        {
            // append the current read line to the cline (don't forget the optinal separator)
            cline += line;
            if (sep.length() > 0)
                cline += sep;
        }
        else
        {
            // this is a new line, so push back the collected strings
            v_s.push_back(cline);
            // and prepare the cline
            cline.clear();
        }
        count++;
    }
    // maybe there was no empty line at the end of the file
    if (cline.length() > 0)
    {
        v_s.push_back(cline);
    }
    return count;
}

