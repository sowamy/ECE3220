#include<stdio.h>

int main()
{
	int x=1309;
	// NULL does not have an address, pointer p must point at something
	int *p = &x;

	printf("\n The value of x is = %d",x);
	printf("\n The pointer points to the value = %d",*p);

	return 1;
}

