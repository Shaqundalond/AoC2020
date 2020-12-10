#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <limits.h>

using namespace std;




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


bool read_input( vector<string> &vect, const string &input )
{
    string line;

    // open the input file
    ifstream fil(input);
    if (!fil.is_open())
    {
        cout << "Could not open file: [" << input << "]" << endl;
        return false;
    }

    // read all lines
    while (getline(fil, line))
    {
	vect.push_back(line);
    }

    fil.close();
    return true;
}

bool is_valid_XMAS_num( const vector<long> &vl_num, int i_lower, int i_upper, long l_num)
{
	// The Range for this is inclusive Ranges
	for( int i = i_lower; i <= i_upper; i++)
	{
		for(int j = i + 1; j <= i_upper; j++)
		{
			if( vl_num[i] + vl_num[j] == l_num)
			{
				return true;
			}
		}

	}

	return false;
}

int main()
{

    vector<string> vs_input;		// store the inputfield
    string input = "input";

    int i_range = 25;			// Range of XMAS protocol to calculate a number
    int i_lower = 0;
    int i_upper = 0;
    long l_lookup = 0;
    int i_lookupIndex = 0;
    vector<long> vl_input;

    cout << MakeHeadline("Advent of Code 2020 Puzzle # 09",'=') << endl;

    if (!read_input(vs_input, input))
    {
	    return 1;
    }

    cout << "reading file [ " << input << " ] finished\n";

    cout << "Casting the strings to long\n";
    for ( int i = 0 ; i< vs_input.size(); i++ )
    {
	    vl_input.push_back(stol(vs_input[i]));
    }

    cout << "Parsing the XMAS Protocol\n";

    for ( int i = 25; i < vl_input.size(); i++)
    {
	    i_lower = i - i_range;
	    i_upper = i - 1;
	    l_lookup = vl_input[i];

	    if(!is_valid_XMAS_num(vl_input, i_lower, i_upper, l_lookup))
	    {
		    cout << "Invalid Number [" << l_lookup << "] found in line [" << i + 1 << "]\n";
		    i_lookupIndex = i;
		    break;
	    }


    }

    cout << "Looking for the Encryption Weakness\n";
    cout << "Using a Kernel of increasing Size to Check\n";



    //creating the kernel
    for (i_range = 2 ; i_range < i_lookupIndex; i_range++)
    {
	//moving the Kernel
	for ( int i = 0; i <= i_lookupIndex - i_range; i++)
	{
		if(accumulate(vl_input.begin() + i, vl_input.begin() +  i +i_range, 0) == l_lookup)
		{
			long l_max = LONG_MIN;
			long l_min = LONG_MAX;
			cout <<"Found the matching Range\nCaluclating sum of low and high\n";
			for(int j = i ; j < i + i_range; j ++)
			{
				if( vl_input[j] > l_max)
				{
					l_max = vl_input[j];
				}
				if (vl_input[j] < l_min)
				{
					l_min = vl_input[j];
				}
			}

			cout << "the Encryption Weakness is [ ";
			cout << l_max + l_min;
			cout << " ]\n";
		}
	}
    }




    return 1;

}

