/*
Notes:
- This program will assume that any negative values entered in place of a price will be invalid.
- It will assume that one will not pay one to take a valuable item, and that one will not pay another to take such an object.
*/

#include <stdio.h>

int main( void )
{
	float originalPrice = 0;	// Keeps the price the product was purchased for
	float sellingPrice = 0;		// Keeps the price the product sold for
	short negativeFlag = 1;		// Flag : 1 - Negative Values : 0 - Positive Values

	// Price may not be a negative value
	while( negativeFlag != 0 ) {

		negativeFlag = 0;

		// Prompt to get the price the product was brought for
		// Assigns price to originalPrice
		printf( "Enter the original price the product was brought for: \n--> " );
		scanf( "%f", &originalPrice );

		// Tests if original price is negative.
		if( originalPrice < 0 ) {
			negativeFlag = 1;
			printf( "\nERROR: The price must be positive\n" );
		} // END if : Original Price Negative Test
	
	} // END while : Original Price Negative

	// TODO negative values
	negativeFlag = 1;

	while( negativeFlag != 0 ) {

		negativeFlag = 0;

		// Prompt to get the price the product sold for
		// Assigns value to sellingPrice
		printf( "\n\nEnter the price that the product was sold for: \n--> " );
		scanf( "%f", &sellingPrice );

		// Tests if selling price is negative
		if( sellingPrice < 0 ) {
			negativeFlag = 1;
			printf( "\nERROR: The price must be positive\n" );
		} // END if : Selling Price Negative Test

	} // END while : Selling Price Negative

	if( originalPrice < sellingPrice ) {			// If the user made money...
		printf( "You have MADE %.2f dollars in this transaction.", sellingPrice - originalPrice );
	} else if( originalPrice > sellingPrice ) {		// If the user lost money...
		printf( "You have LOST %.2f dollars in this transaction.", originalPrice - sellingPrice );
	} else {										// If the user broke even
		printf( "You have neither LOST nor MADE money in this transaction." );
	} // END if...else if...else

	return 0;
} // END FUNCTION main
