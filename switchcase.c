#include <stdio.h>
#include <math.h>


//Global Variables
double tol = 1e-8;
int max_iter = 50;
double x0;
double x1;
double x2 = 0;
double x3 = 0;
int counter = 0;


// Soving for the function
double fun(double x)
{
return (pow(x,6) - x - 1.0);
}

// Solving for the derivative
double derivfun(double x)
{
return (6.0 * pow(x,5) - 1);
}


// Bisection Method
double BisectionMet()
{

printf("\nSolving Equation Using The Bisection Method \n");
printf("\nEnter Initial First Number: \n");
scanf("%lf", &x0);

printf("\nEnter Initial Second Number: \n");
scanf("%lf", &x1);
	
	
if (x0 > x1)
{
printf("\nThe first initial number should be less than the second.\n");
//break;
} else if (fun(x0) * fun(x1) > 0)
{
printf("\nThe function is not continuous and there is no root between the initial two numbers given\n");
//break;
} 
else{
	
do	
{
	printf("Counter %d\n", counter);
	if (counter == max_iter)
	{
	printf("\nMax iterations reached. No convergence\n");
	break;
	}
		
	// Calculating the midpoint
	
	x3 = (x0 + x1)/2;
	counter = counter + 1;
		
	if (fun(x3) == 0)
	{
	printf("\nThe root of the function is: %lf \n", x3);
	break;
	} 
	else if (fun(x3) < 0)
	{
	x0 == x3;
	} 
	else
	{
	x1 == x3;
	}
}while (fabs(fun(x3)) > tol);
}
	
}
	
	
	
	

//double root;
//printf("Play game called");
//return root;

//}

// Newton's Method
double NewtonMet()
{

printf("\nSolving Equation Using Newton's Method\n");
printf("\nEnter Initial Number: \t");
scanf("%lf", &x0);  


do 
{
	if (counter == max_iter)
	{
	printf("\nMax iterations reached. No convergence\n");
	break;
	}
	
	if (derivfun(x0) == 0 )
	{
	printf("\nNo root found\n");
	break;
	}
	
	x2 = x0 - (fun(x0)/derivfun(x0));
	counter = counter + 1;
	printf("At iteration = %d of maxiterations= %d |f(x2)| = %lf\n ", counter, max_iter, fabs(fun(x2)));
	x0 = x2;

} while (fabs(fun(x2)) > tol); 

printf("\nThe approximate root is %lf with tolerance = %lf using %d iterations\n ", x2, tol, counter); 

//printf("Input the function: ");
//scanf();
//return root;

}

double SecantMet()
{
//int option = 3;
//double root;

printf("\nSolving Equation Using The Secant Method \n");
printf("\nEnter initial First Number: \n");
scanf("%lf", &x0);

printf("\nEnter Initial Second Number: \n");
scanf("%lf", &x1);

if (fun(x0) == fun(x1))
{
	printf("funct(%f) = funct(%f). Please input different initial values\n", x0, x1);
	//return;
	//break;
}

else
{
	do
	{
	x2 = (x0 * fun(x1) - x1 * fun(x0))/(fun(x1) - fun(x0));
	counter = counter + 1;
	printf("At iteration = %d of maxiterations= %d |f(x2)| = %lf\n ", counter, max_iter, fabs(fun(x2)));
	
	if(counter == max_iter)
	{
	printf("Max iterations reached. No convergence\n");
	break;
	}
	
	x0 = x1;
	x1 = x2;

	} while(fabs(fun(x2)) > tol);
	
	
	printf("\nThe approximate root is %lf with tolerance = %lf using %d iterations\n ", x2, tol, counter);	

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
