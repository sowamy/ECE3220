// L11_Ex1_Inheritance.cpp
// By Luis Rivera

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

// --------- BaseSig class and methods ------------------------------
class BaseSig{
	private:
		// neither derived classes nor other users
		// can access private members
	
	protected:	// accessible by derived classes, not by other users.
		int length;
		int *raw_data;
		
	public:
		BaseSig();		// default constructor.
		BaseSig(int L);	// parametric constructor
		virtual ~BaseSig();		// virtual destructor
		int getLength() { return length; };
		int getRawValue(int pos);
		static int numObjects;	// static, only one member for the entire hierarchy
		virtual void printInfo();
		// Assignment 5
		void getFileInfo();
};

int BaseSig::numObjects = 0;	// initialize static data member

// Base class constructor
BaseSig::BaseSig(){
	length = 0;
	raw_data = NULL;
	numObjects++;
}

// Base class parametric constructor
// Note that the data array is not being initialized (we could read from a file)
BaseSig::BaseSig(int L){
	length = L;
	raw_data = new int[L];
	if(raw_data == NULL)
		cerr << "Error in memory allocation";
	numObjects++;
}

// Base class destructor
BaseSig::~BaseSig(){
	delete raw_data;
	cout << "Goodbye, BaseSig." << endl;
}

int BaseSig::getRawValue(int pos) {
	if(pos < 0)			// invalid index
		return(raw_data[0]);
	else if(pos >= length)	// invalid index
		return(raw_data[length-1]);	
	else
		return(raw_data[pos]);
}

void BaseSig::printInfo() {
	cout << "\nLength: " << length << endl;
}

// Opens file and distributes contents into variable containers
void BaseSig::getFileInfo() {	
	int l;
	int maxMagnitude;
	string line;
	string information;

	ifstream file;
	// Change name of file to open another file
	// Has to be done manually
	file.open( "Raw_data_01.txt" );	// Opens file for processing
	
	if ( file.is_open() )
	{
		getline( file, information );
		istringstream iss;
		iss.str( information );
		iss >> l;
		iss >> maxMagnitude;
		length = l;

		BaseSig( length );

	    for( int i = 0; i < l; i++ ) {
	    	getline( file, line );
	    	raw_data[ i ] = atoi( line.c_str() );	// Must use c_str function to allow string const_chat to be converted to an int
	    }

	    file.close();
	}
}
// ------------------------------------------------------------------

// --------- ExtendSig class and methods ----------------------------
class ExtendSig : public BaseSig{ // ExtendSig is derived from class BaseSig
//BaseSig is a public base class
	private: 
		double average;		// add new data members
		double *data;
		
	public:
		ExtendSig(int L);	//derived classes need a new constructor
		~ExtendSig();
		
		// define new member functions
		double getValue(int pos);
		int setValue(int pos, double val);
		double getAverage();
		
		// redefine member function. Virtual keyword not needed
		void printInfo();	// new standard: explicit "override" keyword can be used
};

// Derived class constructor. Note how the Base constructor is called.
ExtendSig::ExtendSig(int L) : BaseSig(L) {
	data = new double[L];
	if(data == NULL)
		cerr << "Error in memory allocation";
	else{
		for(int i = 0; i < L; i++)
			data[i] = (double)raw_data[i];
		average = getAverage();
	}
}

// Derived class destructor
ExtendSig::~ExtendSig() {
	delete data;
	cout << "Goodbye, ExtendSig." << endl;
}

double ExtendSig::getValue(int pos) {
	if(pos < 0)			// invalid index
		return(data[0]);
	else if(pos >= length)	// invalid index
		return(data[length-1]);	
	else
		return(data[pos]);
}

int ExtendSig::setValue(int pos, double val) {
	if((pos < 0) || (pos >= length))
		return(-1);	// invalid index
	else {
		data[pos] = val;
		average = getAverage();
		return(0);	// success
	}
}

double ExtendSig::getAverage() {
	if(length == 0)
		return(0.0);
	else {
		double temp = 0.0;
		for(int i = 0; i < length; i++)
			temp += data[i];
		return(temp/(double)length);
	}
}

// Redefined printInfo function for derived class
void ExtendSig::printInfo() {
	cout << "\nLength: " << length << endl
		 << "Average: " << average << endl;
}
// ------------------------------------------------------------------

// Main function. A few examples
int main(){
	BaseSig bsig1;
	cout << "--------------------------------------------" << endl;
	bsig1.getFileInfo();
	cout << "--------------------------------------------" << endl;
	return 0;
}