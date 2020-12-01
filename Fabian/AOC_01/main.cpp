#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
   //initialie the array size
   vector<int> vl_input;
   int store;

   ifstream is;
   is.open("input");
   // check that array is not already full

   while (is >> store) {
   // and read integer from file
   	vl_input.push_back(store);
   // print the integers stored in the array
   }
   /* cout<<"The integers are:"<<"\n"; */
   /* for (int i = 0; i < vl_input.size(); i++) { */
   /*    cout << vl_input[i] <<' '; */
   /* } */
   /* //close the file */
   /* cout << '\n' */
   is.close();

   for ( int i = 0; i < vl_input.size(); i++) {
   	for (int j = i; j < vl_input.size(); j ++) {
		if (vl_input[i] + vl_input[j] == 2020 ) {

			cout << vl_input[i] << '\n' ;
			cout << vl_input[j] << '\n' ;
			cout << vl_input[i] * vl_input[j] << '\n';
		}
	}
   }
}
