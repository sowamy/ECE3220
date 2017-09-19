#include <stdio.h>
#include <string.h>

void tester(int* c, int k) {
	c[1000]=1309;
	printf("x[%d] = %d\n", k, c[k]);	
}

int main(int argc, char* argv[]) {
	int i = 0, j, k;
	int x[1001];
	
	while(i < 1001){
		x[i] = i;
		i++;
	}

	printf("Enter an integer between 0 to 9999: ");
	fflush(stdout);
	scanf("%d",&k);

	tester(x, k);
}
