#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

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

void extract_substring(const string &parent, string &child, const string key)
{
    int l_begin;
    int l_end;
    int l_idsize = 4;

    child.clear();
    l_begin = parent.find(key);
    l_end = parent.find(" ", l_begin);

    // untersuche den substring von [l_begin + l_idsize , l_end )
    child = parent.substr(l_begin + l_idsize, l_end - l_begin - l_idsize);
}

int calculate_seat_id(const string &pass)
{
	int l_rowHigh = 127;	//highest Rownumber 2^n -1
	int l_rowLow = 0;	//lowest Rownumber 2^n
	int l_colHigh = 7;	//highest Rownumber
	int l_colLow = 0;	//lowest Rownumber
	int l_diff = 0;

	for (char c : pass )
	{
		switch(c)
		{
			case 'F':
				//Stay on the lower numbers
				// lower border does not change only upper border
				l_diff = l_rowHigh - l_rowLow;
				l_rowHigh = l_rowLow + l_diff/2;
				break;
			case 'B':
				//Stay on the hgher numbers
				//upper border does not change only lower
				l_diff = l_rowHigh - l_rowLow;
				l_rowLow = l_rowHigh - l_diff/2;
				break;
			case 'L':
				//Stay on the lower numbers
				// lower border does not change only upper border
				l_diff = l_colHigh - l_colLow;
				l_colHigh = l_colLow + l_diff/2;

				break;
			case 'R':
				//Stay on the hgher numbers
				//upper border does not change only lower
				l_diff = l_colHigh - l_colLow;
				l_colLow = l_colHigh - l_diff/2;
				break;
			default:
				cout << " Invalid Pass\n";
				return 0;
		}
	}

	return l_rowHigh * 8 + l_colHigh;

}


int main()
{

    vector<string> vs_input;		// store the inputfield
    string input = "input";

    //int l_maxSeatID = 0;
    int l_currentSeatID =0;
    int l_numrows = 128;
    int l_numcols = 8;

    bool seats[l_numrows * l_numcols];



    cout << MakeHeadline("Advent of Code 2020 Puzzle # 05",'=') << endl;

    if (!read_input(vs_input, input))
    {
	    return 1;
    }

    cout << "reading file [ " << input << " ] finished\n";

    cout << "clearing seat array \n";
    for (int b = 0; b < l_numrows * l_numcols; b++)
    {
	    seats[b] = false;
    }
    cout << "Seats initiaized \n";

    cout << "Filling Seats \n";
    for (int i = 0; i< vs_input.size() ; i++)
    {
	    l_currentSeatID = calculate_seat_id(vs_input[i]);
	    cout << " Seat: " << l_currentSeatID << " filled\n";
	    seats[l_currentSeatID] = true;
    }

    cout << "checking for free seats\n";

    // we know that we have no seat in the first and last row
    for ( int i = 1 * l_numcols ; i < l_numrows * l_numcols - l_numcols ; i++ )
    {
	    if ( seats[i-1] && !seats[i] && seats[i+1] )
	    {
		    cout << "Found free Seat at ID: " << i << '\n';
	    }
    }




    return 1;

}

