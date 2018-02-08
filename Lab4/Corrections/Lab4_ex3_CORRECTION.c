#include <stdio.h>

int factorial ( int num )
{
	/*
	 * In the original program, the recursive function was never ending (created an infinite loop)
	 * In the corrected program, the if statements provides a means to end the program
	 */
	if( num != 1 ) {
		num *= factorial( num - 1 );
	}
    return num;
}

int main(void)
{
    int no,ans;
    printf("Enter the number \n");
    scanf( "%d", &no );
    ans = factorial( no );
    printf("The factorial is %d ", ans );
    return 0;
}

