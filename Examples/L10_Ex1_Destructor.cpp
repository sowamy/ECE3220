// L10_Ex1_Destructor.cpp
#include <iostream>
#include <cstring>

using namespace std;	// with this, we won't need the std::

class MyClass{
	private:
		int *data;
		int length;
	public:
		MyClass();		// default constructor.
		MyClass(int);	// parametric constructor
		~MyClass();		// destructor
};

MyClass::MyClass(){
	length = 0;
	data = NULL;
	cout << "\nDefault constructor" << endl;
}

MyClass::MyClass(int L){
	length = L;
	data = new int[L]; // instead of 'malloc', which would work as well
	if(data == NULL)
		cerr << "Error in memory allocation";
	
	cout << "\nParametric constructor, length =  " << length << endl;
}

MyClass::~MyClass(){
	delete[] data;	// instead of 'free'
	cout << "\nDestructor" << endl;
}

int main(){
	MyClass obj1(1), obj2;	// The corresponding constructor is called here.
	MyClass *objPtr = new MyClass(10); // constructor called here, too.
	
	{
		MyClass obj3(5);	// scope: inside the {} block
	}
	cout << endl << "After {}" << endl;
	
	delete objPtr;
	cout << endl << "After delete objPtr" << endl;
	
	return 0;
}