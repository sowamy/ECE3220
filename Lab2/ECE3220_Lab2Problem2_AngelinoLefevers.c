/* Name:		Angelino Lefevers 
 * SID: 		14121997
 * PawPrint: 	adl535, LefeversA
 * Class:		ECE 3220
 * Lab #:		2
 * Problem #:	2
*/

 #include <stdio.h>

unsigned short* arithmaticOperations( int input );
unsigned short* bitwiseOperations( int input );

 int main( void )
 {
 	int rawInput = 0;
 	char formattedOutput[ 7 ];
 	char* formattedOutputPtr = &formattedOutput[ 0 ];
 	unsigned short menuChoice = 0;
	unsigned short* binaryRepresentation;
 	short i = 0;

 	printf( "ENTER INTEGER TO CONVERT\n--> " );
 	fscanf( stdin, "%d", &rawInput );

 	printf( "\nWHICH WAY SHOULD THE PROGRAM CONVERT\n1.ARITHMATIC OPERATIONS\n2.BITWISE OPERATIONS\n--> " );
 	fscanf( stdin, "%hu", &menuChoice );

 	switch( menuChoice ) {
 		case 1:
 			binaryRepresentation = arithmaticOperations( rawInput );
 			break;
 		case 2:
 			binaryRepresentation = bitwiseOperations( rawInput );
 			break;
 		default:
 			printf( "ERROR: INVALID INPUT, RETRY PROGRAM" );
 	} // END switch

 	printf( "\nTHE BINARY REPRESENTATION OF %d IS: ", rawInput );

	for( i = 0; i < 7; i++ ) {
		printf( "%hu", *binaryRepresentation );
		binaryRepresentation++;
	} // END for

	puts( " " );

	return 0;

 }

 unsigned short* arithmaticOperations( int input )
 {
 	int currentValue = input;
	unsigned short binaryRep[ 7 ] = { 0 };
	unsigned short* binaryRepPtr = &binaryRep[ 0 ];
	unsigned short i = 7;

 	for( i = 7; i >= 0; i-- ) {
 		binaryRep[ i ] += currentValue % 2;
		currentValue /= 2;
 	}

	return binaryRepPtr;
 }

unsigned short* bitwiseOperations( int input )
{

}
