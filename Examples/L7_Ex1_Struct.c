#include <stdio.h>

int main(void) {

	struct Signal_Info{
		int numPoints;
		int maxValue;
		char *comments;
	};

	struct Signal_Info signal1_Info;

	signal1_Info.numPoints = 50;
	signal1_Info.maxValue = 255;
	signal1_Info.comments = "Comments for Signal";

	printf("The value of the numPoints member is: %d\n", signal1_Info.numPoints);
	printf("The value of the maxValue member is: %d\n", signal1_Info.maxValue);
	printf("The value of the comments member is: %s\n\n", signal1_Info.comments);

	struct Signal_Info *signalPtr = &signal1_Info;
	printf("The value of the numPoints member is: %d\n", (*signalPtr).numPoints);
	printf("The value of the maxValue member is: %d\n", signalPtr->maxValue);
	printf("The value of the comments member is: %s\n\n", signalPtr->comments);
	
	struct Signal_Info sigInfoArray[3];
	printf("The adresses of the structures:\n%p\n%p\n%p\n\n",
			sigInfoArray, sigInfoArray+1, sigInfoArray+2);

	typedef struct{
		struct Signal_Info info;
		int *dataPointer;
	}FullSignal;

	int signalArray[100] = {1, 2};

	FullSignal signal1 = {{10, 150, "Example"}, signalArray};

	printf("The value of the numPoints member in signal1: %d\n", signal1.info.numPoints);
	printf("The value of the maxValue member in signal1: %d\n", signal1.info.maxValue);
	printf("The value of the comments member in signal1: %s\n", signal1.info.comments);
	printf("The value of a few datapoints in signal1: %d, %d, %d\n",
			signal1.dataPointer[0], signal1.dataPointer[1], signal1.dataPointer[2]);
	
	return 0;
}
