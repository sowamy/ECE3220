/*
 ============================================================================
 Name        : main.c
 Author      : Angelino Lefevers
 Version     : 1.0
 Class		 : ECE 3220
 Lab #		 : 5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Holds signal information
 struct dataNode{
 	int fileNumber; 	// Number of the text file to be accessed
 	int length;			// Length of the signal
 	double offset;		// Quantity to be added to each signal sample
 	double scale;		// Quantity to be multiplied with each signal sample
 	double magnitude;	// Maximum magnitude of the signal
	double average;		// Average of the data
 	double *data; 		// Points to the first address in data array
 }; // END STRUCT dataNode

 // Function Prototypes
void loadData( struct dataNode *dataNodePtr );
void scaleData( struct dataNode *dataNodePtr );
void offsetData( struct dataNode *dataNodePtr );
void printData( struct dataNode dataNodePtr );
void renameFile( struct dataNode *dataNodePtr ,char *fileName );
void getMax( struct dataNode *dataNodePtr );
void average( struct dataNode *dataNodePtr );
void getStatistics( struct dataNode *dataNodePtr );
void centerSignal( struct dataNode *dataNodePtr );
void normalizeSignal( struct dataNode *dataNodePtr );
void printHelp( void );

int main( int argc, char *argv[] )
{
	struct dataNode data;

	char *newFileName;

	// Counters
	int i = 0;

	// Flags
	bool n = false;	// File Number Flag
	bool o = false;	// Offset Value Flag
	bool s = false;	// Scale Factor Flag
	bool r = false;	// Rename Flag
	bool h = false;	// Help Flag
	bool e = false; // Error Flag
	bool a = false; // Argument Present for every option Error Flag
	bool stat = false;
	bool center = false;
	bool normal = false;

	// Test if there are any arguments present
	if( argc == 1 ) {
		e = true;
		printf( "\nERROR: There are no arguments present\n" );
	}

	// Iterates through all command line arguments, and prepares for selection structure
	for( i = 1; i < argc; i++ ) {	
	// Scans arguments for -n
		// File Number (INTEGER)
		if( ( argv[i][0] == '-' ) && ( argv[i][1] == 'n' ) && ( e == false ) ) {
			// Detects if the c.l. argument was already used
			if( n == true ) {
				e = true;
				printf( "\nERROR: Repeat argument\n" );
			} else {
				// Tests if there is no value following
				if ( argc <= (i+1) ) {
					e = true;
					printf( "\nERROR: No value -n\n" );
				// Tests if there is an argument directly following this argument
				} else if( argv[i+1][0] == '-' ) {
					e = true;
					printf( "\nERROR: Invalid value for -n\n" );
				// If the value following -n is valid:
			   	} else {
					n = true;
					data.fileNumber = atoi( &argv[i+1][0] );

					// TEST: Print -n argument
					// printf( "%d\n", data.fileNumber );

				} // END if...else if...else
			}	// END if...else

		// Scans arguments for -o
		// Offset Value (DOUBLE)
		} else if( ( argv[i][0] == '-' ) && ( argv[i][1] == 'o' ) && ( e == false ) ) {
			// Detects if the c.l. argument was already used
			if( o == true ) {
				e = true;
				printf( "\nERROR: Repeat argument\n" );
			} else {
				// Tests if there is no value following
				if ( argc <= (i+1) ) {
					e = true;
					printf( "\nERROR: No value -o\n" );
				// Tests if there is an argument directly following this argument
				} else if( argv[i+1][0] == '-' ) {
					e = true;
					printf( "\nERROR: Invalid value for -o\n" );
				// If the value following -o is valid:
			   	} else {
					o = true;
					data.offset = atof( &argv[i+1][0] );
					// TEST: Print -o argument
					// printf( "%f\n", data.offset );
				} // END if...else if...else
			}	// END if...else

		// Scans arguments for -s
		} else if( ( argv[i][0] == '-' ) && ( argv[i][1] == 's' ) && ( e == false ) ) {
			// Detects if the c.l. argument was already used
			if( s == true ) {
				e = true;
				printf( "ERROR" );
			} else {
				// Tests if there is no value following
				if ( argc <= (i+1) ) {
					e = true;
					printf( "\nERROR: No value -s\n" );
				// Tests if there is an argument directly following this argument
				} else if( argv[i+1][0] == '-' ) {
					e = true;
					printf( "\nERROR: Invalid value for -s\n" );
				// If the value following -s is valid:
			   	} else {
					s = true;
					data.scale = atof( &argv[i+1][0] );
					// TEST: Print -s argument
					// printf( "%f\n", data.scale );
				} // END if...else if...else
			}	// END if...else

		// Scans arguments for -r
		} else if( ( argv[i][0] == '-' ) && ( argv[i][1] == 'r' ) && ( e == false ) ) {
			// Detects if the c.l. argument was already used
			if( r == true ) {
				e = true;
				printf( "ERROR" );
			} else {
				// Tests if there is no value following
				if ( argc <= (i+1) ) {
					e = true;
					printf( "\nERROR: No value -r\n" );
				// Tests if there is an argument directly following this argument
				} else if( argv[i+1][0] == '-' ) {
					e = true;
					printf( "\nERROR: Invalid value for -r\n" );
				// If the value following -s is valid:
			   	} else {
					r = true;
					newFileName = &argv[i+1][0];
					// TEST: Print -r argument
					// printf( "%s\n", newFileName );
				} // END if...else if...else
			}	// END if...else

		// Scans arguments for -h
		} else if( ( argv[i][0] == '-' ) && ( argv[i][1] == 'h' ) && ( e == false ) ) {
			// Detects if the c.l. argument was already used
			if( h == true ) {
				e = true;
				printf( "ERROR" );
			} else {
				h = true;
			}	// END if...else

		// Scans arguments for -S
		} else if( ( argv[i][0] == '-' ) && ( argv[i][1] == 'S' ) && ( e == false ) ) {
			// Detects if the c.l. argument was already used
			if( stat == true ) {
				e = true;
				printf( "ERROR" );
			} else {
				stat = true;
			}	// END if...else

		// Scans arguments for -C
		} else if( ( argv[i][0] == '-' ) && ( argv[i][1] == 'C' ) && ( e == false ) ) {
			// Detects if the c.l. argument was already used
			if( center == true ) {
				e = true;
				printf( "ERROR" );
			} else {
				center = true;
			}	// END if...else

		// Scans arguments for -N
		} else if( ( argv[i][0] == '-' ) && ( argv[i][1] == 'N' ) && ( e == false ) ) {
			// Detects if the c.l. argument was already used
			if( normal == true ) {
				e = true;
				printf( "ERROR" );
			} else {
				normal = true;
			}	// END if...else
		//} else {
		//	printf( "ERROR: INVALID ARGUMENT" );
		}// END - selection structure
	} // END for

	if( n == true ) {
		loadData( &data );
	} // END if

	if( s == true ) {
	 	scaleData( &data );
	} // END if

	if( o == true ) {
		offsetData( &data );
	} // END if

	if( r == true ) {
		renameFile( &data, newFileName );
	} // END if

	if( h == true ) {
		printHelp();
	} // END if

	if( stat == true ) {
		getStatistics( &data );
	} // END if

	if( center == true ) {
		centerSignal( &data );
	} // END if

	if( normal == true ) {
		normalizeSignal( &data );
	} // END if
	
	if( e == true ) {
		printf( "\nTYPE -h FOR HELP\n" );
	} // END if

	// TEST: Print every data sample
	// printData( data );

	return 0;
} // END FUNCTION main

/* FUNCTION: loadData
 * DESCRIPTION: Takes in data from file described in structure, and points the
 * 				pointer <data> to the first entry of the data.
*/
void loadData( struct dataNode *dataNodePtr )
{
	// File Pointer, used to hold the file the data is stored in
	FILE *dataFile;

	int i = 0;
	int dummy;
	char line[256];
	char fileName[256];
	int dummy;

	sprintf( fileName, "%s%02d%s", "Raw_data_", dataNodePtr->fileNumber, ".txt" );

	// TEST: Prints file name before accessing file
	// printf( "\n%s\n", &fileName[0] );

	if( ( dataFile = fopen( (const char*)&fileName[0], "r" ) ) == NULL ) {
		printf( "\nERROR: File could not be opened\n" );
	} else {	
		fscanf( dataFile, "%d %lf", &dataNodePtr->length, &dataNodePtr->magnitude );
		// Gets rest of line 1 
		// fgets( line, sizeof( line ), dataFile );

		// Temporarily stores data from file - allocates memory
    
		//double dataArray[ dataNodePtr->length ];
		double *dataArray = (double *)malloc(dataNodePtr->length*sizeof(double));

		// TEST: Prints length and max magnitude of signal in text file
		printf( "\nlength: %d, magnitude: %lf\n", dataNodePtr->length, dataNodePtr->magnitude );

		// Loads each data sample into double array <dataArray>
		for( i = 0; i < ( dataNodePtr->length ); i++ ) {			

			//fgets( line, sizeof( line ), dataFile );
			//fscanf( dataFile, "%lf%s", &dataArray[ i ], &line );
			//fscanf( dataFile, "%d", &dataArray[ i ]);
			fscanf( dataFile, "%d", &dummy);
			//printf( "%d\n", dummy );
			dataArray[i] = (double)dummy;
			
			// TEST: Prints each data point
			printf( "%f\n", dataArray[ i ] );

		} // END for

		// Stores address of double array <dataArray> into structure double pointer <data>
		dataNodePtr->data = &dataArray[ 0 ];

		fclose( dataFile );
	} // END if...else
} // END FUNCTION loadData

/* FUNCTION: scaleData
 * DESCRIPTION: Multiplies each data sample in the structure by the structure variable scale
*/
void scaleData( struct dataNode *dataNodePtr )
{
	// File pointer, used to hold file data
	FILE *dataFile;

	int i = 0;	// Counter
	char fileName[256];
	double *pointer = dataNodePtr->data;

	sprintf( fileName, "%s%02d%s", "Scaled_data_", dataNodePtr->fileNumber, ".txt" );

	if( ( dataFile = fopen( (const char*)&fileName[0], "w" ) ) == NULL ) {
			printf( "\nERROR: File could not be opened\n" );
	} else {
		fprintf( dataFile, "%d %.2lf\n", dataNodePtr->length, dataNodePtr->scale );
		for( i; i < dataNodePtr->length; i++ ) {
		
			// TEST: Prints each data sample
			// printf( "%lf\n", *pointer );

			fprintf( dataFile, "%lf\n", ( *(pointer++) * dataNodePtr->scale ) );
		} // END for
	} // END if...else

	// TEST: Prints file name before accessing file
	// printf( "%s\n", &fileName[0] );
} // END FUNCTION scaleData

/* FUNCTION: offsetData
 * DESCRIPTION: Adds <offset> to each sample in <data> in the structure
*/
void offsetData( struct dataNode *dataNodePtr )
{
	// File pointer, used to hold file data
	FILE *dataFile;

	int i = 0;	// Counter
	char fileName[256];
	double *pointer = dataNodePtr->data;

	sprintf( fileName, "%s%02d%s", "Offset_data_", dataNodePtr->fileNumber, ".txt" );

	if( ( dataFile = fopen( (const char*)&fileName[0], "w" ) ) == NULL ) {
			printf( "\nERROR: File could not be opened\n" );
	} else {
		fprintf( dataFile, "%d %.2lf\n", dataNodePtr->length, dataNodePtr->offset );
		for( i; i < dataNodePtr->length; i++ ) {
			fprintf( dataFile, "%lf\n", ( *(pointer++) + dataNodePtr->offset ) );
		} // END for
	} // END if...else

	// TEST: Prints file name before accessing file
	// printf( "%s\n", &fileName[0] );

} // END FUNCTION offsetData

/* FUNCTION: renameFile
 * DESCRIPTION: Save signal in a different file named <fileName>
 */
void renameFile( struct dataNode *dataNodePtr, char *fileName )
{
	// File pointer, used to hold file data
	FILE *dataFile;

	int i = 0;	// Counter
	double *pointer = dataNodePtr->data;

	if( ( dataFile = fopen( fileName, "w" ) ) == NULL ) {
			printf( "\nERROR: File could not be opened\n" );
	} else {
		fprintf( dataFile, "%d %.2lf\n", dataNodePtr->length, dataNodePtr->magnitude );
		for( i; i < dataNodePtr->length; i++ ) {
			fprintf( dataFile, "%lf\n", *pointer++ );
		} // END for
	} // END if...else

	// TEST: Prints file name before accessing file
	// printf( "%s\n", &fileName[0] );

} // END FUNCTION renameFile

/* FUNCTION: printData
 * DESCRIPTION: Prints each sample in the signal
*/
void printData( struct dataNode dataNodePtr )
{
	int i = 0;	// Counter
	double *pointer = dataNodePtr.data;

	printf( "Sample: \n" );

	for( i; i < ( dataNodePtr.length ); i++ ) {
		printf( "%lf\n", *pointer++ );
	} // END for
} // END FUNCTION printData

void getMax( struct dataNode *dataNodePtr )
{
	int i = 0;
	double *pointer = dataNodePtr->data;

	dataNodePtr->magnitude = *pointer;

	for( i; i < dataNodePtr->length; i++ ) {
		if( *pointer > dataNodePtr->magnitude ) {
			dataNodePtr->magnitude = *pointer;
		} // END if
		pointer++;
	} // END for

	// TEST: Prints max magnitude
	// printf( "\nMax Magnitude: %lf\n", dataNodePtr->magnitude );
} // END FUNCTION getMax

void average( struct dataNode *dataNodePtr )
{
	int i = 0;
	double *pointer = dataNodePtr->data;
	double sum = 0;

	for( i; i < ( dataNodePtr->length ); i++ ) {
		sum += *pointer++;
	} // END for

	dataNodePtr->average =  sum / dataNodePtr->length;
} // END FUNCTION average

void getStatistics( struct dataNode *dataNodePtr )
{
	// File pointer, used to hold file data
	FILE *dataFile;

	int i = 0;	// Counter
	char fileName[256];
	double *pointer = dataNodePtr->data;
	average( dataNodePtr );

	sprintf( fileName, "%s%02d%s", "Statistics_data_", dataNodePtr->fileNumber, ".txt" );

	if( ( dataFile = fopen( (const char*)&fileName[0], "w" ) ) == NULL ) {
			printf( "\nERROR: File could not be opened\n" );
	} else {
		fprintf( dataFile, "Average MaxMagnitude\n" );
		fprintf( dataFile, "%lf %lf", dataNodePtr->average, dataNodePtr->magnitude );
	} // END if...else

	// TEST: Prints file name before accessing file
	// printf( "%s\n", &fileName[0] );

} // END FUNCTION getStatistics

void centerSignal( struct dataNode *dataNodePtr )
{
	// File pointer, used to hold file data
	FILE *dataFile;

	int i = 0;	// Counter
	char fileName[256];
	double *pointer = dataNodePtr->data;
	average( dataNodePtr );

	sprintf( fileName, "%s%02d%s", "Centered_data_", dataNodePtr->fileNumber, ".txt" );

	if( ( dataFile = fopen( (const char*)&fileName[0], "w" ) ) == NULL ) {
			printf( "\nERROR: File could not be opened\n" );
	} else {
		fprintf( dataFile, "%d %.2lf\n", dataNodePtr->length, dataNodePtr->average );
		for( i; i < dataNodePtr->length; i++ ) {
			fprintf( dataFile, "%lf\n", ( *pointer++ - dataNodePtr->average ) );
		} // END for
	} // END if...else

	// TEST: Prints file name before accessing file
	// printf( "%s\n", &fileName[0] );

} // END FUNCTION centerSignal

void normalizeSignal( struct dataNode *dataNodePtr )
{
	// File pointer, used to hold file data
	FILE *dataFile;

	int i = 0;	// Counter
	char fileName[256];
	double *pointer = dataNodePtr->data;
	// Sets maximum magnitude of signal
	getMax( dataNodePtr );

	sprintf( fileName, "%s%02d%s", "Normalized_data_", dataNodePtr->fileNumber, ".txt" );

	if( ( dataFile = fopen( (const char*)&fileName[0], "w" ) ) == NULL ) {
			printf( "\nERROR: File could not be opened\n" );
	} else {
		for( i; i < dataNodePtr->length; i++ ) {
			fprintf( dataFile, "%lf\n", ( *pointer++ / dataNodePtr->magnitude ) );
		} // END for
	} // END if...else

	// TEST: Prints file name before accessing file
	// printf( "%s\n", &fileName[0] );

} // END FUNCTION normalizeSignal

void printHelp( void )
{
	puts( "Signal Program Help" );
	puts( "--------------------------------------------------------------------------------" );
	puts( "This program operates on a signal which is imported via text files." );
	puts( "\nTo use this program effectively, the user must append the desired function" );
	puts( "as a command line argment when calling the executable." );
	puts( "\nThe following arguments are availiable for use by the user:" );
	puts( "-n := Represents the file number to be opened." );
	puts( "-o := Represents the quantity upon which to offset the signal." );
	puts( "-s := Represents the quantity upon which to scale the signal." );
	puts( "-r := Saves the signal in another file with the name given after this argument." );
	puts( "-h := Brings up this help menu you are currently seeing." );
	puts( "\nThe following operations are availiable for use by the user:" );
	puts( "-S := Get the statistics of the signal." );
	puts( "-C := Centers the signal." );
	puts( "-N := Normalizes the signal." );
} // END FUNCTION printHelp;
