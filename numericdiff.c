#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include <cblas.h>

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
void diff(double* u, int N, double dx, double* du)
{

	int i;
	
 	du[0] = (u[1] - u[0]) / dx; //Forward Difference for the 1st point
  
	for (i=1; i < N - 1; ++i)
  	{
    		du[i] = (u[i + 1] - u[i]) / dx; //Forward Difference for the middle points
  	}
  
  	du[N-1] = (u[N - 1] - u[N - 2]) / dx; //Backward Difference for the last point
  
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
  	for (i=0; i < N + 1; ++i)
  	{
    		u[i] = sin(i * dx);
    	}
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


	double* u = (double*)malloc((N+1)*sizeof(double));
	double* du = (double*)malloc((N+1)*sizeof(double));
	double* errdu = (double*)malloc((N+1)*sizeof(double));//calculating error.
	double dx = M_PI/N;

	init(u, N, dx);  

	for (int i=0; i < N+1;++i)
	{
    		printf("sin[%d] = %f  \n",i, u[i]);
    	}
    
	diff(u, N, dx, du);

	for (int i=0; i < N +1 ;++i)
	{
    		errdu[i] = cos(i * dx) - du[i];
    		printf("diff = %f - %f = %f \n",cos(i * dx), du[i], cos(i*dx) - du[i]);
	}
    
	double error_L2 = cblas_ddot(N+1, errdu, 1, errdu, 1);
	printf("L2 error = %f \n", sqrt(error_L2));

	free(u);
	free(du);
	free(errdu);

	return 0;
}

