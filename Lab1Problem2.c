#include <stdio.h>

int main( void )
{
	float originalPrice = 0;	// Keeps the price the product was purchased for
	float sellingPrice = 0;		// Keeps the price the product sold for

	// Prompt to get the price the product was brought for
	// Assigns price to originalPrice
	printf( "Enter the original price the product was brought for: \n--> " );
	scanf( "%f", &originalPrice );

	// TODO negative values

	// Prompt to get the price the product sold for
	// Assigns value to sellingPrice
	printf( "\n\nEnter the price that the product was sold for: \n--> " );
	scanf( "%f", &sellingPrice );

	if( originalPrice < sellingPrice ) {			// If the user made money...
		printf( "You have MADE %.2f dollars in this transaction.", sellingPrice - originalPrice );
	} else if( originalPrice > sellingPrice ) {		// If the user lost money...
		printf( "You have LOST %.2f dollars in this transaction.", originalPrice - sellingPrice );
	} else {										// If the user broke even
		printf( "You have neither LOST nor MADE money in this transaction." );
	} // END if...else if...else

	return 0;
} // END FUNCTION main
