#include <stdio.h>

int main( void )
{

	float operand1 = 0;
	float operand2 = 0;
	char operator;
	int operatorCode = 0;		// Will determine the operation in the switch statement
	int operatorValid = 0;	// Will determine if the operator entered is valid
	int operand2Valid = 0;	// Makes sure that the user doesn't divide by 0

	// Prompt to get first operand
	printf( "Enter 1st Operand: " );
	scanf( "%f", &operand1 );

	// Prompt to get operator
	// ERROR: Acts funny when entering multiple invalid inputs for the operator
	// ERROR: if 43, 45, 42, or 47 is entered for the operand, it will be interpreted as either +, -, *, or / respectively
	while( operatorValid != 1 ) {	// Will continue as long as the operand entered is invalid
		operatorValid = 1;
		printf( "Enter Operator: " );	// Prompt to get second operand
		getchar();
		operator = getchar();
		switch( (int)operator ) {
		case 43: // addition
			operatorCode = 1;
			break;
			break;
		case 45: // subtraction
			operatorCode = 2;
			break;
		case 42: // division
			operatorCode = 3;
			break;
		case 47: // multiplication
			operatorCode = 4;
			break;
		default:
			operatorValid = 0;
			printf( "ERROR: INVALID OPERATOR\n" );
			break;
		};
	} // END while

	while( operand2Valid != 1 ) {	// Will continue as long as the user does not try and divide by zero

		operand2Valid = 1;

		// Prompt to get second operand
		printf( "Enter 2nd Operand: " );
		scanf( "%f", &operand2 );

		if( operatorCode == 4 && operand2 == 0 ){
			operand2Valid = 0;
			printf( "\nERROR: CANNOT DIVIDE BY ZERO, ENTER ANOTHER VALUE BESIDES ZERO\n\n" );
		} // END if
	} // END while


	// Does the calculation and prints result
	switch( operatorCode ){
	case 1:
		printf( "%.2f + %.2f = %.2f", operand1, operand2, operand1+operand2 );
		break;
	case 2:
		printf( "%.2f - %.2f = %.2f", operand1, operand2, operand1-operand2 );
		break;
	case 3:
		printf( "%.2f * %.2f = %.2f", operand1, operand2, operand1*operand2 );
		break;
	case 4:
		printf( "%.2f / %.2f = %.2f", operand1, operand2, operand1/operand2 );
		break;
	default:
		printf( "ERROR" );
		break;
	}; // END switch

	return 0;

} // END FUNCTION main
