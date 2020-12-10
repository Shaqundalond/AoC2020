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

long recursive_stepsearch(vector<int> &vect, long al_stepcount[], int i_step)
{
	long l_count = 0;
	//Abort this ship
	if( i_step == 0 ) return 1;
	if( i_step < 0 ) return 0;

	//is this a valid step
	//TODO speed this up by passing vector and find it on your own without find
	if(find(vect.begin(), vect.end(), i_step) == vect.end()) return 0;

	//has this step already been caluclated
	if( al_stepcount[i_step] != 0 ) return al_stepcount[i_step];

	//recursive stearch
	l_count += recursive_stepsearch(vect, al_stepcount, i_step - 1);
	l_count += recursive_stepsearch(vect, al_stepcount, i_step - 2);
	l_count += recursive_stepsearch(vect, al_stepcount, i_step - 3);

	al_stepcount[i_step] = l_count;
	return l_count;
}



int main()
{

    vector<string> vs_input;		// store the inputfield
    string input = "input";

    vector<int> vi_input;
    int ai_counts[3] = { 0,0,0 };
    int i_diff = 0;
    long l_combinations;

    cout << MakeHeadline("Advent of Code 2020 Puzzle # 10 PART 1",'=') << endl;

    if (!read_input(vs_input, input))
    {
	    return 1;
    }

    cout << "reading file [ " << input << " ] finished\n";

    cout << "Casting the strings to long\n";
    for ( int i = 0 ; i< vs_input.size(); i++ )
    {
	    vi_input.push_back(stol(vs_input[i]));
    }

    cout << "Adding 0 jolts outlet\n";

    vi_input.push_back(0);

    cout << "Sorting the array\n";

    sort(vi_input.begin(), vi_input.end());

    cout << "Adding device joltage\n";

    vi_input.push_back(vi_input.back() + 3);

    for (int i = 0 ; i < vi_input.size() - 1 ; i++)
    {
	    i_diff = vi_input[i +1] - vi_input[i] - 1;
	    /* cout << "The Adapters were: "<< vi_input[i] << " & " << vi_input[i +1] << '\n'; */
	    /* cout << "The difference was: " << i_diff + 1 << '\n'; */

	    ai_counts[i_diff]++;
    }

    cout << "Multiplying #1jolts and #3jolts deltas\n";
    cout << ai_counts[0] * ai_counts[2];


    cout << MakeHeadline("Advent of Code 2020 Puzzle # 10 PART 2",'=') << endl;

    long al_stepcount[vi_input.back() + 1 ];

    l_combinations = recursive_stepsearch(vi_input, al_stepcount, vi_input.back());

    cout << l_combinations << endl;

    return 1;

}

