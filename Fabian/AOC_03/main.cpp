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

int find_trees( const vector<string> &vect, int i_deltax, int i_deltay, int i_modspace)
{
    int i_xpos = 0;			// initial x position
    int i_treecount = 0;		// count the trees hit by route
    for ( int i_ypos = 0; i_ypos < vect.size() ; i_ypos+=i_deltay )
    {
        if ( vect[i_ypos].at(i_xpos) == '#')
	{
	    i_treecount++;
	}
	i_xpos = (i_xpos + i_deltax) % i_modspace;
    }

    cout << "On the route " << i_deltax << '-' << i_deltay << '\n';
    cout << i_treecount << '\n';
    cout << "trees were hit\n";
    cout << "#############################";

    return i_treecount;

}


int main()
{
    /*
    const int i_deltax = 3;
    const int i_deltay = 1;
    */


    vector<string> vs_input;		// store the inputfield
    int i_multcount = 1;		// store the mult count for hit trees
    int i_modspace;			// modulospace defined by the size of one line

    cout << MakeHeadline("Advent of Code 2020 Puzzle # 03",'=') << endl;

    // open the input file
    ifstream fil("input");
    if (!fil.is_open())
    {
        cout << "Could not open file: [" << "input" << "]" << endl;
        return 1;
    }

    // read all lines
    string line;
    while (getline(fil, line))
    {
	vs_input.push_back(line);
    }

    fil.close();

    // walk through the forest

    i_modspace = vs_input[0].size();

    i_multcount*=find_trees(vs_input, 1, 1, i_modspace);
    i_multcount*=find_trees(vs_input, 3, 1, i_modspace);
    i_multcount*=find_trees(vs_input, 5, 1, i_modspace);
    i_multcount*=find_trees(vs_input, 7, 1, i_modspace);
    i_multcount*=find_trees(vs_input, 1, 2, i_modspace);




    cout << "The Solution is:\n";
    cout << i_multcount << '\n';
    return 1;

}

