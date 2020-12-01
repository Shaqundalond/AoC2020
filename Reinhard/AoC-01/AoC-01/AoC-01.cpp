// AoC-01.cpp : Defines the entry point for the application.
//

#include "AoC-01.h"


/*
* AoC 2020
* Puzzle 1
*
* Reinhard Pfaff
*/

using namespace std;


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

int Puzzle_1_1(vector<int>& v_i)
{
    cout << "Puzzle 1/1: Searching for two matching values" << endl;

    // find values
    for (int i = 0; i < (v_i.size() - 1); i++)
    {
        int i1 = v_i[i];
        int i2 = 2020 - i1;
        for (int j = i + 1; j < v_i.size(); j++)
        {
            if (v_i[j] == i2)
            {
                cout << "Two Values found:" <<  endl;
                cout << "i1: " << i << " val=" << i1 <<  endl;
                cout << "i2: " << j << " val=" << i2 <<  endl;
                cout << "i1 * i2 = " << i1 * i2 <<  endl;
                return 0;
            }
        }
    }
    
    cout << " **** ERROR : no matchinge pairs found!" <<  endl;

    return 0;
}

int Puzzle_1_2(vector<int>& v_i)
{
    cout << "Puzzle 1/2: Searching for three matching values" << endl;
    // find values
    for (int i = 0; i < (v_i.size() - 2); i++)
    {
        for (int j = i + 1; j < v_i.size()-1; j++)
        {
            for(int k = j+1; k < v_i.size() ; k++)
            if (v_i[i] + v_i[j] + v_i[k] == 2020)
            {
                cout << "Three Values found:" << endl;
                cout << "i1: " << i << " val=" << v_i[i] << endl;
                cout << "i2: " << j << " val=" << v_i[j] << endl;
                cout << "i3: " << k << " val=" << v_i[k] << endl;
                long int res = v_i[i] * v_i[j] * v_i[k];
                cout << "i1 * i2 * i3 = " << res << endl;
                return 0;
            }
        }
    }
        
    cout << " **** ERROR : no matchinge tripples found!" << endl;

    return 0;
}

int main()
{
    vector<int> v_i;
    int rv = ReadInts(v_i);

    if (rv > 0)
    {
        Puzzle_1_1(v_i);
        Puzzle_1_2(v_i);
    }
    return 0;
}