// L18_Ex2.cpp

#include <iostream>
#include <cstdlib>

#define EXAMPLE 4	// 1, 2, 3 or 4

using namespace std;

class Type1{
public:
	virtual void mesg();
	Type1() {cout << "Constructor 1" << endl;}
};

class Type2: public Type1{
public:
	void mesg();
	Type2() {cout << "Constructor 2" << endl;}
};

void Type1::mesg(){
	cout << "Exception of Type 1 Thrown." << endl;
}

void Type2::mesg(){
	cout << "Exception of Type 2 Thrown." << endl;
}

int f1(int x){
	if(x > 0){
		return x;
	} else if(x == 0){
		throw Type1();
	} else if(x < 0){
		throw Type2();
	}
	return -1;
}

int main(int argc, char *argv[]){
	int x;
	
	try{
		if(argc != 2)
			throw 0;
		else {
			x = atoi(argv[1]);
			f1(x);
			cout << "x is: " << x << endl;
		}
	}
// Try all four cases below. What is (are) the difference(s)?
// Explain your observations.
#if EXAMPLE == 1
	catch(Type2 o2){
		o2.mesg();
	}
	catch(Type1 o1){
		o1.mesg();
	}
#endif
	
#if EXAMPLE == 2
	catch(Type1 o1){
		o1.mesg();
	}
	catch(Type2 o2){
		o2.mesg();
	}
#endif

#if EXAMPLE == 3
	catch(Type1 &o1){
		o1.mesg();
	}
#endif

#if EXAMPLE == 4
	catch(Type2 &o2){
		o2.mesg();
	}
#endif
	
	cout << "Good bye." << endl;
}
