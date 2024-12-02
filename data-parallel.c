#include<stdlib.h>
#include<stdio.h>
#include<omp.h> //OpenMP header.
/*
 Parallel programming can be achieved using Open MP. 
 Goal of this program is to create a parallel vector sum calculation using  Open MP.
 Author: CPS 5401
 Date: 10-31-22.
 Source: 
 https://curc.readthedocs.io/en/latest/programming/OpenMP-C.html
 https://www.geeksforgeeks.org/openmp-hello-world-program/
 */


/* Step01: Specify the parallel region. 
In OpenMP, we need to specify the region which we are going to make it as parallel
using the keywork pragma omp parallel. This is used to fork additional threads to 
carry out the work enclosed in the parallel. 
The original thread will be denoted as the master thread with thread ID 0.
*/

/*Step02: To compile and run.
 * export OMP_NUM_THREADS= N N could be any positive integer say 6 or 4 or 3.
 * gcc -o hello -fopenmp hello-world-open-mp.c 
 * ./hello
 */

int main(int argc, char* argv[]){

int N = atoi(argv[1]);
int Nthreads = atoi(argv[2]);
int a[12], b[12], c[12];
    for (int i = 0 ; i < 12; i++)
        {
            a[i] = 11*i; 
            b[i] = -i;
        }
printf("array a entries: \n");
    for (int i = 0 ; i < 12; i++)
        {
            printf("%3d ", a[i]);
        }
printf("\n");
printf("array b entries:\n");
     for (int i = 0 ; i < 12; i++)
        {
            printf("%3d ", b[i]);
        }
printf("\n");
// Beginning of parallel region    
#pragma omp parallel
{
 

  for (int i = 0 ; i < 12; i++)
        {
            c[i] = a[i] + b[i];             
            printf("Executing sum at index %d by thread %d. \n", i, omp_get_thread_num());
        }
}
 // Ending of parallel region    
    for (int i = 0 ; i < 12; i++)
        {
            printf("%3d ", c[i]);
        }
printf("\n");  
}
