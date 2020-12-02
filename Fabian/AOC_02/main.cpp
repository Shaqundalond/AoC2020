#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
   //initialie the array size
   vector<string> vs_input;
   string store;
   int l_resultcount;
   int l_charcount;

   int l_min;
   string s_min;

   int l_max;
   string s_max;

   char c_param;

   // PART 2 extra variables
   bool b_min;
   bool b_max;

   int l_tmpstrpos;

   ifstream is;
   is.open("input");
   // check that array is not already full

   // THIS METHOD SPLITS AT WHITESPACES!
   // x-y A: PASSWORD
   // is split into 3 seperae strings
   while (is >> store) {
   	vs_input.push_back(store);
   }

   // Go through input in step of three
   l_resultcount = 0;
   for (int i = 0; i < vs_input.size(); i+=3) {

	   b_min = false;
	   b_max = false;

	   l_charcount = 0;

	   // Split i-th string in min and max separated by '-'
	   l_tmpstrpos = vs_input[i].find_first_of('-');
	   s_min = vs_input[i].substr(0, l_tmpstrpos);
	   s_max = vs_input[i].substr(l_tmpstrpos + 1 , string::npos);

	   l_min = stoi(s_min);
	   l_max = stoi(s_max);

	   // extract character from i+1th string
	   c_param = vs_input[i+1].at(0);

	   // PART 1
	   // check if c_param occures between l_min and l_max inclusive
	   /* l_charcount = std::count(vs_input[i+2].begin(), vs_input[i+2].end(), c_param); */

	   /* if ( l_charcount >= l_min && l_charcount <= l_max ) { */
		   /* l_resultcount += 1; */
	   /* } */

	   // PART 2
	   // check if c_param occures ONCE on l_min or l_max; l_min and l_max are 1-indexed
	   b_min = c_param == vs_input[i+2].at(l_min -1);
	   if ( l_min > vs_input[i+2].size() ) {
		   b_max = false;
	   }
	   else {
		   b_max = c_param == vs_input[i+2].at(l_max - 1);
	   }

	   if ( b_min ^ b_max ) {
		l_resultcount += 1;
	   }



	   // SANITYCHECK
	   /* cout << "RANGE: " << s_min << " : " << s_max << '\n'; */
	   /* cout << "CHAR : " << c_param << '\n'; */
	   /* cout << "PASSW: " << vs_input[i+2] << '\n'; */

   }

   // SANITY CHECK
   /* cout<<"The integers are:"<<"\n"; */
   /* for (int i = 0; i < vl_input.size(); i++) { */
   /*    cout << vl_input[i] <<'\n'; */
   /* } */

   is.close();

   cout << l_resultcount << '\n';

}
