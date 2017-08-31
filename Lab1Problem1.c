#include <stdio.h>
#include <math.h>

#define PI 3.141592653

float getCircleArea( float radius );

int main( void )
{
	float radius = 0;

	// Prompt to user to enter radius, and assigns valued entered into float radius
	printf( "Enter radius of circle: \n--> " );
	scanf( "%f", &radius );

	// TODO radius check - negative

	// Displays the area of the circle to the user
	printf( "\n\nThe area of the circle is: %.4f", getCircleArea(radius) );

	return 0;
} // END FUNCTION main

// Takes the radius of a circle, and returns the area of the circle
float getCircleArea( float radius ) { return PI*radius*radius; }
