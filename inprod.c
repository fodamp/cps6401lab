#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <math.h>
#define a_size 5


int main(int argc, char* argv[]) 
{
  clock_t start, end;
  double cpu_time_used;
  double dotproduct = 0.0;
  int rowsize = atoi(argv[1]); 
  //int colsize = atoi(argv[1]);
  int x[rowsize];
  int y[rowsize];
  
  
     
     
  start = clock();
     /* Do the work. */
     
     for (int i = 0; i< rowsize; ++i)
     {
     	x[i] = (-1)^(i);
     	y[i] = (-1)^(i+1);
     	dotproduct = dotproduct +  (x[i] * y[i]);
     }	
 
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  // print the result
  printf("The dot product of the vectors is %.3f \n", dotproduct);
  printf("This task took %f seconds to execute \n", cpu_time_used);

  return 0.;
}
