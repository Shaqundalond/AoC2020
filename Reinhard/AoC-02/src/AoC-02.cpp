/**********************************************************
* AoC 2020
* Puzzle 2
*
* Reinhard Pfaff
*
***/

#include "AoC-02.h"

using namespace std;

const int iPuzzle = 2;      // Puzzle no.

string MakeHeadline(const string head, const char char_frame)
{
    // Makeing:
    //
    // ========
    // = head =
    // ========
    //

    stringstream ts;
    int ls = head.length() + 4;
    ts << endl;
    ts << string(char_frame,ls) << endl;
    ts << char_frame << " " << head << " " << char_frame << endl;
    ts << endl;
    return ts.str();
}

int ReadInts(vector<int>& v_i)
{
    int count = 0;
    string fn = "input.txt";
    ifstream fil(fn);

    // open the input file
    if (!fil.is_open())
    {
        cout << "Could not open file: [" << fn << "]" << endl;
        return 1;
    }

    // real all lines
    int one = 0;
    string line;
    while (getline(fil, line))
    {
        one = stoi(line);
        v_i.push_back(one);
        count++;
    }
    return count;
}

int Puzzle_2_1(const string fn)
{
    cout << MakeHeadline("** Puzzle 1: Looking for valid passwords",'-') << endl;

    // open the input file
    ifstream fil(fn);
    if (!fil.is_open())
    {
        cout << "Could not open file: [" << fn << "]" << endl;
        return 1;
    }

    // read all lines
    int iCountValid = 0;
    int iLine = 0;
    string line;
    while (getline(fil, line))
    {
        iLine++;            // counting lines

        // One Line consists of #1-#2 c: <string>
        stringstream ts(line);
        int iMin = 0;           // min number of occurance
        int iMax = 0;           // max number of occurance
        char ch_char = ' ';     // character to count
        char ch_sep = ' ';      // separator
        string pw;              // password to check (maybe containing whitespaces)
        ts >> iMin >> ch_sep >> iMax >> ch_char >> ch_sep >> pw;
        if (ts)
        {
            // valid inputline
            int iCountChar = 0;
            for (char tc : pw)
            {
                if (tc == ch_char)
                    iCountChar++;
            }
            if (iCountChar >= iMin && iCountChar <= iMax)
                iCountValid++;
        }
        else
        {
            // invalid inputline
            cout << " **** invalid inputline @" << iLine << " ["<<line<<"]" << endl;
        }
        
    }

    return iCountValid;
}


int main()
{
    cout << MakeHeadline("Advent of Code 2020 Puzzle # 02",'=') << endl;

    Puzzle_2_1("input.txt");
    // Puzzle_2_2(v_i);

    return 0;
}