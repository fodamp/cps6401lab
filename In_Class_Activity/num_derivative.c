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


//Central Differnce
void diff_central(double* u, int N, double dx, double* du)
{
	int i;
	du[0] = (u[1] - u[N-1]) / (2 * dx);
  
	for (i=1; i < N - 1; ++i)
  	{
    		du[i] = (u[i + 1] - u[i-1]) / (2 * dx);
  	}
  
  	du[N - 1] = (u[0] - u[N - 2])/ (2 * dx);
}

//Forward Difference
void diff_forward(double* u, int N, double dx, double* du)
{
  	int i;
  	du[0] = (u[1] - u[0]) / dx; //Forward Difference for the 1st point
  
  
  	for (i=1; i < N - 1; ++i)
  	{
    		du[i] = (u[i+1] - u[i]) / dx; //Forward Difference for the middle points
  	}
  
  	du[N-1] = (u[N-1] - u[N-2]) / dx; //Backward Difference for the last point
  
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
	double* du = (double*)malloc((N + 1) * sizeof(double));
	double* errdu = (double*)malloc((N + 1) * sizeof(double));//calculating error.

	double* dfdx =(double*)malloc((N + 1) * sizeof(double)); //For Central Difference
	double* Dfh =(double*)malloc((N + 1) * sizeof(double));
	double* errdfdx = (double*)malloc((N + 1) * sizeof(double));

	double dx = (2 * M_PI) / N;
	//
	double dx = M_PI / N;


	printf("\nApproximation of sin(x) using Forward Difference\n");
	init(u, N, dx); 

	for (int i=0; i < N+1;++i)
    		printf("sin[%d] = %f  \n",i, u[i]);
    
	diff_forward(u, N, dx, du);

	for (int i=0; i < N+1;++i)
	{
    		errdu[i] = cos(i * dx) - du[i];
    		printf("diff = %f - %f = %f \n",cos(i*dx), du[i], cos(i*dx)-du[i]);
	}
    
	double error_L2_forward = cblas_ddot(N+1, errdu, 1, errdu, 1);
	printf("L2 error = %f \n", sqrt(error_L2_forward));


	printf("\nApproximation of sin(x) using Central Difference\n");

	init(dfdx, N, dx);  

	for (int i=0; i < N+1;++i)
    		printf("sin[%d] = %f  \n",i, dfdx[i]);
    
    
	diff_central(dfdx, N, dx, Dfh);

	for (int i=0; i< N+1;++i)
	{
    		errdfdx[i] = cos(i * dx) - Dfh[i];
    		printf("diff = %f - %f = %f \n", cos(i*dx), Dfh[i], cos(i*dx) - Dfh[i]);
	}

	double error_L2_central = cblas_ddot(N + 1, errdfdx, 1, errdfdx, 1);
	printf("L2 error = %f \n", sqrt(error_L2_central));




	free(dfdx);
	free(Dfh);
	free(errdfdx);
	free(u);
	free(du);
	free(errdu);

	return 0;
}


