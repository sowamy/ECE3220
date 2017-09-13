#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main()
{
    signed char c = CHAR_MAX+1;
    signed char d = CHAR_MIN-1;
    printf("Too small char value: %d.\n", d);
    printf("A too large char value is %d.\n", c);

    const signed char charValue1 = 65;
    printf("\nThe character is %c.\n", charValue1);
    printf("The character is %d.\n", charValue1);

    signed char charValue2 = 97;
    printf("\nThe character is %c.\n", charValue2);
    printf("The character is %d.\n", charValue2);

    int i = 256;
    signed char k = i;
    printf("\nValue of i:%i. Value of i:%c. Value of k:%d.\n", i, k, k);
    
    i = 3.14;
    double pi = i;
    printf("\nValue of pi: %f. \n", pi);
    pi = 3.14;
    printf("Value of pi: %f. \n", pi);

    int intVar;
    char charVar;
    unsigned char uChar;

    intVar = 3;
    charVar = intVar;
    printf("\nThe int variable value is %d.\n", intVar);
    printf("The char variable value is: %d.\n", charVar);

    charVar = CHAR_MAX;
    intVar = charVar;
    printf("\nThe int variable value is %d.\n", intVar);
    printf("The char variable value is: %d.\n", charVar);

    intVar = CHAR_MAX + 1;
    charVar = intVar;
    printf("\nThe int variable value is %d.\n", intVar);
    printf("The char variable value is: %d.\n", charVar);

    intVar = 256;
    uChar = (unsigned char) intVar;
    printf("\nThe int variable value is %d.\n", intVar);
    printf("The char variable value is: %d.\n", uChar);

    unsigned u = 10, u2 = 42;
	printf("\n%u\n", u2 - u);
	printf("%u\n", u - u2);
    
	int n = 10, n2 = 42;
	printf("\n%d\n", n - n2);
	printf("%d\n", n2 - n);
	printf("%d\n", u - n);
	printf("%d\n", n - u);
	
	return 0;
}

