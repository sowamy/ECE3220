// L17_Ex1_Exception.cpp

#include <iostream>
using namespace std;

double hmean(double a, double b);

int main() {
	double x, y, z;
	cout << "Enter two numbers: ";
    
    while(cin >> x >> y){
        try{
            z = hmean(x,y);
        }
		// catch blocks (exception handlers)
		// The appropriate one will be used, based on what was thrown.
        catch(const int s){
            cout << "Const. value thrown: " << s << endl
                 << "\nEnter a new pair of numbers <q to quit>: ";
            continue;
        }
        catch(const char * s){
            cout << s << endl
                 << "\nEnter a new pair of numbers <q to quit>: ";
            continue;
        }
		// "catch-all" handler.
        catch(...){
            cout << "\nEnter a new pair of numbers <q to quit>: ";
            continue;
        }
        cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl
             << "\nEnter next set of numbers <q to quit>: ";
    }

	cout << "Bye! \n";
	return 0;
}

double hmean(double a, double b)
{
	if(a == -b){
		throw "bad hmean() arguments: a = -b not allowed";
	}
	// This next condition is just to illustrate throwing a const int.
	// It is okay for a to be greater than b...
    else if(a > b){
        throw (-1);
    }
	return 2.0*a*b / (a+b);
}


