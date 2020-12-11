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

int i_rows;
int i_cols;


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


int scan_line( vector<int> &vect, int index, int i_stepX, int i_stepY)
{
	int i_neighbour = 0;
	bool b_Wall = false;

	bool b_left = false;			// is the center on the left side
	bool b_right = false;		// is the center on the right side
	bool b_top = false;			// is the center on the top row
	bool b_bottom = false;		// is the center on the bottom row

	while(true)
	{

		b_left = ( index % i_cols == 0 );
		b_right = ( index % i_cols == i_cols -1 );
		b_top = ( index / i_cols == 0 );
		b_bottom = ( index / i_cols == i_rows - 1 );

		// check for the possible collision points
		if ( i_stepY < 0 ) b_Wall ^= b_top;
		if ( i_stepY > 0 ) b_Wall ^= b_bottom;
		if ( i_stepX < 0 ) b_Wall ^= b_left;
		if ( i_stepX > 0 ) b_Wall ^= b_right;

		if(b_Wall) break;		// no seats found in line

		index += i_stepX;
		index += i_stepY;

		if(0 == vect[index]) return 0;
		if(1 == vect[index]) return 1;
	}

	return 0;


}

int main()
{

    vector<string> vs_input;		// store the inputfield
    string input = "input";
    int i_neighbours;			// store the neighbours for each Kernel pass
    bool b_ident;			// did the seating change between turns
    int i_count = 0;

    vector<int> vi_input;	// Store the playingfield in a 1D array


    cout << MakeHeadline("Advent of Code 2020 Puzzle # 11 PART 2",'=') << endl;

    if (!read_input(vs_input, input))
    {
	    return 1;
    }

    cout << "reading file [ " << input << " ] finished\n";

    cout << "Definfing the Dimensions" << endl;
    i_cols = vs_input[0].length();
    i_rows = vs_input.size();
    cout << "Rows: " << i_rows << endl;
    cout << "Cols: " << i_cols << endl;

    cout <<"Transforming input" <<endl;
    for ( string row : vs_input )
    {
	for (char c : row)
	{
		if ( 'L' == c) vi_input.push_back(0);
		else if ( '.' == c) vi_input.push_back(-1);
		else if ( '#' == c) vi_input.push_back(1);
		else
		{
			cout << "Something went wrong" << endl;
			return -1;
		}
	}
    }

    cout << "Playing game of Life" << endl;

    vector<int> vi_new = vi_input;
    b_ident = false;

    i_count = 0;
    while(!b_ident)
    {
	    i_count++;
	    b_ident = true;
	    for( int i = 0; i < vi_input.size(); i++)
	    {


		    i_neighbours = 0;
		// if floor skip
		    if (vi_input[i] == -1) continue;
		// nutze den Kernel mit allen grenzfaellen und addiere Count
		// start in the top left corner and go clockwise

		    i_neighbours += scan_line(vi_input, i, -1, -i_cols); 	//lefttop
		    i_neighbours += scan_line(vi_input, i,  0, -i_cols); 	//top
		    i_neighbours += scan_line(vi_input, i,  1, -i_cols);	//righttop
		    i_neighbours += scan_line(vi_input, i,  1,  0     ); 	//right
		    i_neighbours += scan_line(vi_input, i,  1,  i_cols); 	//rightdown
		    i_neighbours += scan_line(vi_input, i,  0,  i_cols); 	//down
		    i_neighbours += scan_line(vi_input, i, -1,  i_cols); 	//leftdown
		    i_neighbours += scan_line(vi_input, i, -1,  0     ); 	//left

		// If Seat is empty and no occupied(1) seats around it fills
		    if( 0 == vi_input[i] && i_neighbours == 0)
		    {
			    vi_new[i] = 1;
			    b_ident &= false;
		    }
		// If Seat is filled and four or more (>=4) seats around are occupied vacant it
		    if( 1 == vi_input[i] && i_neighbours >= 5 )
		    {
			    vi_new[i] = 0;
			    b_ident &= false;
		    }
	    }

	    //Swap Vectors
	    vi_input = vi_new;
    }

    cout << i_count << endl;
    i_count = 0;

    for (int i : vi_input)
    {
	if (i == 1) i_count++;
    }

    cout << "Number of occupied seats" <<endl;
    cout << i_count << endl;

    return 1;

}

