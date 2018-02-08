// L13_Ex1_ABC.cpp
// By Luis Rivera

// Compile using the flag  -std=c++11  or  -std=c++0x
// Example: g++ L13_Ex1_ABC.cpp -o L13_Ex1_ABC -std=c++11
//      or: g++ L13_Ex1_ABC.cpp -o L13_Ex1_ABC -std=c++0x

// Edited by: Angelino Lefevers

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

#define PI 3.14

using namespace std;

/* CLASS: BaseConic
 * DESCRIPTION: Creates an Abstract Base Class (ABC), conic; which stores basic values and functions considering conics
 */
class BaseConic {
	protected:
		double x;
		double y;

	public:
		BaseConic(double x0 = 0, double y0 = 0){x = x0; y = y0;}
		virtual ~BaseConic(){};
		void Move(double nx, double ny){x = nx; y = ny;}
		virtual double Area() = 0;
		virtual bool inside( double x_in, double y_in ) = 0;
		virtual void display() = 0;
}; // END CLASS BaseConic

/* CLASS: Ellipse
 * PARENT: BaseConic
 * DESCRIPTION: Describes an Ellipse, derived from the (ABC) BaseConic
 */
class Ellipse : public BaseConic {
	private:
		double a; 		// semi-major axis
		double b; 		// semi-minor axis
		double angle; 	// orientation angle

	public:
		Ellipse(double x0, double y0, double a0, double b0, double an0);
		virtual ~Ellipse(){};
		virtual double Area() {return 3.1416*a*b;}
		void Rotate(double nang){angle += nang;}
		virtual bool inside( double x_in, double y_in );
		virtual void display();
}; // END CLASS Ellipse

/* CLASS: Ellipse
 * PARENT: BaseConic
 * METHOD: Ellipse
 * DESCRIPTION: Default Constructor, sets all measurements to 0 be default
 */
Ellipse::Ellipse(double x0=0,double y0=0,double a0=0,double b0=0,double an0=0) : BaseConic(x0,y0) {
	a = a0;
	b = b0;
	angle = an0;
} // END CONSTRUCTOR Ellipse

/* CLASS: Ellipse
 * PARENT: BaseConic
 * METHOD: inside
 * DESCRIPTION: Returns true if the given point is inside of the ellipse
 */
bool Ellipse::inside( double x_in, double y_in ) {
	double p1 = pow( ( ( cos(angle*PI/180.0)*(x_in-x)+sin(angle*PI/180.0)*(y_in-y) ) / a ), 2 );
	double p2 = pow( ( ( sin(angle*PI/180.0)*(x_in-x)+cos(angle*PI/180.0)*(y_in-y) ) / b ), 2 );
	double ell = p1 + p2;
	if( ell < 1 ) {
		return true;
	} else {
 		return false;
	} // END if...else

} // END METHOD inside

/* CLASS: Ellipse
 * PARENT: BaseConic
 * METHOD: display
 * DESCRIPTION: Displays the size, position, angle, and area of an ellipse.
 */
void Ellipse::display() {
	cout << "x = " << x << ", y = " << y << ", a = " << a << ", b = " << b
		 << ", angle = " << angle << ", Area = " << this->Area() << endl;
} // END METHOD display

/* CLASS: Circle
 * PARENT: BaseConic
 * DESCRIPTION: Describes a circle, derived from (ABC) BaseConic
 */
class Circle : public BaseConic {
	private:
		double r; 	// radius

	public:
		virtual double Area() {return 3.1416*r*r;}
		Circle(double x0=0,double y0=0,double r0=0) : BaseConic(x0,y0){r = r0;}
		virtual ~Circle(){};
		virtual bool inside( double x_in, double y_in );
		virtual void display();
}; // END CLASS Circle

/* CLASS: Circle
 * PARENT: BaseConic
 * DESCRIPTION: Returns 1(true) if the given coordinate is inside the circle; otherwise, returns 0(false)
 */
bool Circle::inside( double x_in, double y_in ) {
	x_in -= x;
	y_in -= y;

	double distance = sqrt( x_in*x_in + y_in*y_in );

	if( distance < r ) {
		return true;
	} else {
		return false;
	} // END if...else

} // END METHOD inside

/* CLASS: Circle
 * PARENT: BaseConic
 * METHOD: display
 * DESCRIPTION: Displays the size, position, and area of a circle
 */
void Circle::display() {
	cout << "\nx = " << x << ", y = " << y << ", r = " << r
		 << ", Area = " << this->Area() << endl;
} // END METHOD display

/* FUNCTION: main
 * DESCRIPTION: Uses all classes and functions together and uses them
 */
int main(){
	bool on = true;	// Turns program on (true) and off (false)
	bool error; 	// Flag: Signals if user interface is incorrect
	int menu;		// Holds user menu choice
	double x_pos;	// X Position of conic
	double y_pos;	// Y Position of conic
	double a;
	double b;
	double radius;	// Radius of Circle
	double angle;
	string raw;		// Raw input from user
	BaseConic *obj;
	istringstream iss;

	// Create Object Menu
	cout << "\nSelect Type of Object to Create: " << endl;
	cout << "1. Circle" << endl;
	cout << "2. Ellipse" << endl;
	cout << "--> ";

	// Get and convert user choice
	getline( cin, raw );
	menu = atoi( raw.c_str() );

	if( menu == 1 ) {

		// Get x and y position from user
		cout << "\nEnter Initial Position; x y: ";
		getline( cin, raw );

		iss.str( raw );
		iss >> x_pos;
		iss >> y_pos;

		cout << "\nEnter Radius: ";
		getline( cin, raw );
		radius = atof( raw.c_str() );

		// TEST: Print x and y positions
		// cout << "x: " << x_pos << "\ty: " << y_pos << "\tr: " << radius << endl;

		obj = new Circle( x_pos, y_pos, radius );
	} else if( menu == 2 ) {
		cout << "\nEnter Initial Position; x y: ";
		getline( cin, raw );

		iss.str( raw );
		iss >> x_pos;
		iss >> y_pos;

		cout << "\nEnter Values; a b: ";

		getline( cin, raw );

		iss.str( raw.c_str() );
		iss >> a;
		iss >> b;

		cout << "\nEnter Angle: ";

		getline( cin, raw );
		angle = atof( raw.c_str() );

		obj = new Ellipse( x_pos, y_pos, a, b, angle );
	} else {

	} // END if...else if...else : Gets type of object to create

	while( on ) {

		// Print main menu
		cout << "\nMain Menu: " << endl;
		cout << "1. Conic Information" << endl;
		cout << "2. Move Conic" << endl;
		cout << "3. Inside" << endl;
		cout << "9. EXIT" << endl;
		cout << "--> ";

		// Get and convert user choice
		getline( cin, raw );
		menu = atoi( raw.c_str() );

		// Menu selection structure
		switch( menu ) {
			case 1:	// Conic Infomation
				obj->display();
				break;
			case 2: // Move Conic
				// cout << "\nEnter New Position; x y: ";
				// getline( cin, raw );
				//
				// iss.str( raw );
				// iss >> x_pos;
				// iss >> y_pos;

				cout << "\nEnter New X Position: ";
				cin >> x_pos;
				cin.ignore();

				cout << "Enter New Y Position: ";
				cin >> y_pos;

				cin.ignore();

				// TEST: Prints x and y positions
				// cout << "\nx: " << x_pos << "y: " << y_pos;

				obj->Move( x_pos, y_pos );
				break;
			case 3: // Inside
				// cout << "\nEnter Coordinates; x y: ";
				// getline( cin, raw );
				//
				// iss.str( raw );
				// iss >> x_pos;
				// iss >> y_pos;

				cout << "\nEnter X Coordinate: ";
				cin >> x_pos;

				cin.ignore();

				cout << "Enter Y Coordinate: ";
				cin >> y_pos;

				cin.ignore();

				cout << '(' << x_pos << ", " << y_pos << ") is ";

				if( obj->inside( x_pos, y_pos ) ) {
					cout << "inside the conic" << endl;
				} else {
					cout << "outside the conic" << endl;
				} // END if...else

				break;
			case 9: // Exit Program
				on = false;
				break;
			default:
				break;
		} // END SWITCH : Main Menu Selection
	} // END WHILE: Program on
} // END FUNCTION main
