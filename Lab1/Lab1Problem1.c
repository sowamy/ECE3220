#include <stdio.h>
#include <math.h>

#define PI 3.141592653

float getCircleArea( float radius );

int main( void )
{
	float radius = 0;
	short positiveTest = 0;	// Flag: 1 if the radius is greater than or equal to 0: 0 otherwise.

	// Will continue to prompt user if the radius entered is not a valid value
	while( positiveTest != 1 ) {

		positiveTest = 1;

		// Prompt to user to enter radius, and assigns valued entered into float radius
		printf( "\nEnter radius of circle: \n--> " );
		scanf( "%f", &radius );

		// TODO radius check - negative
		if( radius < 0 ) {
			printf( "\nERROR: Radius must be a number greater than or equal to zero\n" );
			positiveTest = 0;
		} // END if : Negative Test

	} // END while : Positivity Test

	// Displays the area of the circle to the user, accurate to 4 decimal places
	printf( "\nThe area of the circle is: %.4f\n\n", getCircleArea(radius) );

	return 0;
} // END FUNCTION main

// Takes the radius of a circle, and returns the area of the circle
float getCircleArea( float radius ) { return PI*radius*radius; }
