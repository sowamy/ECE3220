// Lab6_vectors.cpp
// This program shows some simple vector examples, and asks for simple tasks.
// Reference: Lippman, section 3.3

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab6_vectors.cpp -o Lab6_vectors -std=c++11
//      or:  g++ Lab6_vectors.cpp -o Lab6_vectors -std=c++0x
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <vector>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	vector<int> ivec1(5), ivec2;
	vector<double> dvec1{5.1}, dvec2(5,1.5);
	vector<string> svec1 = {"hello", "world"};
	// vector<myClass> myCvec;	// you can have vectors of objects
	// in general: vector<Type> vec;	// vector is a "template"

	for(int i = 0; i < ivec1.size(); i++)
		cout << ivec1[i] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:ivec1)	// This is equivalent to the above for loop
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec2)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:svec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
		
	cout << "Original size: " << ivec2.size() << endl;
	ivec2.push_back(50);
	cout << "New size: " << ivec2.size() << "\nAdded element: " << ivec2[0] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
// ***********************************************************************
	vector<int>v0 = {0,1,2,3,4,5,6,7,8,9};
	vector<int>v1;
	vector<int>v2(v0);

	vector<int>v3 = v0;
	vector<int>v4(2,5);
	vector<int>v5(3);
	vector<int>v6{1,2,3,4,5,6,7};
	vector<int>v7 = {9,8,7,6,5,4,3};
	
	cout << "\n******************************************************************" << endl;
	cout << "v1: " << endl;
	for( auto i:v1 )
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	cout << "v2: " << endl;
	for( auto i:v2 )
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	cout << "v3: " << endl;	
	for( auto i:v3 )
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	cout << "v4: " << endl;	
	for( auto i:v4 )
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	cout << "v5: " << endl;
	for( auto i:v5 )
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	cout << "v6: " << endl;
	for( auto i:v6 )
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	cout << "v7: " << endl;
	for( auto i:v7 )
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	cout << "\n******************************************************************" << endl;
// ***********************************************************************




// ***********************************************************************
// Try all the ways to initialize a vector shown in Table 3.4. Use the
// vectors above and/or declare new vectors.
// Some of those operations have already been used, but write your
// own examples.

// Do exercises 3.14 and 3.15 from Lippman (page 102)

// Try all the vector operations shown in table 3.5. Use the vectors above
// or define new ones. Try different types.
// ***********************************************************************

	return 0;
}
