/* ==========================================================================
 Name:			L22_Ex2_pthreads.c
 Author:		Alina Zare
 Modified by:	Luis Rivera
 
 Compile using -lpthread and -std=c11  (var declaration inside for)
	Ex.: gcc L22_Ex2_pthreads.c -o L22_Ex2_pthreads -lpthread -std=c11
 ========================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *print_message_function(void *ptr);

// You can pass structures (pointers) to the threads.
typedef struct{
    char * message;
    int waitTime;
} threadArgs;

int main()
{
	pthread_t thread1, thread2;	// thread identifiers

	threadArgs args1;
	args1.message = "Thread 1:";
	args1.waitTime = 1;

	threadArgs args2;
	args2.message = "Thread 2:";
	args2.waitTime = 2;

	// Create different threads, each of which will execute function
	pthread_create(&thread1, NULL, print_message_function, (void*) &args1);
	pthread_create(&thread2, NULL, print_message_function, (void*) &args2);

	pthread_join(thread1, NULL);	// wait until thread 1 finishes
	pthread_join(thread2, NULL);	// wait until thread 2 finishes

	printf("Thread 1 Done\n");
	printf("Thread 2 Done\n");

	return(0);
}

// Thread function. You can have different ones, to be executed by different threads.
void *print_message_function(void *ptr)
{
	threadArgs* args = (threadArgs*)ptr;	// retrieve what was passed

	for(int i = 0; i < 5; i++)
	{
		sleep(args->waitTime);
		printf("%s %d\n", args->message, i);
		fflush(stdout);
	}

	pthread_exit(0);
}
