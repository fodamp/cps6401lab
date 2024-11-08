#include <stdio.h>
#define Size 10




int main()
{

	int intnumbs[] = {10, 50, -19, 8, 12, 0, 34, 25, 66, -75};
	int *intnumbspt = &intnumbs[0];
	int max = *intnumbspt; 
	
	
	printf("\nThe maximum integer in the array of numbers:");
	for (int i=0; i < Size; ++i)
	{
		printf("\n%d", *(intnumbspt + i));
		if (*(intnumbspt + i) > max)
			max = *(intnumbspt + i);
	}
	
	printf("\nis: %d\n",max);


	return 0;
}
