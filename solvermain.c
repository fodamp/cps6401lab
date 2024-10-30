#include <stdio.h>
#include <math.h>
/*
x^6-x-1=0
f(x)=x^6-x-1
*/
//secant
//tol and max_iter globally using #DEFINE
#define MAX_ITER 100 
#include "nonlinear-solver.h"

int main()
{
        int input;
    double tol =1e-16;
    int max_iter=1e+8;
        //int option=3;
        double x0 = 50;
        double x1 = 10.82;
        double a = -1.0;
        double b = 4.0 ;
        double x2=90.0 ; 

        printf( "1. bisection\n" );
        printf( "2. Newton\n" );
        printf( "3. Secant\n" );
        printf( "4. Exit\n" );
        printf( "Selection: " );
        scanf( "%d", &input );
        switch ( input ) {
            case 1:            /* Note the colon, not a semicolon */
                bisection(a,b, tol, MAX_ITER /*max_iter*/);
                break;
            case 2:          
                newton( x0, tol, max_iter);
                break;
            case 3:         
                secant(x0, x1, tol, max_iter);
                break;
            case 4:        
                printf( "Thanks for playing!\n" );
                break;
            default:            
                printf( "Bad input, quitting!\n" );
                break;
        }//end of switch
        getchar();
 
}
