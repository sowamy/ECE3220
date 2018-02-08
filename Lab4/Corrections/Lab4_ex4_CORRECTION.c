#include<stdio.h>
#include<string.h>

void main()
{
    int i=0;
	// arr1 was too small to contain all of the characters from arr2
    char arr1[ 20 ] = "Trumantiger";
    char arr2[ 20 ];

    while(i<20){
        arr2[ i ] = 'A';
        ++i;
    }
    strcpy( arr1 , arr2 );
	// Add null character at the end of arr1 to show the string how far to print
    arr1[ 20 ] = '\0';
    printf("%s",arr1);
}

