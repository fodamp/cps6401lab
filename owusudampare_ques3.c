#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 20


int main()
{

	int number[SIZE]; 
	int i=0;
	double avg = -5.0;
	double sum = 0.0;
	double sdsum = 0.0;
	int counter = 0;
	int freq = 0;
	int freqnum = -9999999;

	FILE* in_file = fopen("scores-data.txt", "r"); //only open a pre-exisiting file in read mode. 
         
	if (! in_file ) // equivalent to saying if ( in_file == NULL )
	{
		printf("oops, file can't be read\n"); 
                exit(-1); 
        }
                
                
          // attempt to read the next line and store 
          // the value in the "number" variable 
	while ( fscanf(in_file, "%d", & number[i] ) == 1 ) 
	{ 
		i++;
	}
		
		
        for (int q = 0; q < SIZE; ++q)
        {
		sum += number[q];
		
		if (freqnum != number[q])
		{
			for (int r = 0; r < SIZE; ++r)
			{
				if (r != q)
				{
					if (number[r] == number[q])
					counter = counter + 1;
				}
			if (freq <= counter)
			{
				freq = counter;
				freqnum = number[r];
			}
			}	
		}
	}
				
	
	avg = sum/SIZE;
	
	for (int s = 0; s < SIZE; ++s)
		sdsum += pow(fabs(number[s] - avg), 2);
	
	sdsum = sqrt(sdsum/SIZE);
	
	
	printf("\nThe summary statistics of the grades:\n");
	
	for (int t = 0; t < SIZE; ++t)
        	printf("Grade %d: %d\n", t+1, number[t]);
	
	printf("\n1. Average: %.3lf \n", avg);
	printf("2. Mode: %d \n", freqnum);
	printf("3. Standard deviation: %.3lf \n", sdsum);
	
	return 0;
}
	
