#include <stdio.h>
int x = 10; 
void one(void){
	int x; 
	x = 1;
}

void two(int x){
	x = 2;
}

void three(void){
	x = 2;
}

void four(int *p){
	*p = 3;
}

int main(void){
	printf("%d\n", x);
	x = 4;
	one();
	printf("%d\n", x);
	x = 5; 
	two(x);
	printf("%d\n", x);
	x = 6;
	{
		int x = 7;
		three();
		printf("%d\n", x);
	}
	printf("%d\n", x);
	x = 8; 
	four(&x);
	printf("%d\n", x);
	return 0;
}