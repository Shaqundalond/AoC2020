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




int main()
{

    vector<string> vs_input;		// store the inputfield
    string input = "input";

    int al_answers[26];
    int l_current = 0;			// current answers
    int l_cum =0;			// cumulative answers
    int l_base = (int) 'a';		// use ASCII of a as a baseline
    int l_size;				// size of group

    int l_tmp;


    cout << MakeHeadline("Advent of Code 2020 Puzzle # 06",'=') << endl;

    if (!read_input(vs_input, input))
    {
	    return 1;
    }

    cout << "reading file [ " << input << " ] finished\n";


    cout << "Processing Groups \n";

    for (int i = 0; i< vs_input.size() ; i++)	// loop to go over groups
    {
	    cout << "Processing Group: " << i+1 << '\n';
	    cout << "Initializing Answers";

	    for (int j = 0; j < 26 ; j++)
	    {
		    al_answers[j] = 0;
	    }


	    cout << "Parsing individual Answers";
	    l_size = 0;
	    while ( i < vs_input.size() && vs_input[i].length() >0 ) // loop over every members answers
	    {
		    for ( char c : vs_input[i] )
		    {
			l_tmp = c - l_base;
			al_answers[l_tmp] += 1;
		    }

		    l_size++;
		    i++;
	    }


	    cout << "Counting Answers";
	    l_current = 0;
	    for (int j = 0; j < 26 ; j++)
	    {
		    if(al_answers[j] == l_size) l_current+=1;
	    }

	    l_cum += l_current;

	    cout << "There were " << l_current << " postive answers\n";
	    cout << "\n";

    }
    cout << "The sum of all answers is " << l_cum << '\n';





    return 1;

}

