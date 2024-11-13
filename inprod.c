#include <stdio.h>
#include <time.h>
#define a_size 5


int main(int argc, char* argv[]) 
{
  clock_t start, end;
  double cpu_time_used;
  double x[a_size] = {1., 2., 3., 4., 5.};
  double y[a_size] = {1., -1., 1., -1., 1.};
  double dotproduct = 0.0;
     
     
  start = clock();
     /* Do the work. */
     for (int i = 0; i< a_size; i++)
     	dotproduct += x[i] * y[i];
 
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  // print the result
  printf("The dot product of the vectors is %.3f \n", dotproduct);
  printf("This task took %f seconds to execute \n", cpu_time_used);

  return 0.;
}
