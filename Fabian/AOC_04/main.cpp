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
bool check_validity(const string &pass)
{

    bool byr = false;
    bool iyr = false;
    bool eyr = false;
    bool hgt = false;
    bool hcl = false;
    bool ecl = false;
    bool pid = false;
    //bool cid = false;
    string s_value;
    int l_tmp;

    // TODO speed up by making else clauses with return false

    if (pass.find("byr:") != string::npos )
    {
	extract_substring(pass, s_value, "byr:");
	// byr speciic checks
	cout << "testing byr:\n";
	cout << s_value << '\n';
	if (s_value.length() == 4 && stoi(s_value) >= 1920 && stoi(s_value) <= 2002) byr = true;
	cout << byr << '\n';

    }

    if (pass.find("iyr:") != string::npos )
    {
	extract_substring(pass, s_value, "iyr:");

	// iyr specific checks

	cout << "testing iyr:\n";
	cout << s_value << '\n';
	if (s_value.length() == 4 && stoi(s_value) >= 2010 && stoi(s_value) <= 2020) iyr = true;

	cout << iyr << '\n';
    }

    if (pass.find("eyr:") != string::npos )
    {
	extract_substring(pass, s_value, "eyr:");

	// iyr specific checks

	cout << "testing eyr:\n";
	cout << s_value << '\n';
	if (s_value.length() == 4 && stoi(s_value) >= 2020 && stoi(s_value) <= 2030) eyr = true;
	cout << eyr << '\n';
    }

    if (pass.find("hgt:") != string::npos )
    {
	//extract value


	extract_substring(pass, s_value, "hgt:");

	cout << "testing hgt:\n";
	cout << s_value << '\n';

	l_tmp = stoi(s_value);
	// check for cm
	if (s_value.at(s_value.length()-1) == 'm' )
	{
	    if (l_tmp >= 150 && l_tmp <= 193) hgt = true;
	}
	else if (s_value.at(s_value.length()-1) == 'n' )
	{
	    if (l_tmp >= 59 && l_tmp <= 76) hgt = true;
	}
	cout << hgt << '\n';
    }

    if (pass.find("hcl:") != string::npos )
    {
	extract_substring(pass, s_value, "hcl:");

	cout << "testing hcl:\n";
	cout << s_value << '\n';

	if (s_value.at(0) == '#' && s_value.find_first_not_of("0123456789abcdef", 1) == string::npos) hcl = true;
	cout << hcl << '\n';

    }
    if (pass.find("ecl:") != string::npos )
    {
	//amb blu brn gry grn hzl oth
	extract_substring(pass, s_value, "ecl:");


	cout << "testing ecl:\n";
	cout << s_value << '\n';

	if (s_value == "amb" || s_value == "blu" || s_value == "brn" || s_value == "gry" || s_value == "grn" || s_value == "hzl" || s_value == "oth" ) ecl = true;
	cout << ecl << '\n';

    }
    if (pass.find("pid:") != string::npos )
    {

	extract_substring(pass, s_value, "pid:");


	cout << "testing pid:\n";
	cout << s_value << '\n';

	if (s_value.length() == 9 && s_value.find_first_not_of("0123456789") == string::npos) pid = true;
	cout << pid << '\n';
    }

    return byr && iyr && eyr && hgt && hcl && ecl && pid;

}




int main()
{

    vector<string> vs_input;		// store the inputfield
    string input = "input";
    string s_toTest = "";
    int l_counter =0;
    int l_pcount = 1;

    cout << MakeHeadline("Advent of Code 2020 Puzzle # 04",'=') << endl;

    if (!read_input(vs_input, input))
    {
	    return 1;
    }

    for ( string lol : vs_input )
    {
	    cout << lol << '\n';
    }

    cout << "reading file [ " << input << " ] finished\n";
    for (int i = 0; i< vs_input.size() ; i++)
    {
	cout << "Scanning " << l_pcount << "th passport\n";
	s_toTest.clear();

	// generate new string to test
	while( i < vs_input.size() && vs_input[i].length() !=0)	//1. cond to keep in bounds
	{
	    s_toTest.append(" ");
	    s_toTest.append(vs_input[i]);

	    i++;
	}

	//dirty hack to keep validitycheck simple
	// TODO better solution
	s_toTest.append(" ");

	if (check_validity(s_toTest))
	{
	    l_counter++;
	}

	l_pcount++;

    }

    cout << "Number of valid passports\n";
    cout << l_counter << '\n';




    return 1;

}

