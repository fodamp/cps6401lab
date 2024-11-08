#include<stdio.h>
#include<math.h>

#define arraysize 5


//This program calculates the average of the scores of 5 students.


int main()
{
//int n = 5;
//int max_student_size = 1000;


int stugrad[arraysize] = {10, 7, 5, 9, 10};  //array of variable length. 
double avg = -5.0;
double sum = 0.0;   //sum 41
double sdsum = 0.0;
int counter = 0;
int freq = 0;
int freqnum = -9999999;
	
	for (int i = 0; i < arraysize; ++i)
	{
		sum += stugrad[i];
		
		if (freqnum != stugrad[i])
		{
			for (int j=0; j < arraysize; ++j)
				if (j != i)
					if (stugrad[j] == stugrad[i])
					counter = counter + 1;
		
			if (freq <= counter)
				freq = counter;
				freqnum = stugrad[i];
		}
		
	} // for-loop
	
	avg = sum/arraysize;
	
	for (int i = 0; i < arraysize; ++i)
		sdsum += pow(fabs(stugrad[i] - avg), 2);
	
	sdsum = sqrt(sdsum/arraysize);
	
	printf("\nThe summary statistics of the grades: %d, %d, %d, %d, %d is\n",stugrad[0], stugrad[1], stugrad[2], stugrad[3], stugrad[4]);
	printf("1. Average: %.3lf \n", avg);
	printf("2. Mode: %d \n", freqnum);
	printf("3. Standard deviation: %.3lf \n", sdsum);
	
	
return 0;
}

