// Simple_formatting.cpp
// Luis Rivera

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float x = 9.123456789;
	int i = 10;
		
	// Formatting - some examples. There are other functions/options.
	cout << "\nFormatting output: \n";
	cout << x << endl << setprecision(1) << x << endl << setprecision(3) << x << endl
		 << setprecision(6) << x << endl << x << endl;
		 
	cout << i << endl << setw(1) << i << endl << setw(3) << i << endl
		 << setw(4) << i << endl << setw(5) << i << endl;
		 
	cout << setfill('0') << setw(4) << i << endl << setfill('*') << setw(5) << i << endl;
	return 0;
}