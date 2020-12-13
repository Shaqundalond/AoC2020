#include <iostream>		//cout cin
#include <fstream>		// reading files
#include <sstream>		// Stringstream
#include <vector>		// Vector container
#include <string>		// String class
#include <algorithm>		// find for vector
#include <iterator>		// Iterators for fvectors
#include <numeric>		// acccumulate
#include <limits.h>		// Long?int maximum and minimum values
#include <stdlib.h>		//abs

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




int main()
{

	vector<string> vs_input;		// store the inputfield
	string input = "input.bak";

	int i_departure =0;
	vector<int> vi_trainline;
	vector<int> vi_delay;


	cout << MakeHeadline("Advent of Code 2020 Puzzle # 13 PART 2",'=') << endl;

	if (!read_input(vs_input, input))
	{
	    return 1;
	}

	cout << "reading file [ " << input << " ] finished\n";

	cout << "Extracting earliest departure" << endl;
	i_departure = stoi(vs_input[0]);

	cout << "Extracting available lines" << endl;
	istringstream iss(vs_input[1]);
	string s_tmp;
	int it = -1;
	while(getline(iss, s_tmp, ','))
	{
		it++;
		// Skip lines that are not available
		if( s_tmp == "x" ) continue;
		vi_trainline.push_back(stoi(s_tmp));
		cout << s_tmp << ":" << it <<endl;
		vi_delay.push_back(it);
	}

	int i_waitingtime = INT_MAX;
	int i_bus = 0;
	//check each waiting time

	for (int i : vi_trainline)
	{
		// How many minutes ago did the train leave
		int i_tmp = i_departure % i;

		//When will the next train leave? and is it smaller than the current time
		if ( (i - i_tmp) < i_waitingtime )
		{
			i_waitingtime = i- i_tmp;
			i_bus = i;
		}

	}


	cout << "The minimum waiting time is: " << i_waitingtime << " timeintervalls" << endl;
	cout << "The bus is: " << i_bus  << endl;
	cout << "Answer: " << i_bus * i_waitingtime  << endl;



	cout << MakeHeadline("Advent of Code 2020 Puzzle # 13 PART 2",'=') << endl;

	long l_currPeriod= 1;
	long l_currTime = 0;


	for (int i = 0 ; i < vi_trainline.size() ; i++ )
	{
		int i_offset;
		//annoying first case handling
		if (i == 0 )
		{
			i_offset = vi_delay[i];
		}
		else
		{
			i_offset = vi_delay[i] - vi_delay[i -1];
		}

		while( true )
		{
			if( (l_currTime + i_offset) % vi_trainline[i] == 0 )
			{
				//found
				l_currTime += i_offset;
				l_currPeriod *= vi_trainline[i];
				break;
			}
			l_currTime += l_currPeriod;
		}
	}

	cout << l_currTime - vi_delay.back()<< endl;




}

