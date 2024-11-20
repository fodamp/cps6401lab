#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
#include <cblas.h>


/*
f(x)=sin(x) on [0,2pi]. h=2pi/N
*/




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
  du[0] = (u[1] - u[0])/dx;
  
  for (i=1; i < N-1; ++i)
  {
    du[i] = (u[i + 1] - u[i-1])/(2 * dx);
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
  for (i=0; i < N+1; ++i)
    u[i] = sin(i*dx);
}





int main(int argc, char* argv[]){

int N =atoi(argv[1]);

/*introduce a pointer to the array containing the exact derivative and 
its forward difference approximation.*/
double* dfdx =(double*)malloc(N*sizeof(double));
double* Dfh =(double*)malloc(N*sizeof(double)); //notice how D replaces d and h replaces dx!
double* errdfdx = (double*)malloc((N+1)*sizeof(double));

double h = (2 * M_PI)/N;

init(dfdx, N, h);  

for (int i=0; i < N;++i)
    printf("sin[%d] = %f  \n",i, dfdx[i]);
    
    
diff(dfdx, N, h, Dfh);

for (int i=0; i< N;++i)
{
    errdfdx[i] = cos(i * h) - Dfh[i];
    printf("diff = %.6f - %.6f = %.6f \n", cos(i*h), Dfh[i], cos(i*h) - Dfh[i]);
}

double error_L2 = cblas_ddot(N+1, errdfdx, 1, errdfdx, 1);
printf("L2 error = %f \n", sqrt(error_L2));

free(dfdx);
free(Dfh);
free(errdfdx);


return 0;
}

