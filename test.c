#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 30


int main()
{

	int numbers[SIZE];
	int numbmod[SIZE/2]; 
	int a=0;
	int b = 0;
	double avg = -5.0;
	double sum = 0.0;
	double sdsum = 0.0;
	int counter = 0;
	int freq = 0;
	int multiplefreq =0;
	int freqnum = -9999999;

	FILE* in_file = fopen("data_scores.txt", "r"); //only open a pre-exisiting file in read mode. 
         
	if (! in_file ) // equivalent to saying if ( in_file == NULL )
	{
		printf("oops, file can't be read\n"); 
                exit(-1); 
        }
                
                
          // attempt to read the next line and store 
          // the value in the "number" variable 
	while ( fscanf(in_file, "%d", & numbers[b] ) == 1 ) 
	{ 
		++b;
	}
	
	for (int t = 0; t < SIZE; ++t)
	{
        	printf("Grade %d: %d\n", t+1, numbers[t]);
        }
        return 0;
}
