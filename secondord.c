#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include <cblas.h>



/*
f(x)=sin(x) on [0,2pi]. h=2pi/N
*/


void diff(double* u, int N, double dx, double* d2u)
{

  	for (i = 1; i < N - 1; ++i)
  	{
    		
    		d2u[i - 1] = (u[i + 1] - 2.0 * u[i] + u[i - 1]) / (dx * dx);
  	}

}


void init(double* u, int N, double dx)
{
  	int i;
  	for (i = 0; i < N+1; ++i)
    		u[i] = sin(i*dx);
}


int main(int argc, char* argv[])
{
	int N = atoi(argv[1]);


	double* u = (double*)malloc((N + 1) * sizeof(double));//For Forward Difference
	double* d2u = (double*)malloc((N + 1) * sizeof(double));
	double* errd2u = (double*)malloc((N - 1) * sizeof(double));//calculating error.

	

	double dx = (2 * M_PI) / N;



	for (int i = 0; i < N - 1;++i)
	{
    		errdu[i] = -sin(i * dx) - d2u[i+1];
	}
    
	double error_L2 = cblas_ddot(N - 1, errd2u, 1, errd2u, 1);
	printf("L2 error = %f \n", sqrt(error_L2));
	



	free(u);
	free(d2u);
	free(errd2u);

	return 0;
}


