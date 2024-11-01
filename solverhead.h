
// Defining macros

#define MAX_ITER 100
#define TOL 1e-04


//Defining global variables

double x0, x1;
double x2 = 0;
double x3 = 0;
int counter = 0;


// Solving for the function

double fun(double x)
{
	return (pow(x,6) - x - 1.0);
}


// Solving for the derivative

double derivfun(double x)
{
	return (6.0 * pow(x,5) - 1.0);
}



/*
void bisection(double a_, double b_, double tol_, int max_iter_){

    printf("MAX ITERS = %d \n", MAX_ITER);
}
*/


// Bisection Method
void BisectionMet()
	{

		printf("\nSolving Equation Using The Bisection Method \n");
		
		printf("\nEnter Initial First Number: \n");
		scanf("%lf", &x0);

		printf("\nEnter Initial Second Number: \n");
		scanf("%lf", &x1);
		
		printf("\n");
	
	
		if (x0 > x1)  //Checking if the first number is less than the second number
		{
			printf("\nThe first initial number should be less than the second.\n");
			//break;
		}else if (fun(x0) * fun(x1) > 0) //Checking if the two numbers have opposite signs
		{
			printf("\nThe function is not continuous and there is no root between the initial two numbers given\n");
			//break;
		}else{
	
			do	
			{
				//printf("Counter %d\n", counter);
				
				if (counter == MAX_ITER)
				{
					printf("\nMax iterations reached. No convergence\n");
					break;
				}
		
				
				// Calculating the midpoint between the two numbers
	
				x3 = (x0 + x1)/2;
				counter = counter + 1;
				printf("At iteration = %d of maxiterations= %d |f(x3)| = %lf \n", counter, MAX_ITER, fabs(fun(x3)));
		
				if (fun(x3) == 0)
				{
					printf("\nThe root of the function is: %lf \n", x3);
					break;
				}else if (fun(x3) < 0)
				{
					x0 = x3;
				}else
				{
					x1 = x3;
				}
			}while (fabs(fun(x3)) > TOL);
		}
	printf("\nThe approximate root is %lf with tolerance = %lf using %d iterations\n", x3, TOL, counter); 
	//return 0;
	
}


                      
//void newton( double x0, double tol, double max_iter){}


// Newton's Method
void NewtonMet()
{

	printf("\nSolving Equation Using Newton's Method\n");
	printf("\nEnter Initial Number: \t");
	scanf("%lf", &x0);
	
	printf("\n");  


	do 
	{
		if (counter == MAX_ITER)
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
		printf("At iteration = %d of maxiterations= %d |f(x2)| = %lf\n", counter, MAX_ITER, fabs(fun(x2)));
		x0 = x2;

	} while (fabs(fun(x2)) > TOL); 

	printf("\nThe approximate root is %lf with tolerance = %lf using %d iterations\n", x2, TOL, counter); 

	//return 0;

}




void SecantMet()
{

	printf("\nSolving Equation Using The Secant Method \n");
	
	printf("\nEnter initial First Number: \n");
	scanf("%lf", &x0);

	printf("\nEnter Initial Second Number: \n");
	scanf("%lf", &x1);
	
	printf("\n");

	if (fun(x0) == fun(x1))
	{
		printf("funct(%f) = funct(%f). Please input different initial values\n", x0, x1);
		//break;
	}else
	{
		do
		{
			x2 = (x0 * fun(x1) - x1 * fun(x0))/(fun(x1) - fun(x0));
			
			counter = counter + 1;
			printf("At iteration = %d of maxiterations= %d |f(x2)| = %lf\n", counter, MAX_ITER, fabs(fun(x2)));
	
			if(counter == MAX_ITER)
			{
				printf("Max iterations reached. No convergence\n");
				break;
			}
			
	
			x0 = x1;
			x1 = x2;

			}while(fabs(fun(x2)) > TOL);
	
	
			printf("\nThe approximate root is %lf with tolerance = %lf using %d iterations\n", x2, TOL, counter);	

	}
	//return 0;		
}







/*


void secant(double x0, double x1, double tol, int max_iter ){
int counter= 0;
double x2 = -100;   
do
    {
        if(f(x0)==f(x1))
            {
                printf("f(%lf)=f(%lf) choose different x0 and x1 \n" , x0, x1);
                break;
            }
        x2 = x1 - (((x1-x0)*f(x1))/(f(x1)-f(x0)));
        printf("x2= %lf \n ", x2);
        counter=counter + 1; //counter++;
        printf("at iteration = %d of maxiterations= %d |f(x2)| = %lf  \n ", counter, max_iter, fabs(f(x2)));
        if( counter == max_iter)
            {
                printf("Max iterations reached no convergence \n");
                break;
            }
        x0=x1;
        x1=x2;
    
    } while(fabs(f(x2))> tol);

}

*/
