#include <stdio.h>
#include <math.h>


// Soving for the function
double fun(double x)
{
return (pow(x,6) -x - 1.0);
}

// Solving for the derivative
double derivfun(double x)
{
return (6.0 * pow(x,5) - 1.0);
}


// Bisection Method
double BisectionMet()
{

double root;
printf("Play game called");
return root;

}

// Newton's Method
double NewtonMet()
{
    
double root;
printf("Input the function: ");
//scanf();
return root;

}

double SecantMet()
{

double tol = 0.0001;
int max_iter = 50;
double x0;
double x1;
double x2 = 0;
int counter = 0;
//int option = 3;
//double root;

printf("\n Solving Equation Using The Secant Method \n");
printf("\n Enter initial First Number: \n");
scanf("%lf", &x0);

printf("\n Enter Initial Second Number: \n");
scanf("%lf", &x1);

if (fun(x0) == fun(x1))
{
	printf("funct(%f) = funct(%f). Please input different initial values \n", x0, x1);
	//return;
	//break;
}

else
{
	do
	{
	x2 = (x0 * fun(x1) - x1 * fun(x0))/(fun(x1) - fun(x0));
	counter = counter + 1;
	printf("At iteration = %d of maxiterations= %d |f(x2)| = %lf  \n ", counter, max_iter, fabs(fun(x2)));
	
	if(counter == max_iter)
	{
	printf("Max iterations reached. No convergence \n");
	break;
	}
	
	x0 = x1;
	x1 = x2;

	} while(fabs(fun(x2)) > tol);
	
	
	printf("\n The approximate root is %lf with tolerance = %lf using %d iterations \n ", x2, tol, counter);	

}
		
}
     


int main()
{
	int option; 
	printf("1. Bisection Method\n");
	printf("2. Newton's Method\n");
	printf("3. Secant Method\n");
        printf("4. Exit\n" );
        printf("Selection: ");
        
        scanf("%d", &option);
        
        switch ( option ) {
        	case 1:            
            		BisectionMet();
            	break;
            	
        	case 2:          
            		NewtonMet();
            	break;
            	
        	case 3:         
            		SecantMet();
            	break;
            	
        	case 4:        
            		printf( "Thanks!\n" );
            	break;
            	
        	default:            
            		printf( "Bad input, quitting!\n" );
            	break;
    }
 
}
