#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include <cblas.h>



/*
f(x)=sin(x) on [0,pi]. h=pi/N
*/


//Second Order Difference
void diff_second(double* u, int N, double dx, double* d2u)
{
	int i;
	//du[0] = (u[1] - u[N-1]) / (2 * dx);
  
	for (i=1; i < N - 1; ++i)
  	{
    		d2u[i] = (u[i + 1] - 2.0 * u[i] + u[i-1]) / (dx * dx);
  	}
  
  	//du[N - 1] = (u[0] - u[N - 2])/ (2 * dx);
}




void init(double* u, int N, double dx)
{
  	int i;
  	for (i=0; i < N+1; ++i)
    		u[i] = sin(i*dx);
}


int main(int argc, char* argv[])
{
	int N = atoi(argv[1]);


	double* u = (double*)malloc((N + 1) * sizeof(double));//For Forward Difference
	double* d2u = (double*)malloc((N + 1) * sizeof(double));
	double* errd2u = (double*)malloc((N + 1) * sizeof(double));//calculating error.


	double h = M_PI / N;
	


	printf("\nApproximation of sin(x) using Second Order Derivative\n");
	init(u, N, h); 

	for (int i=0; i < N-1;++i)
    		printf("sin[%d] = %f  \n",i, u[i]);
    
	diff_second(u, N, h, d2u);

	for (int i=0; i < N+1;++i)
	{
    		errd2u[i] = -sin((i + 1) * h) - d2u[i + 1];
    		//printf("diff = %f - %f = %f \n",-sin((i + 1)*dx), d2u[i + 1], -sin((i + 1)*dx) - d2u[i + 1]);
	}
    
	double error_L2 = cblas_ddot(N-1, errd2u, 1, errd2u, 1);
	printf("L2 error = %f \n", sqrt(error_L2));


	free(u);
	free(d2u);
	free(errd2u);

	return 0;
}


