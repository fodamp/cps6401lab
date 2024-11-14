#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/time.h>
#include <unistd.h>
#include <math.h>

/*
  void diff(double* u, int N, double dx, double* du)

  Computes a finite difference approximation for du/dx

  Inputs: 
  u: pointer for input array
  N: length of the array
  dx: the space step size
  du: pointer to output array

  Outputs: 
  du: contains the forward finite difference approximation
*/
void diff(double* u, int N, double dx, double* du) {

  int i;
  du[0] = (u[1]-u[0])/dx;
  for (i=1; i<N-1; ++i) {
    du[i] = (u[i]-u[i-1])/dx;
  }
  du[N-1] = (u[N-1]-u[N-2])/dx;
  
}

/*
  void init(double* u, int N, double dx)

  Initializes the data array with the sin function

  Inputs: 
  u: pointer to array will values will be stored
  N: length of the array
  dx: the space step size

  Outputs: 
  u: contains data for a sin function
*/
void init(double* u, int N, double dx)
{
  int i;
  for (i=0; i<N; ++i)
    u[i] = sin(i*dx);
}

/*
  int main(int argc, char* argv[])

  Function tests the timing accuracy of 4 different methods

  Inputs: argc should be 2
  argv[1] is the integer length of the data array
  
  Outputs: ???
*/
int main(int argc, char* argv[])
{
int N = atoi(argv[1]);


double* dfdx = (double*)malloc(N*sizeof(double));
double* Dfh = (double*)malloc(N*sizeof(double));
double dx = M_PI/N;

init(u, N, dx);  
for (int i=0; i<N;++i)
    printf("sin[%d] = %f  \n",i, u[i]);
diff(u, N, dx, du);
for (int i=0; i<N;++i)
    printf("diff = %f - %f = %f \n",u[i], du[i], u[i]-du[i]);
free(u);
free(du);

return 0;
}

