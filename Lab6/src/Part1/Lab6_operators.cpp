// Lab6_operators.cpp
// This program provides a few examples about operators in C++
// Study the code, run it, pay attention to the comments and questions
// posted, and use the ideas to complete the assignments described in
// the lab 6 guide.
// Reference: Lippman, sections 14.1 - 14.4

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab6_operators.cpp -o Lab6_operators -std=c++11
//      or:  g++ Lab6_operators.cpp -o Lab6_operators -std=c++0x
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>

using namespace std;

class Lab6
{
public:
	int a[2]; // could be private, but methods would be needing to access this member.
	
	// operators as member functions: 'this' is bound to the left hand operand
	bool operator>(const Lab6 &x) const;
	void operator+(const Lab6 &x);
	void operator*(int factor);
	void Printvals();
	// constructor(s)
	// destructor
	~Lab6() { cout << "Object Destroyed." << endl; }
};

// --------------- Member functions ---------------------------------
bool Lab6::operator>(const Lab6 &x) const
{
	if ((a[0] > x.a[0]) & (a[1] > x.a[1]))
		return 1;
	else
		return 0;
}

void Lab6::operator+(const Lab6 &x)
{
	a[0] += x.a[0];
	a[1] += x.a[1];
}

void Lab6::operator*(int factor)
{
	a[0] *= factor;
	a[1] *= factor;
}

void Lab6::Printvals()
{
	cout << "\na[0] = " << a[0] << ", a[1] = " << a[1] << endl;
}

// -------- Operators can be Non-member functions -------------------
Lab6 operator+(const Lab6 &lhs, const Lab6 &rhs)
{
	Lab6 sum;
	sum.a[0] = lhs.a[0] + rhs.a[0];
	sum.a[1] = lhs.a[1] + rhs.a[1];
	
	return sum;
}

// Main function. Shows a few examples about using the operators.
int main()
{
	Lab6 obj1, obj2, obj3;
	int f = 10;
	
	obj1.a[0] = 1; obj1.a[1] = 5;
	obj2.a[0] = 10; obj2.a[1] = 20;
	
	// If obj1[0] and obj1[1] are greater than obj2[0] and obj2[1] respectively, then the condition is true
	if(obj1 > obj2)	// normal expression. Which operator is being called?
					// The > operator [bool Lab6::operator>(const Lab6 &x) const] is being called 
		cout << "\nObject 1 is bigger than object 2" << endl;
	else
		cout << "\nObject 1 is not bigger than object 2" << endl;
	
	 if(obj1.operator>(obj2))	// equivalent function call (eq. to obj1 > obj2)
		cout << "\nObject 1 is bigger than object 2" << endl;
	else
		cout << "\nObject 1 is not bigger than object 2" << endl;
	
	// If obj2[0] and obj2[1] are greater than obj1[0] and obj1[1] respectively, then the condition is true
	if(obj2 > obj1)	// Which operator is being called?
					// The > operator [bool Lab6::operator>(const Lab6 &x) const] is being called 
		cout << "\nObject 2 is bigger than object 1" << endl;
	else
		cout << "\nObject 2 is not bigger than object 1" << endl;
	
	if(obj2.operator>(obj1))	// explicit function call, equivalent to the previous
		cout << "\nObject 2 is bigger than object 1" << endl;
	else
		cout << "\nObject 2 is not bigger than object 1" << endl;
	
	cout << "------------------------------------------------------------------" << endl;
	obj1.Printvals();
	obj2.Printvals();
	
	// obj1 + obj2;	// normal expression. Which operator is being called?
					// The + operator [Lab6 operator+(const Lab6 &lhs, const Lab6 &rhs)] is being called

	obj1.operator+(obj2);	// equivalent, try it out


	obj1.Printvals();
	obj2.Printvals();
	
	// obj2 + obj1;	// normal expression. Which operator is being called?
					// The + operator [Lab6 operator+(const Lab6 &lhs, const Lab6 &rhs)] is being called
	obj2.operator+(obj1);	// equivalent, try it out
	obj1.Printvals();
	obj2.Printvals();

	cout << "------------------------------------------------------------------" << endl;
	obj1*2;		// Would 2*obj1 work? Give it a try.
	// 2*obj1;
	obj2*f;		// Would f*obj2 work? Give it a try.
	// f*obj2;
	obj1.Printvals();
	obj2.Printvals();
	
	cout << "------------------------------------------------------------------" << endl;
	// Which operator is being called next?
	// The + operator [Lab6 operator+(const Lab6 &lhs, const Lab6 &rhs)] is being called
	obj3 = operator+(obj1, obj2);	// Would  obj3 = obj2 + obj1; work?
									// Yes, this works

	obj1.Printvals();				// 22, 50
	obj2.Printvals();				// 210, 450
	obj3.Printvals();				// 232, 500
	
	obj3 = operator+(obj2, obj1);	// is this the same as before?
									// Yes, this results in the same values being stored in object <obj3>

	obj1.Printvals();				// 22, 50
	obj2.Printvals();				// 210, 450
	obj3.Printvals();				// 232, 500
	
	return 0;
}
