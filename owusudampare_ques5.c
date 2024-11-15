#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//#define SIZE 30

int main()
{
	int arraysize;

	printf("\nEnter the size of the numbers: ");
	scanf("%d", &arraysize);

    	if (arraysize <= 0) 
    	{
        	printf("Invalid array size. It must be a positive integer.\n");
        	return -1;
    	}
	
	
	int number[arraysize];
	int numbmod[arraysize]; 
	int a = 0;
	int b = 0;
	double avg = -5.0;
	double sum = 0.0;
	double sdsum = 0.0;
	int counter = 0;
	int freq = 0;
	int multiplefreq = 0;
	int freqnum = -9999999;
	

	FILE* in_file = fopen("data.txt", "r"); //only open a pre-exisiting file in read mode. 
         
	if (! in_file ) // equivalent to saying if ( in_file == NULL )
	{
		printf("oops, file can't be read\n"); 
                exit(-1); 
        }
                
                
          // attempt to read the next line and store 
          // the value in the "number" variable 
	while ( fscanf(in_file, "%d", & number[b] ) == 1 ) 
	{ 
		b++;
	}
	
	for (int q = 0; q < arraysize; ++q) //looping through the array of numbers
        {
		
		sum += number[q];  // Find the sum of all the numbers in the array/file read
		counter = 1;	   //Resetting the counter to check the frequencies of each number in the area	
		
		if (freqnum != number[q])	// skips if the number in the array has already been 
						//encountered previously and the frequency has been found
		{
			
			for (int r = 0; r < arraysize; ++r) //looping through the array of numbers again
			{
				if (r != q)
				{
					if (number[r] == number[q]) //Checks if the numbers are the same
					counter = counter + 1;
				}		//increases its count or frequency
				
			if (freq < counter)	//If the counter is greater than the set frequency
			{
				freq = counter;
				freqnum = number[q];
				multiplefreq = 1;
				numbmod[0] = number[q];		//Assumes every number is a multiple node and initiates the array
			}
			else if (freq == counter) //If the counter and the set frequency are the same; hence multiple modes
			{
				int y = 0;
				for (int z = 0; z < multiplefreq; ++z) //Checks if the number is already stored in the 
									//multiple modes array so it doesn't store it again
				{
					if (numbmod[z] == number[q])
					{
						y = 1;
						break;
					}
				}
				
				if (!y)  //Stores the number (different mode) if it is not already stored
				{
					numbmod[multiplefreq] = number[q];
					++multiplefreq;		
				}
				
			}
			
			}	
		}
	}
	
	
	
	avg = sum/arraysize;
	
	for (int s = 0; s < arraysize; ++s)
		sdsum += pow(fabs(number[s] - avg), 2);
	
	sdsum = sqrt(sdsum/arraysize);
	
	
		
		
     	printf("\nThe summary statistics of the grades:\n");
	
	for (int t = 0; t < arraysize; ++t)
	{
        	printf("Grade %d: %d\n", t+1, number[t]);
        }
        
        
        
        printf("\n1. Average: %.3lf \n", avg);
        
        if (multiplefreq > 0)
        {
        	for (int n = 0; n < multiplefreq; ++n)
        	{
        		printf("2. Mode %d: %d\n", n+1, numbmod[n]);
        	}
        }
        else
        {
        	printf("2. Mode: %d \n", freqnum);
        }
        
	printf("3. Standard deviation: %.3lf \n", sdsum);
	
	return 0;
}
	
