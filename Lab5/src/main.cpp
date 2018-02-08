/*
 ============================================================================
 Name        : main.cpp
 Author      : Angelino Lefevers
 Version     : 1.0
 Class		 : ECE 3220
 Lab #		 : 5
 Description : Takes in signal from file, modifies it, and saves it to 
 			   another file.
 ============================================================================
 */

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

// Function Prototypes
void printDoubleArray( double *inputArray, int length, string title );

// Used to convert type string to type char*
#define SSR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class Signal{
	private:
		int length;
		double maxValue;
		double average;
		double *data;
		void findAverage();
		void findMax();
		void getFileData( string fileName );
	
	public:
		Signal();
		Signal( int fileNumber );
		Signal( string fileName );
		~Signal();
		void offset( double o );
		void scale( double s );
		void center();
		void normalize();
		void printSignal();
		void Sig_info();
		void Save_file( int fileNumber );
};

/* CLASS: Signal
 * METHOD: Signal()
 * DESCRIPTION: Gets data from default file
 */
Signal::Signal() {
	getFileData( "Raw_data_01.txt" );
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
	free( data );
} // END METHOD Signal::~Signal

void Signal::offset( double o ) {
 	double *pointer = data;

 	for( int i = 0; i < length; i++ ) {
 		*pointer = *pointer + o;
		pointer++;
	}
}

void Signal::scale( double s ) {
 	double *pointer = data;

 	for( int i = 0; i < length; i++ ) {
 		*pointer = *pointer * s;
		pointer++;
	}
}

/* CLASS: Signal
 * METHOD: getFileData
 * DESCRIPTION: Gets the length and max sample value of the signal which has the name represented by
 * 				the string <fileName>. Also, get every sample within that signal and references using
 * 				the <data> pointer.
 */
void Signal::getFileData( string fileName ) {

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

		data = new double[ length ];

		if( data == NULL ) {
			cerr << "ERROR: Memory allocation"; 
		} else {

			for( int i = 0; i < length; i++ ) {
				getline( dataFile, line );
				data[ i ] = atof( line.c_str() );
			} // END for
		}	// END if...else
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
	double *pointer = data;

	for( int i = 0; i < length; i++ ) {
		sum += *pointer++;
		// TEST: Print sample and sum onto screen
		// NOTE: Will be a sample off due to increment of <pointer> the line before
		// cout << "Sample: " << *pointer << endl << "Sum: " << sum << endl;
	} // END for

	average = sum / length;

	// TEST: Print length and average onto screen
	// cout << endl << "Length: " << length << endl << "Average: " << average << endl;
} // END METHOD findAverage

/* CLASS: Signal
 * METHOD: findMax
 * DESCRIPTION: Goes through each sample in the signal, updating <maxValue>
*/
 void Signal::findMax() {
 	double *pointer = data;
 	maxValue = *pointer;

 	for( int i = 0; i < length; i++ ) {
 		if( *pointer++ > maxValue ) { maxValue = *pointer; }
 		// TEST: Prints sample and <maxValue> each iteration
 		// cout << "Sample: " << *pointer << endl << "maxValue: " << maxValue << endl;
 	} // END for
 } // END METHOD maxValue

/* CLASS: Signal
 * METHOD: center
 * DESCRIPTION: Centers each sample in the signal around 0 so that the sum and average is 0.
*/
void Signal::center() {
	findAverage();
	double *junk = data;

	for( int i = 0; i < length; i++ ) {
		*junk++ -= average;
	} // END for

	// TEST: Print <average> (private function)
	cout << "Average: " << average << endl;
	
} // END METHOD center

/* CLASS: Signal
 * METHOD: normalize
 * DESCRIPTION: Scales all the samples of the signal to be a magnitude between 1 and 0
*/
void Signal::normalize() {
	double *junk = data;
	findMax();

	for( int i = 0; i < length; i++ ) {
		// TEST: Prints junk, maxValue, and the quotient of the two
		// cout << "junk: " << *junk << "\tmaxValue: " << maxValue << endl;
		// cout << "junk/maxValue: " << *junk / maxValue << endl;

		findMax();
		*junk++ /= maxValue;
	} // END for
} // END METHOD normalize

/* CLASS: Signal
 * METHOD: printSignal
 * DESCRIPTION: Prints every element of that <data> points to of class <Signal>
 */
void Signal::printSignal() {
	double *junk = data; 

	for( int i = 0; i < length; i++ ) {
		cout << *junk++ << endl;
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
void Signal::Save_file( int fileNumber ) {
	double *junk = data;

	string fileName;

	if( fileNumber < 10 ) {
		fileName = "Raw_data_0" + SSR(fileNumber) + ".txt";
	} else {
		fileName = "Raw_data_" + SSR(fileNumber) + ".txt";
	} // END if...else

	ofstream dataFile;
	dataFile.open( fileName.c_str() );

	if( dataFile.is_open() )
	{
		dataFile << length << " " << maxValue << endl;

		for( int i = 0; i < length; i++ ) {
			dataFile << *junk++ << endl;
		} // END for
	} else {
		cout << "ERROR: File unable to be opened" << endl;
	} // END if...else
} // END METHOD Save_file

int main( int argc, char *argv[] )
{
	bool on = true;     // Used to control user interface
	int menuChoice;
	double amount = 0;
	int fileNumber;
	Signal signalObj(12);
     
	while( on ) {
		cout << "\n\nUSER MENU\nENTER NUMBER FOR DESIRED FUNCTIONALITY: " << endl;
		cout << "\t1. OFFSET" << endl;
		cout << "\t2. SCALE" << endl;
		cout << "\t3. CENTER" << endl;
		cout << "\t4. NORMALIZE" << endl;
		cout << "\t5. INFORMATION" << endl;
		cout << "\t6. PRINT SIGNAL" << endl;
		cout << "\t7. SAVE SIGNAL" << endl;
		cout << "\t0. EXIT\n--> ";
		cin >> menuChoice;
     
		switch( menuChoice ) {
			case 0:
				on = false;
				break;
			case 1:
				cout << "\n\nENTER AMOUNT TO OFFSET: ";
				cin >> amount;
				signalObj.offset( amount );
				signalObj.printSignal();
				break;
			case 2:
				cout << "\n\nENTER AMOUNT TO SCALE: ";
				cin >> amount; 
				signalObj.scale( amount );
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
				cout << "\n\nFILE NUMBER TO SAVE: ";
				cin >> fileNumber;
				signalObj.Save_file( fileNumber );
				break;
			default:
				cout << "ERROR: INVALID INPUT, TRY AGAIN...\n\n\n" << endl;
				break;
		}
	}
	return 0;
} // END FUNCTION main

/* FUNCTION: printDoubleArray
 * DESCRIPTION: Used to print an array of type double and with a length of <length>.
 * 				Used to visualize a variety of results
*/
void printDoubleArray( double *inputArray, int length, string title ) {
	double *array = inputArray;

	cout << endl << title << endl;

	for( int i = 0; i < length; i++ ) {
		cout << *inputArray++ << endl;
	} // END for
} // END FUNCTION printDoubleArray
