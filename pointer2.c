#include <stdio.h>


#define Size 10
 
int main()
{
	int dog[10] = {0, -1, 2, -3, 4, -5, 6, -7, 8, -9};
	int *dogpointer = &dog[0];
	//int max = dog[0];
	int max = *dogpointer;
	
	/*
	if (max > dog[1])
		printf("The max is %d \n", max);
	else
		max = dog[1];
		printf("The max is %d \n", max);
	
	*/
	
	for (int i=0; i < Size; ++i)
	{
		if (*(dogpointer+ i) > max)
			max = *(dogpointer + i);
			//printf("The max is %d \n", max);
	}
	
	
	printf("The maximum value in the array is %d \n", max);
	
	
	printf("array[0] = %d, array[1] = %d \n", dog[0], dog[1]);
	printf("dogpointer = %d \t dogpointer next entry =%d\n", *dogpointer, *(dogpointer+1));
	
	
	//or (int i=0; i<2; ++i)
	//printf

	return 0;
}
