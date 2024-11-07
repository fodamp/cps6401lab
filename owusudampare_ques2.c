#include<stdio.h>


//This program calculates the average of the scores of 5 students.


int main(){
	//int n = 5;
	//int max_student_size = 1000;
	int x[5];//array of variable length. 
	//x[1]= x[2]= wrong because 
	// indexing begins at 0. x[0] and x[1].
	double avg=-5.0;
	x[0]= 10;
	x[1]= 7;
	x[2]= 5;
	x[3]= 9;
	x[4]= 10;
	double sum = 0.0;//sum 41
	for (int i = 0 ;i < 5; ++i)
		{
		sum +=x[i];
		printf("for i = %d, sum = %lf \n ", i, sum );
			//more for checking if the right sum is being 
			//computed.
		} // for-loop
	avg = sum/5;
	printf("the average score is: %lf \n", avg);
}
