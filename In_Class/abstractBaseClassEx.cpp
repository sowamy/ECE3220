#include <iostream>

#define PI 3.14

using namespace std;

class BaseConic {
	private:
		double x;
		double y;

	public:
		BaseConic( double x0 = 0, double y0 = 0 ) {};
		virtual ~BaseConic(){};
		void Move( double nx, double ny ) { x = nx; y = ny; }
		virtual double Area() = 0;
		double get_xPosition() { return x; }
		double get_yPosition() { return y; }
};

class Ellipse : public BaseConic {
	private:
		double a;
		double b;
		double area;

	public:
		Ellipse();
		Ellipse( double ain, double bin );
		Ellipse( double xin, double yin, double ain, double bin );
		~Ellipse() {};
		double Area() { area = PI * a * b; return area; }
};

Ellipse::Ellipse() : BaseConic() {
	Move( 0, 0 );
	a = 0;
	b = 0;
	area = 0;
}

Ellipse::Ellipse( double ain, double bin ) {
	Move( 0, 0 );
	a = ain;
	b = bin;
	Area();
}

Ellipse::Ellipse( double xin, double yin, double ain, double bin ) {
	Move( xin, yin );
	a = ain;
	b = bin;
	Area();
}

class Circle : public BaseConic {
	private:
		double radius;
		double area;

	public:
		Circle();
		Circle( double r );
		~Circle() {};
		double Area() { area = PI*radius*radius; return area; }
};

Circle::Circle() {
	radius = 0;
}

Circle::Circle( double r ) {
	radius = r;
}

int main( void ) {
	Ellipse ellie( 2, 3 );
	cout << ellie.Area() << endl;
	// ellie.Move( 1, 2 );
	cout << "Position: " << ellie.get_xPosition() << ", " << ellie.get_yPosition() << endl;
	ellie.Move( 1, 2 );
	Circle cellie( 3 );
	cout << cellie.Area() << endl;
	return 0;
}