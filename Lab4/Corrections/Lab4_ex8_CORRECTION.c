#include<stdio.h>
#include<string.h>
#include<malloc.h>

int main(void)
{
	// Variable <s> must be initialized with a static length
	// How does program know how long to make s?
	char s[ 20 ] = { '\0' };
	char *dyn_s;
	int ln;

	printf("Enter the input string\n");
	scanf("%s",&s[ 0 ]);

	ln = strlen(s);
	dyn_s = (char*)malloc(strlen((char*)&s[0])+1);
	dyn_s = s;
	dyn_s[strlen(s)]='\0';

	printf( "%s\n", dyn_s);

	return 0;
}

