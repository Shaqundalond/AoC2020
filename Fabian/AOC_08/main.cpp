#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>

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

enum StringOpcode
{
	acc,
	jmp,
	nop
};

static map<std::string, StringOpcode> s_mapStringOpcode;

bool run_programm(vector<string> &vs_input)
{

    vector<bool> vb_visited(vs_input.size(), false);
    bool b_running = true;

    int l_acc = 0;			// local accumulator
    string s_opcode = "";		// Operaction coude
    int l_argument =0;			// argument of operation code

    int i = 0;
    int l_posSpace;
    while(b_running && i < vs_input.size())
    {
	    // resetting
	    s_opcode.clear();
	    l_argument = 0;

	    // extracting the line
	    l_posSpace = vs_input[i].find(' ');
	    s_opcode = vs_input[i].substr(0, l_posSpace);
	    l_argument = stoi(vs_input[i].substr(l_posSpace, string::npos));

	    //Check if line is already visited else flag as visited
	    if (vb_visited[i])
	    {
		    cout << "Line " << i << " was already visited\n";
		    cout << "Dumping Accumulator\n";
		    cout << l_acc << '\n';
		    break;
	    }
	    else
	    {
		    vb_visited[i] = true;
	    }


	    switch(s_mapStringOpcode[s_opcode])
	    {
		    case acc:
			    l_acc += l_argument;
			    i++;
			    break;
		    case jmp:
			    i += l_argument;
			    break;
		    case nop:
			    i++;
			    break;
		    default:
			    cout << "Invalid opcode [" << s_opcode << "] at line " << i << '\n';
			    break;
	    }

	    if( i == vs_input.size() )
	    {
		cout << "Reached Last Line Dumping Accumulator\n";
		cout << l_acc << '\n';
		return true;
	    }

	    // check index for out of bounds
	    /* if ( i < 0 || i > vs_input.size() ) */
	    /* { */
		    /* cout << "Invalid acces of Memory! Aborting"; */
	    /* } */
    }

    return false;

}

int main()
{

    vector<string> vs_input;		// store the inputfield
    string input = "input";


    // initialize enum because C++ is shitty
    s_mapStringOpcode["acc"] = acc;
    s_mapStringOpcode["jmp"] = jmp;
    s_mapStringOpcode["nop"] = nop;

    cout << MakeHeadline("Advent of Code 2020 Puzzle # 08",'=') << endl;

    if (!read_input(vs_input, input))
    {
	    return 1;
    }

    cout << "reading file [ " << input << " ] finished\n";

    // go through the code
    string s_nop = "nop";
    string s_jmp = "jmp";

    for ( int i = 0 ; i< vs_input.size(); i++ )
    {


	if( vs_input[i].find(s_nop) != string::npos )
	{
    		cout << "##############################\n";
		cout << "replacing [ nop ] with [ jmp ] in line " << i+1 << '\n';
		// nop found replace with jmp
		vs_input[i].replace(0,3,s_jmp);
		//do caluclation
		if ( run_programm(vs_input)) break;
		//change it back
		vs_input[i].replace(0,3,s_nop);
	}
	else if( vs_input[i].find(s_jmp) != string::npos )
	{
    		cout << "##############################\n";
		cout << "replacing [ jmp ] with [ nop ] in line " << i+1 << '\n';

		// nop found replace with jmp
		vs_input[i].replace(0,3,s_nop);
		//do caluclation
		if ( run_programm(vs_input)) break;
		//change it back
		vs_input[i].replace(0,3,s_jmp);
	}
    }




    return 1;

}

