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
 	unsigned short menuChoice = 0;
	unsigned short* binaryRepresentation;
 	short i = 0;

 	printf( "ENTER INTEGER TO CONVERT\n--> " );
 	scanf( "%d", &rawInput );

 	printf( "\nWHICH WAY SHOULD THE PROGRAM CONVERT\n1.ARITHMATIC OPERATIONS\n2.BITWISE OPERATIONS\n--> " );
 	scanf( "%hu", &menuChoice );

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

	for( i = 0; i < 8; i++ ) {
		printf( "%0hu", *binaryRepresentation );
		binaryRepresentation++;
	} // END for

	puts( " " );

	return 0;

 }

 unsigned short* arithmaticOperations( int input )
 {
 	int currentValue = input;
	unsigned short binaryRepRaw[ 8 ] = { 0 };
	unsigned short binaryRep[ 8 ] = { 0 };
	unsigned short* binaryRepPtr;
	unsigned short temp = 0;
	int i = 0;
	int j = 7;

 	for( i = 0; i <= 8; i++ ) {
 		binaryRepRaw[ i ] = currentValue % 2;
		currentValue /= 2;
 	} // END for

 	for( i = 0; i <= 8; i++ ) {
 		binaryRep[ i ] = binaryRepRaw[ j ];
 		j--;
 	}

 	binaryRepPtr = &binaryRep[ 0 ];

	return binaryRepPtr;
 }

unsigned short* bitwiseOperations( int input )
{
	unsigned short bitMasker = 128; 	// binary := 1000 0000
	unsigned short binaryValue[ 8 ] = { 0 };
	unsigned short* binaryValuePtr;
	unsigned short i = 0;				// counter

	for( i = 0; i < 8; i++ ) {

		if( ( input & bitMasker ) == 0 ) {
			binaryValue[ i ] = 0;
		} else {
			binaryValue[ i ] = 1;
		}

		bitMasker = bitMasker >> 1;
	} // END for

	binaryValuePtr = &binaryValue[ 0 ];

	return binaryValuePtr;
}

