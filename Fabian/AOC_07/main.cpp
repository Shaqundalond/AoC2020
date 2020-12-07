#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

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


// CLASS DEFINITION
// TODO new file and learn to makefile!
class Rule
{
	string name;
	public:
		vector<string> vs_subbags;
		vector<int> vl_subamount;
		Rule (const string &text);
		string out();
		bool contains(const string &child);
		string parent();
		bool is_parent(const string &text ) const ;
};

Rule::Rule(const string &text)
{
	vector<string> vs_container;
	vector<string> vs_childContainer;
	string token;				//used to store childs
	int a;					// store the splitting point
	int b = 0; 					// amount to delete from the end

	// splitting the input on contain to separate into parent and children
	// parent is in container[0]
	//all children are in container[1]
	a = text.find(" contain ");
	vs_container.push_back(text.substr(0, a));
	vs_container.push_back(text.substr(a + 9));


	//parent name = container[0] without ( \ bags)
	name = vs_container[0].substr(0, vs_container[0].length() - 5);

	// find subbags
	// escape on no subbags
	if ( vs_container[1].find("no other bags") != string::npos)
	{
		// set the values to none
		vl_subamount.push_back(0);
		vs_subbags.push_back("0");

		return;
	}

	stringstream ss(vs_container[1]);

	while( getline(ss, token, ','))
	{
		if(token.find(' ') == 0)
		{
			token.erase(0,1);
		}
		b = token.find_last_of(' '); // last space to remove the bag/bags/bag./bags.
		token.erase(b, string::npos);

		// get num and string
		b = token.find(' ');
		vl_subamount.push_back(stoi(token.substr(0)));
		vs_subbags.push_back(token.substr(b + 1, string::npos));

	}



	// iterate over rest

}


bool Rule::contains(const string &child)
{

	if (find(vs_subbags.begin(), vs_subbags.end(), child) != vs_subbags.end() )
	{
		return true;
	}

	return false;
}

bool Rule::is_parent(const string &text) const
{
	return ( name.find(text) != string::npos );
}

string Rule::parent()
{
	return name;
}


string Rule::out()
{
	string out;
	out.append("The Top Bag is: ");
	out.append(name);
	out.append("\n");

	for (int i = 0; i < vs_subbags.size(); i++)
	{
		out.append("Subbag: ");
		out.append(vs_subbags[i]);
		out.append(" ");
		out.append(to_string(vl_subamount[i]));
		out.append("\n");
	}
	out.append("\n");

	return out;

}



void recursive_searchbag(const string &search, vector<string> &topbags, const vector<Rule> &ruleset)
{
	for ( Rule rule : ruleset)
	{
		if (rule.contains(search) &&
				!(find(topbags.begin(), topbags.end(), rule.parent()) != topbags.end()))
		{
			topbags.push_back(rule.parent());
			recursive_searchbag(rule.parent(), topbags, ruleset);
		}
	}

	return;
}

int recursive_subbags(const string &parent, const vector<Rule> ruleset)
{
	int count = 0;
	// find parent in ruleset
	for (int i = 0; i < ruleset.size(); i++)
	{
		if( ruleset[i].is_parent(parent))
		{
			// iterate over children
			if ( ruleset[i].vs_subbags[0] == "0" ) // we reached the end
			{
				return 0;
			}

			for( int j = 0; j < ruleset[i].vs_subbags.size() ; j++ )
			{
				count += ruleset[i].vl_subamount[j] + (ruleset[i].vl_subamount[j] * recursive_subbags(ruleset[i].vs_subbags[j], ruleset));
			}
		}
	}

	return count;

}



int main()
{

    vector<string> vs_input;		// store the inputfield
    string input = "input";

    vector<Rule> vr_ruleset;

    string s_start = "shiny gold";	// Search for this bag
    vector<string> vs_topbags;		// store the topbags
    //vs_topbags.push_back("shiny gold");	// needed to exclude endless recursion
    int count = 0;

    cout << MakeHeadline("Advent of Code 2020 Puzzle # 07",'=') << endl;

    if (!read_input(vs_input, input))
    {
	    return 1;
    }

    cout << "reading file [ " << input << " ] finished\n";


    cout << "Creating Ruleset \n";

    for (string rule : vs_input)
    {
	vr_ruleset.push_back(Rule(rule));
    }

    cout << "Ruleset created\n";
    for (Rule rule : vr_ruleset)
    {
	    cout << rule.out();
    }

    cout << "starting Search\n";

    recursive_searchbag(s_start, vs_topbags, vr_ruleset);

    cout << "Number of Bags: " << vs_topbags.size() << "\n";

    count = recursive_subbags(s_start, vr_ruleset);
    cout << "Number of Bags in " << s_start << ": " << count << '\n';

    return 1;

}

