#include <stdio.h>
//include <cblas.h> // This is the C interface for the BLAS library
include "https://www.netlib.org/blas/cblas.h"

/*
  int main(int argc, char* argv[])

  The main program creates two static vectors and then computes their
  dot product using the BLAS routing ddot (double precision dot product)

  Inputs: none

  Outputs: The dot product of the two vectors
  Usage:
  $ gcc -o ip example-71.c -lblas
  $./ip
*/

int main(int argc, char* argv[]) 
{
  // x and y are the two vectors that we will use
  double x[5] = {1., 2., 3., 4., 5.};
  double y[5] = {1., -1., 1., -1., 1.};

  // This is the call to the BLAS function.  
  // See the BLAS documentation for other functions and
  // the definition of the arguments
  // In this case, the first argument is the length of the
  // vectors, and the 3rd and 5th arguments are the increments
  // to use when traversing the vectors.
  double dotprod = cblas_ddot(5, x, 1, y, 1);

  // print the result
  printf("<x,y> = %lf\n", dotprod);

  return 0.;
}

