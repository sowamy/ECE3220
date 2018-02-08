/*
 ============================================================================
 Name        : main.cpp
 Author      : Angelino Lefevers
 Version     : 1.0
 Class		 : ECE 3220
 Lab #		 : 6
 Description : Takes in signal from file, modifies it, and saves it to 
 			   another file. This program features the use of vector and
			   string operations.
 ============================================================================
 */

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>

using namespace std;

// Used to convert type string to type char*
#define SSR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class Signal{
	private:
		int length;
		double maxValue;
		double average;
		void findAverage();
		void findMax();	
	
	public:
		// Data
		vector<double> dataVector;

		// Constructors
		Signal();
		Signal( int fileNumber );
		Signal( string fileName );

		// Deconstructor
		~Signal();

		// Operators
		void operator+( double offset );
		void operator-( double offset );
		void operator*( double scale );

		// Methods
		void scale( double s );
		void center();
		void normalize();
		void printSignal();
		void Sig_info();
		void getFileData( string fileName );
		void Save_file( string fileName );
		void appendSignal( double data ) { dataVector.push_back(data); }

		// Getter Methods
		double getSample( int n ) { return dataVector[n]; }
		double getLength() { return length; }
};

/* CLASS: Signal
 * METHOD: Signal()
 * DESCRIPTION: Gets data from default file
 */
Signal::Signal() {
	// Lab 6 - Empty data vector, and default attributes of signal
	length = 0;
	maxValue = 0;
	average = 0.0;
} // END METHOD Signal::Signal

/* CLASS: SIGNAL
 * METHOD: Signal( int fileNumber )
 * DESCRIPTION: Gets data from Raw_data file with the number <fileNumber>
 */
Signal::Signal( int fileNumber ) {
	if( fileNumber < 10 ) {
		string fileName = "Raw_data_0" + SSR(fileNumber) + ".txt";
		getFileData( fileName );
	} else {
		string fileName = "Raw_data_" + SSR(fileNumber) + ".txt";
		getFileData( fileName );
	}
} // END METHOD Signal::Signal

/* CLASS: Signal
 * METHOD: Signal( string fileName )
 * DESCRIPTION: Gets data from file name <fileName>
 */
 Signal::Signal( string fileName ) {
 	getFileData( fileName );
 } // END METHOD Signal::Signal

/* CLASS: ~Signal
 * DESCRIPTION: Deconstructor that frees the data allocated to class variable
 *				<data> after the object that variable is a type of is destroyed.
 */
Signal::~Signal() {
} // END METHOD Signal::~Signal

/* CLASS: Signal
 * METHOD: + operator - offsets signal
 * DESCRIPTION: Adds the offset to every sample in the signal
 */
void Signal::operator+( double offset ) {
	for( int i = 0; i < length; i++ ) {
		dataVector[i] += offset;
	} // END FOR : offsets each element in <dataVector>
} // END METHOD OPERATOR Signal::operator+

/* CLASS: Signal
 * METHOD: - operator - negative offset
 * DESCRIPTION: Subtracts offset from every sample in the signal
 */
void Signal::operator-( double offset ) {
	for( int i = 0; i < length; i++ ) {
		dataVector[i] -= offset;
	} // END FOR : offsets each element in <dataVector>
} // END METHOD OPERATOR SIGNAL::operator-

/* CLASS: Signal
 * METHOD: * operator - scale signal
 * DESCRIPTION: Scales every sample in the signal by <scale>
 */
void Signal::operator*( double scale ) {
	for( int i = 0; i < length; i++ ) {
		dataVector[i] *= scale;
	} // END FOR : iterates and scales every sample in signal
} // END METHOD OPERATOR SIGNAL::operator*

/* CLASS: Signal
 * METHOD: getFileData
 * DESCRIPTION: Gets the length and max sample value of the signal which has the name represented by
 * 				the string <fileName>. Also, get every sample within that signal and references using
 * 				the <data> pointer.
 */
void Signal::getFileData( string fileName ) {

	// TEST: Print maximum size of <dataVector>
	// cout << "Vector Size: " << dataVector.max_size() << endl;

	string line;
	string raw;

	ifstream dataFile;
	dataFile.open( fileName.c_str() );

	if( dataFile.is_open() )
	{
		getline( dataFile, raw );
		istringstream iss;
		iss.str( raw );
		iss >> length;
		iss >> maxValue;

		for( int i = 0; i < length; i++ ) {
			getline( dataFile, line );
			dataVector.push_back( atof( line.c_str() ) );
		} // END for 

		dataFile.close();		
	} else {
		cout << "ERROR: File unable to be opened" << endl;
	} // END if...else
} // END METHOD Signal::getFileInfo

/* CLASS: Signal
 * METHOD: findAverage()
 * DESCRIPTION: Finds the average of the signal
 */
void Signal::findAverage() {
	double sum = 0; // Holds the sum of each sample in the signal

	for( int i = 0; i < length; i++ ) {
		// Find sum by adding each sample of a sample organized by vectors
		sum += dataVector[i];
	} // END for

	average = sum / dataVector.size();

	// TEST: Print length and average onto screen
	// cout << endl << "Length: " << length << endl << "Average: " << average << endl;
} // END METHOD findAverage

/* CLASS: Signal
 * METHOD: findMax
 * DESCRIPTION: Goes through each sample in the signal, updating <maxValue>
*/
 void Signal::findMax() {
	// Initiate Max value
	maxValue = dataVector.front();

 	for( int i = 0; i < length; i++ ) {
		// Find max value of <dataVector> 		
		if( dataVector[i] > maxValue ) { maxValue = dataVector[i]; }

		// TEST: Prints <maxValue> - for every sample, and every loop
		// cout << "Max Value: " << maxValue << endl;

 	} // END for
 } // END METHOD maxValue

/* CLASS: Signal
 * METHOD: center
 * DESCRIPTION: Centers each sample in the signal around 0 so that the sum and average is 0.
*/
void Signal::center() {
	findAverage();

	operator+(-average);

	// TEST: Print <average> (private function)
	// cout << "Average: " << average << endl;
} // END METHOD center

/* CLASS: Signal
 * METHOD: normalize
 * DESCRIPTION: Scales all the samples of the signal to be a magnitude between 1 and 0
*/
void Signal::normalize() {
	findMax();
	operator*(1/maxValue);
} // END METHOD normalize

/* CLASS: Signal
 * METHOD: printSignal
 * DESCRIPTION: Prints every element of that <data> points to of class <Signal>
 */
void Signal::printSignal() {
	for( int i = 0; i < length; i++ ) {
		// Prints each sample using <dataVector>
		cout << dataVector[i] << endl;
	}
} // END METHOD printSignal

/* CLASS: Signal
 * METHOD: Sig_info
 * DESCRIPTION: Prints the length, max value, and average of the signal
*/
void Signal::Sig_info() {
	findMax();
	findAverage();

	cout << "\nSignal Information:\t" << endl;
	cout << "Length:\t" << length << endl;
	cout << "Maximum Value:\t" << maxValue << endl;
	cout << "Average Value:\t" << average << endl << endl;
} // END METHOD Sig_info

/* CLASS: Signal
 * METHOD: Save_file
 * DESCRIPTION: Saves the signal to a Raw_data_xx.txt file with xx being equal to <fileNumber> input
*/
void Signal::Save_file( string fileName ) {

	ofstream dataFile;
	dataFile.open( fileName.c_str() );

	if( dataFile.is_open() )
	{
		dataFile << length << " " << maxValue << endl;

		for( int i = 0; i < length; i++ ) {
			// Print each sample in <dataVector> into dataFile
			dataFile << dataVector[i] << endl;			
		} // END for
	} else {
		cout << "ERROR: File unable to be opened" << endl;
	} // END if...else
} // END METHOD Save_file

/*	FUNCTION: operator+ 
 * 	DESCRIPTION: Sums two signals contained in two Signal objects
 				 Stores the signal with the sums into the first object inputted into the argument
 *  RETURNS: Bool, describing if the function executed successfully or not
 *				-- 1: Successful Execution
 				-- 0: Unseccessful Execution
 */
Signal operator+( Signal &a, Signal &b ) {

	Signal sum;

	if( a.getLength() != b.getLength() ) {
		cout << endl << "ERROR: TWO LENGTHS OF SIGNALS TO BE ADDED ARE NOT EQUAL" << endl;
		return 0;
	} else {
		for( int i = 0; i < a.getLength(); i++ ) {
			sum.appendSignal( a.dataVector[i] + b.dataVector[i] );
		}
	} // END if...else : tests if the two lengths are equal

	return sum;
} // END FUNCTION addSignals

int main( int argc, char *argv[] )
{
	bool on = true;     // Used to control user interface
	bool menuSelection = false;
	int menuChoice;
	double amount = 0;
	int fileNumber;
	string rawInput;	// Used in user interface
	string fileName;	// Used to store the users file selection
	string fileName2;	// Used to store aditional signal file for processing
     
	// Prompt user to enter file name or number
	while( !menuSelection ) {
		cout << "\nENTER FILE NAME: ";
		cin >> fileName;
		cin.ignore();
		cout << endl << endl << fileName << endl << endl << "ARE YOU SURE\n(Y)ES -OR- (N)O\n--> ";
		cin >> rawInput;
		cin.ignore();
		if( rawInput == "Y" ) { menuSelection = true; }
	}	// END WHILE : User filename selection, flag controlled loop

	Signal signalObj( fileName );
	Signal b, sum;

	while( on ) {
		cout << "\n\nUSER MENU\nENTER NUMBER FOR DESIRED FUNCTIONALITY: " << endl;
		cout << "\t1. OFFSET" << endl;
		cout << "\t2. SCALE" << endl;
		cout << "\t3. CENTER" << endl;
		cout << "\t4. NORMALIZE" << endl;
		cout << "\t5. SIGNAL INFORMATION" << endl;
		cout << "\t6. PRINT SIGNAL" << endl;
		cout << "\t7. SAVE SIGNAL" << endl;
		cout << "\t8. ADD ANOTHER SIGNAL" << endl;
		cout << "\t0. EXIT\n--> ";
		cin >> menuChoice;
     
		switch( menuChoice ) {
			case 0:
				on = false;
				break;
			case 1:
				cout << "\n\nENTER AMOUNT TO OFFSET: ";
				cin >> amount;
				signalObj.operator+(amount);
				signalObj.printSignal();
				break;
			case 2:
				cout << "\n\nENTER AMOUNT TO SCALE: ";
				cin >> amount; 
				signalObj.operator*( amount );
				signalObj.printSignal();
				break;
			case 3:
				signalObj.center();	
				signalObj.printSignal();
				break;
			case 4:
				signalObj.normalize();	
				signalObj.printSignal();	
				break;
			case 5:
				signalObj.Sig_info();
				break;
			case 6: 
				signalObj.printSignal();
				break;
			case 7: 
				cout << "\n\nFILE NAME TO SAVE DATA: ";
				cin >> fileName;
				signalObj.Save_file( fileName );
				break;
			case 8:
				cout << "\n\nFILE STORING SIGNAL TO SUM WITH THE CURRENT SIGNAL\n--> ";
				cin >> fileName2;
				cin.ignore();
				b.getFileData( fileName2 );
				sum = operator+( signalObj, b );
				cout << "RESULTING SIGNAL: " << endl;
				sum.printSignal();
				break;
			default:
				cout << "ERROR: INVALID INPUT, TRY AGAIN...\n\n\n" << endl;
				break;
		}
	}
	return 0;
} // END FUNCTION main
