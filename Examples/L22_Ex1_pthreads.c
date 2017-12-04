/* ==========================================================================
 Name:		L22_Ex1_pthreads.c
 Author:	Luis Rivera
 
 Compile using -lpthread
	Ex.: gcc L22_Ex1_pthreads.c -o L22_Ex1_pthreads -lpthread
 ========================================================================= */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

// Thread function.
void *My_Thread(void *ptr)
{
	char *message, dummy;
	message = (char *)ptr;	// retrieve what was passed
	
	while(1)
	{
		scanf("%c", &dummy);	// blocking function
		printf("\n%s\n", message);
		fflush(stdout);
	}

	pthread_exit(0);
}

int main(void)
{
	pthread_t thread1;	// thread identifier
	char *message1 = "Thread 1 here";
	int count = 0;

	printf("\n%s\n", message1);
	
	// Create the thread. How many threads will there be in this process?
	pthread_create(&thread1, NULL, My_Thread, (void*)message1);

	while(1)
	{
		sleep(1);
		printf("%d\n", count++);
		fflush(stdout);
	}

	return(0);
}
