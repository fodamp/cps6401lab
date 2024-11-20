
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  void diff_forward(double* u, int N, double dx, double* du)

  Computes a forward finite difference approximation for du/dx

  Inputs: 
  u: pointer for input array
  N: length of the array
  dx: the space step size
  du: pointer to output array

  Outputs: 
  du: contains the forward finite difference approximation
*/
void diff_forward(double* u, int N, double dx, double* du_forward) {
    int i;
    // Forward difference for the first point
    du_forward[0] = (u[1] - u[0]) / dx;

    for (i=1; i<N-1; ++i) {
    du_forward[i] = (u[i]-u[i-1])/dx;
  }
  du_forward[N-1] = (u[N-1]-u[N-2])/dx;
    
    // Forward difference for the middle points
    
}

/*
  void diff_central(double* u, int N, double dx, double* du)

  Computes a central finite difference approximation for du/dx

  Inputs: 
  u: pointer for input array
  N: length of the array
  dx: the space step size
  du: pointer to output array

  Outputs: 
  du: contains the central finite difference approximation
*/
void diff_central(double* u, int N, double dx, double* du_central) {
    int i;
    // Central difference for the first and last points can be done using forward/backward differences
    du_central[0] = (u[1] - u[0]) / dx;  // Forward difference at the start
    du_central[N] = (u[N] - u[N-1]) / dx;  // Backward difference at the end

    // Central difference for the middle points
    for (i = 1; i <= N-1; ++i) {
        du_central[i] = (u[i+1] - u[i-1]) / (2 * dx);
    }
}

/*
  void init(double* u, int N, double dx)

  Initializes the data array with the sin function

  Inputs: 
  u: pointer to array where values will be stored
  N: length of the array
  dx: the space step size

  Outputs: 
  u: contains data for a sin function
*/
void init(double* u, int N, double dx) {
    int i;
    for (i = 0; i < N+1; ++i)  // N+1 because we need N+1 points from 0 to N inclusive
        u[i] = sin(i * dx);
}

/*
  int main(int argc, char* argv[])

  Function tests the forward and central difference methods

  Inputs: argc should be 2
  argv[1] is the integer length of the data array
  
  Outputs: Prints the approximation and error for both methods
*/
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);

    double* u = (double*)malloc((N+1) * sizeof(double));  // N+1 points
    double* du_forward = (double*)malloc((N+1) * sizeof(double));  // N points for forward difference
    double* du_central = (double*)malloc((N+1) * sizeof(double));  // N points for central difference
    double dx = M_PI / N;

    // Initialize the sin function values
    init(u, N, dx);  

    // Compute forward and central differences
    diff_forward(u, N, dx, du_forward);
    diff_central(u, N, dx, du_central);


 
  // Print results
   // printf("\nIndex  x_value   du_Forward_  du_Central  Exact_derivative  Forward_diff  Central_diff\n");
    // printf("\n du_Forward_  du_Central  Forward_diff  Central_diff\n");
    printf("---------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < N+1; ++i) {
        double x = i * dx;
        double exact_derivative = cos(x);  // Exact derivative of sin(x) is cos(x)
        double forward_error = -du_forward[i] + exact_derivative;
        double central_error = -du_central[i] + exact_derivative;
        
       // printf("%d   %.6f   %.6f   %.6f   %.6f   %.6f   %.6f\n",  i, x, du_forward[i], du_central[i], exact_derivative, forward_error, central_error);

          printf(" forward diff error=%.6f -  %.6f =%6f  ,central difference error= %.6f  - %.6f=%6f\n",  exact_derivative, du_forward[i], forward_error,exact_derivative, du_central[i],central_error);
          //printf(" %.6f   %.6f   %.6f   %.6f\n",   du_forward[i], du_central[i],  forward_error, central_error);
    }





    free(u);
    free(du_forward);
    free(du_central);

    return 0;
}

