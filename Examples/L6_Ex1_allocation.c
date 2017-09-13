#include <stdio.h>

int x = 0;			// Global Variable

int f(void){
	int x = 10;		// Local variable x
	x = x + 10;
	return x;
}

int g(void){
	static int x = 10;	// Binds x to global variable x
	x = x + 10;		// Adds 10 to global variable x
	return x;
}

double h(double y){
	y += (double)(++x);	// Adds input y to global variable x (preincremented by 1)
	return y;
}

int main(void){
	printf("%04d \n", f());		// Output: 0020
   	printf("%04d \n", g());		// Output: 0020
	printf("%.2f \n", h(2.5));	// Output: 3.50
	printf("%04d \n", f());		// Output: 0020
	printf("%04d \n", g());		// Output: 0030
	printf("%.2f \n", h(2.5));	// Output: 4.50
	return 0;
}
