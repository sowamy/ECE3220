// Lab6_strings.cpp
// This program shows some simple string examples, and asks for simple tasks.
// Reference: Lippman, section 3.2

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab6_strings.cpp -o Lab6_strings -std=c++11
//      or:  g++ Lab6_strings.cpp -o Lab6_strings -std=c++0x
// Some initialization methods and other things are not supported by the old standard. 

#include <iostream>
#include <string>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	string s1, s2("Hello"), s3 = "World";

// ***********************************************************************
	cout << "\n*****************************" << endl;
	cout << "s1.empty(): " << s1.empty() << endl;
	cout << "s1.size(): " << s1.size() << endl;
	cout << "s1[0]: " << s1[0] << endl;
	cout << "s1[3]: " << s1[3] << endl;
	cout << "s1[5]: " << s1[5] << endl;
	cout << "s1 + \"word\": " << s1 + "word" << endl;
	cout << "s1 == \"word\": " << ( s1 == "word" ) << endl;
	cout << "s1 != \"word\": " << ( s1 != "word" ) << endl;
	cout << "s1 < \"word\": " << ( s1 < "word" ) << endl;
	cout << "s1 > \"word\": " << ( s1 > "word" ) << endl;
	cout << "*****************************" << endl;
// ***********************************************************************

	cout << "\nEnter a word:" << endl;
	cin >> s1;	// input->s1
	cin.ignore();	// to consume the '\n' character. Otherwise, you may get issues with
						// the getline() below. Try commenting this out. Any issues?

/*
RESULTS: COMMENTING cin.ignore()
IMAGE: lab6_strings_commentOut_ciignoreRESULT.png
OBSERVATIONS:
	- Does not throw compilation error
	- There is a logical error
	- Does not allow user to enter text after "Enter some text: " prompt
	- This is probably because the '\n' character takes the place of the user input
	- There is an extra space between "Enter some text: " and the "Enter some text, finish with an &" prompts
*/

// ***********************************************************************		
	cout << "\n*****************************" << endl;
	cout << "s1.empty(): " << s1.empty() << endl;
	cout << "s1.size(): " << s1.size() << endl;
	cout << "s1[0]: " << s1[0] << endl;
	cout << "s1[3]: " << s1[3] << endl;
	cout << "s1[5]: " << s1[5] << endl;
	cout << "s1 + \"word\": " << s1 + "word" << endl;
	cout << "s1 == \"word\": " << ( s1 == "word" ) << endl;
	cout << "s1 != \"word\": " << ( s1 != "word" ) << endl;
	cout << "s1 < \"word\": " << ( s1 < "word" ) << endl;
	cout << "s1 > \"word\": " << ( s1 > "word" ) << endl;
	cout << "*****************************" << endl << endl;
// ***********************************************************************

	string s4(s1);		// s4 = s1 (input)
	
	cout << s1 << endl	// user input
		 << s2 << endl	// Hello
		 << s3 << endl	// World
		 << s4 << endl;	// s1 (input)
			
	s1 = s2 + s3;		// s1 = Hello + World
	cout << s1 << endl;	// HelloWorld

// ***********************************************************************
// Try all the operations in Table 3.2 using the strings above and
// using new strings that you may declare.
// Some of those operations have already been used, but write your
// own examples.
// ***********************************************************************

// -----------------------------------------------------------------------
	string line;
	string line2;

// ***********************************************************************
	cout << "\n*****************************" << endl;
	cout << "line.empty(): " << line.empty() << endl;
	cout << "line.size(): " << line.size() << endl;
	cout << "line[0]: " << line[0] << endl;
	cout << "line[3]: " << line[3] << endl;
	cout << "line[5]: " << line[5] << endl;
	cout << "line + \"word\": " << line + "word" << endl;
	cout << "line == \"word\": " << ( line == "word" ) << endl;
	cout << "line != \"word\": " << ( line != "word" ) << endl;
	cout << "line < \"word\": " << ( line < "word" ) << endl;
	cout << "line > \"word\": " << ( line > "word" ) << endl;
	cout << "*****************************" << endl << endl;
// ***********************************************************************

	cout << "\nEnter some text:" << endl;
	getline(cin, line);

// ***********************************************************************
	cout << "\n*****************************" << endl;
	cout << "line.empty(): " << line.empty() << endl;
	cout << "line.size(): " << line.size() << endl;
	cout << "line[0]: " << line[0] << endl;
	cout << "line[3]: " << line[3] << endl;
	cout << "line[5]: " << line[5] << endl;
	cout << "line + \"word\": " << line + "word" << endl;
	cout << "line == \"word\": " << ( line == "word" ) << endl;
	cout << "line != \"word\": " << ( line != "word" ) << endl;
	cout << "line < \"word\": " << ( line < "word" ) << endl;
	cout << "line > \"word\": " << ( line > "word" ) << endl;
	cout << "*****************************" << endl << endl;
// ***********************************************************************

	cout << line << endl;
// ***********************************************************************
	cout << "\n*****************************" << endl;
	// Converts all characters in the string <line> to uppercase
	for( auto& element: line ) {
  		element = toupper( element );
 	} // END for
	// toupper() using "for range"
	cout << "toupper: " << line << endl;
	
	// Converts all characters in the string <line> to lowercase
	for( auto& element: line ) {
		element = tolower( element );
	} // END for
	// tolower() using "for range"
	cout << "tolower: " << line << endl;

	// Converts all whitespace characters in the string <line> to '.'
	for( auto& element: line ) {
		if( isspace( element ) ) { element = '.'; }
	} // END for
	// Whitespace to '.' using "for range"
	cout << "Whitespace to \'.\': " << line << endl;
	
	cout << "*****************************" << endl << endl;
// ***********************************************************************		
	
	cout << "\nEnter some text, finish it with an &:" << endl;
	getline(cin, line, '&');	// the delimiter can be any character

	cout << line << endl;

// ***********************************************************************
	cout << "\n*****************************" << endl;
	cout << "line.empty(): " << line.empty() << endl;
	cout << "line.size(): " << line.size() << endl;
	cout << "line[0]: " << line[0] << endl;
	cout << "line[3]: " << line[3] << endl;
	cout << "line[5]: " << line[5] << endl;
	cout << "line + \"word\": " << line + "word" << endl;
	cout << "line == \"word\": " << ( line == "word" ) << endl;
	cout << "line != \"word\": " << ( line != "word" ) << endl;
	cout << "line < \"word\": " << ( line < "word" ) << endl;
	cout << "line > \"word\": " << ( line > "word" ) << endl;
	cout << "*****************************" << endl << endl;
// ***********************************************************************

// ***********************************************************************
	cout << "\n*****************************" << endl;
	// Converts all characters in the string <line> to uppercase
	for( auto& element: line ) {
  		element = toupper( element );
 	} // END for
	// toupper() using "for range"
	cout << "toupper: " << line << endl;
	
	// Converts all characters in the string <line> to lowercase
	for( auto& element: line ) {
		element = tolower( element );
	} // END for
	// tolower() using "for range"
	cout << "tolower: " << line << endl;

	// Converts all whitespace characters in the string <line> to '.'
	for( auto& element: line ) {
		if( isspace( element ) ) { element = '.'; }
	} // END for
	// Whitespace to '.' using "for range"
	cout << "Whitespace to \'.\': " << line << endl;
	
	cout << "*****************************" << endl << endl;
// ***********************************************************************	

// ***********************************************************************
// Use a "Range for" (Lippman, page 93) and operations in table 3.3 to:
// 1) change the case of the letters in your input line above (upper to
//    lowercase and vice-versa).
// 2) Replace any whitespace with a dot ('.').
// Print the converted text.
// ***********************************************************************

	return 0;
}
