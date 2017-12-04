/*
Assignment6.c
- Angelino Lefevers

Notes: 
- A lot of warnings when compiling
- probable errors:
	-- overflow of the global variable x
	-- two functions accessing the same variable location at the same time - corrupt memory - something funny with the cache registers
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int x = 0;
int on = 1;

void *incrementVariable( int n );
void *senseExit( void );

int main() {

	pthread_t thread1, thread2, thread3, thread4;

	pthread_create(&thread1, NULL, incrementVariable, 1);
	pthread_create(&thread2, NULL, incrementVariable, 2);
	pthread_create(&thread3, NULL, incrementVariable, 3);
	pthread_create(&thread4, NULL, senseExit, NULL);	

	while(on) {
			sleep(1);
	}
	
	return(0);
} // END FUNCTION main

void *incrementVariable( int n )
{
	while(1) {
		int u_sec = 0;

		// Random number generated
		time_t t;
		srand((unsigned) time(&t));
		u_sec = ( rand() % 500000 ) + 1000000;

		// Thead sleeps for random time
		usleep(u_sec);

		// Increment global variable
		x++;

		// Print thread and counter
		printf("Thread %d: %d\n",n , x);
		fflush(stdout);
	} // END while
} // END FUNCTION incrementVariable

void *senseExit( void )
{
	while(1) {
		char rawInput;
		scanf("%c", &rawInput);
		usleep(100000);
		if( rawInput == 'q' ) {
			on = 0;
		} 
		fflush(stdin);
	}
} // END FUNCTION senseExit
