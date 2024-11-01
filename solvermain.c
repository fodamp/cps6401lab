#include <stdio.h>
#include <math.h>
#include "solverhead.h"


/*
x^6-x-1=0
f(x)=x^6-x-1
*/
//secant
//tol and max_iter globally using #DEFINE
//#define MAX_ITER 100 


int main()
{
	int input;
     
	printf( "\nChoose a Method to solve the quatratic equation: x^6 - x - 1 = 0 \n");
        printf( "1. Bisection Method\n" );
        printf( "2. Newton Method\n" );
        printf( "3. Secant Medthod\n" );
        printf( "4. Exit\n" );
        printf( "Selection: " );
        scanf( "%d", &input );
        
        switch ( input ) 
        {
		case 1:            /* Note the colon, not a semicolon */
                	BisectionMet();
                	break;
            	case 2:          
                	NewtonMet();
                	break;
            	case 3:         
                	SecantMet();
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
