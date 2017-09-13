/* L1_Ex1_demo.c
Created by: Luis Rivera
*/

#include <stdio.h>
#include <math.h>

#define MAX_ITER 15

int main()
{
	int i, n, a = 1;
	printf("\nEnter n: ");
	fflush(stdout);
	scanf("%d", &n);
	printf("\n");
	
	for(i = 1; i <= MAX_ITER; i++) {
		a *= n;
		printf("%d\n", a);
	}
	
	printf("\n");
	for(i = 1; i <= MAX_ITER; i++) {
		printf("%ld\n", (long)pow((double)n,(double)i));
	}
		
	return 0;
}