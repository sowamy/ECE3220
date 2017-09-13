/* Name:		Angelino Lefevers 
 * SID: 		14121997
 * PawPrint: 	adl535, LefeversA
 * Class:		ECE 3220
 * Lab #:		2
 * Problem #:	1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned short getInput( unsigned short inputType );
unsigned long factorial( unsigned short value );
unsigned short leapYearChecker( unsigned short value );

int main( void )
{
    unsigned int menuChoice = 0;
    unsigned short on = 1;

    unsigned short value = 0;
	
	int value2 = 0;
	int value3 = 0;
	int max = 0;

    while( on )
    {

        menuChoice = 0;
        value = 0;

        printf( "MAIN MENU\n1.FACTORIAL\n2.LEAP YEAR\n3.MAXIMUM\n4.DIVISION\n5.EXIT\n--> " );
        menuChoice = (short)getInput( 1 );

        switch( menuChoice )
        {
        case 1: // Factorials
            printf( "\n\nFACTORIAL\n--> " );
            value = (short)getInput( 2 );
            printf( "%hu! IS %lu.\n\n", value, factorial( value ) );
            break;
        case 2: // Leap Year Checker
            printf( "\n\nLEAP YEAR CHECK\n--> " );
            value2 = getInput( 4 );
            leapYearChecker( value2 ) ? printf( "\n%hu WAS A LEAP YEAR\n\n", value2 ) : printf( "\n%hu WAS NOT A LEAP YEAR\n\n", value2 );
            break;
        case 3: // Maximum Value between two integers
            printf( "\n\nMAXIMUM VALUE\n\n1st VALUE:\n--> " );
			value2 = getInput( 4 );
			printf( "2nd VALUE:\n--> " );
			value3 = getInput( 4 );
			( value2 > value3 ) ? printf( "\n%d IS THE MAXIMUM VALUE\n\n", value2 ) : printf( "\n%d IS THE MAXIMUM VALUE\n\n", value3 );
            break;
        case 4: // Division between two integers
            printf( "\n\nDIVISION\n1st VALUE\n--> " );
			value2 = getInput( 4 );
			printf( "2nd VALUE:\n--> " );
			value3 = getInput( 3 );
			printf( "\n%d DIVIDED BY %d IS %.4f\n\n", value2, value3, (float)value2/(float)value3 );
            break;
        case 5: // Exits the program
            on = 0; // Exits the main loop which runs the program
            break;
        default: // Unintended input
            printf( "ERROR" );
            break;
        }
    }
    return 0;
}

// Used to get input from user and checking the input for validity before returning the value
unsigned short getInput( unsigned short inputType )
{
    int rawInput = 0;
    bool invalidInputFlag = true;	// when this flag is true, this function will continue to ask user for input
					// Note: only returns values when this flag is false - verified value

    while( invalidInputFlag == true )
    {
		invalidInputFlag = false;

        scanf( "%d", &rawInput );

        if( rawInput < 0 )
        {
        	invalidInputFlag = true;
            printf( "ERROR: INVALID INPUT. TRY AGAIN\n--> " );
        }

        switch( inputType ) {
           	case 1: // Main Menu
           		if( rawInput > 5 ) {
           			invalidInputFlag = true;
           			printf( "ERROR: THERE ARE NO MENU ITEMS REPRESENTED BY THIS VALUE. TRY AGAIN\n-->");
           		}
           		break;
           	case 2: // Factorial Checker
           		if( rawInput > 12 ) {
           			printf( "WARNING: ANY INTEGER GREATER THAN 12 WILL PRODUCE INVALID RESULTS\n" );
				}
				break;
			case 3: // Division by 0 Checker
				if( rawInput == 0 ) {
					invalidInputFlag = true;					
					printf( "ERROR: CANNOT DIVIDE BY 0\nTRY AGAIN\n--> " );
           		}
				break;
			case 4: // No Extra Checks
				break;
			default:
				invalidInputFlag = true;
				printf( "ERROR: IDK WHAT YOU DID, BUT IT AIN'T RIGHT.....YOU BIG BULLY!!!!" );
		}
	}
    return rawInput;
}

// Used to calculate the factorial of value
unsigned long factorial( unsigned short value )
{
    int i = value;
    unsigned long sum = 1;
    while( i != 0 )
    {
        sum *= i;
        i -= 1;
    }
    return sum;
}

// Used to check if a given year is a leap year
// Returns 1 if the year is a leap year
// Returns 0 if the year is not a leap year
unsigned short leapYearChecker( unsigned short value )
{
    if( value % 4 ) {
        return 0;
    } else {
        return 1;
    }
}
