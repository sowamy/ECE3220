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

    while( on )
    {

        menuChoice = 0;
        value = 0;

        printf( "MAIN MENU\n1.FACTORIAL\n2.LEAP YEAR\n3.MAXIMUM\n4.DIVISION\n5.EXIT\n--> " );
        menuChoice = getInput( 1 );

        switch( menuChoice )
        {
        case 1:
            printf( "\n\nFACTORIAL\n--> " );
            getInput( 2 );
            printf( "%hu! IS %lu.\n\n", value, factorial( value ) );
            break;
        case 2:
            printf( "\n\nLEAP YEAR CHECK\n--> " );
            scanf( "%hu", &value );
            leapYearChecker( value ) ? printf( "%hu WAS A LEAP YEAR\n\n", value ) : printf( "%hu WAS NOT A LEAP YEAR\n\n", value );
            break;
        case 3:
            printf( "Maximum" );
            break;
        case 4:
            printf( "Division" );
            break;
        case 5:
            on = 0;
            break;
        default:
            printf( "ERROR" );
            break;
        }
    }
    return 0;
}

unsigned short getInput( unsigned short inputType )
{
    char rawInput[ 256 ];
    int verifiedInput;
    bool invalidInputFlag = false;

    while( !invalidInputFlag )
    {
    	// Originally used gets(), but that is invalid in linux environment
        fgets( rawInput, 10, stdin );
        printf( "%s", rawInput );

        sscanf( rawInput, "%d", &verifiedInput );

        if( verifiedInput < 0 )
        {
        	invalidInputFlag = true;
            printf( "ERROR: INVALID INPUT. TRY AGAIN\n--> " );
        }

        switch( inputType ) {
           	case 1: // Main Menu
           		if( verifiedInput > 5 ) {
           			invalidInputFlag = true;
           			printf( "ERROR: THERE ARE NO MENU ITEMS REPRESENTED BY THIS VALUE. TRY AGAIN\n-->");
           		}
           		break;
           	case 2: // Factorial Checker
           		if( verifiedInput > 12 ) {
           			printf( "WARNING: ANY INTEGER GREATER THAN 12 WILL PRODUCE INVALID RESULTS\n" );
           		}
        }
	}
    return (short)verifiedInput;
}

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

unsigned short leapYearChecker( unsigned short value )
{
    if( value % 4 ) {
        return 0;
    } else {
        return 1;
    }
}
