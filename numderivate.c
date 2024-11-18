#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
f(x)=sin(x) on [0,2pi]. h=2pi/N
*/
int main(int argc, char* argv[]){

int N =atoi(argv[1]);

/*introduce a pointer to the array containing the exact derivative and 
its forward difference approximation.*/
double* dfdx =(double*)malloc(N*sizeof(double));
double* Dfh =(double*)malloc(N*sizeof(double)); //notice how D replaces d and h replaces dx!

double h = M_PI/N;

return 0;
}
