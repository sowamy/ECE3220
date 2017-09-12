/* Name:		Angelino Lefevers 
 * SID: 		14121997
 * PawPrint: 	adl535, LefeversA
 * Class:		ECE 3220
 * Lab #:		2
 * Problem #:	2
*/

 #include <stdio.h>

void arithmaticOperations( int input, char* output );
void bitwiseOperations( int input, char* output );

 int main( void )
 {
 	int rawInput = 0;
 	char formattedOutput[ 8 ];
 	char* formattedOutputPtr = &formattedOutput[ 0 ];
 	unsigned short menuChoice = 0;
 	short i = 0;

 	printf( "ENTER INTEGER TO CONVERT\n--> " );
 	fscanf( stdin, "%d", &rawInput );

 	printf( "\nWHICH WAY SHOULD THE PROGRAM CONVERT\n1.ARITHMATIC OPERATIONS\n2.BITWISE OPERATIONS\n--> " );
 	fscanf( stdin, "%hu", &menuChoice );

 	switch( menuChoice ) {
 		case 1:
 			arithmaticOperations( rawInput, formattedOutputPtr );
 			break;
 		case 2:
 			bitwiseOperations( rawInput, formattedOutputPtr );
 			break;
 		default:
 			printf( "ERROR: INVALID INPUT, RETRY PROGRAM" );
 	}

 	printf( "\nTHE BINARY REPRESENTATION OF %d IS: ", rawInput );
 	for( i = 0; i < 9; i++ ) { printf( "%c", formattedOutput[ i ] ); }

 }

 void arithmaticOperations( int input, char* output )
 {
 	int currentValue = input;
 	char* outputString = output + 8;
 	short i = 0;

 	for( i = 0; i <= 8; i++ ) {
 		*outputString = currentValue % 2;
 		outputString--;
 		currentValue /= 2 ;
 	}
 }

void bitwiseOperations( int input, char* output )
{

}
