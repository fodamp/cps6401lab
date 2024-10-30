#define MAX_ITER 100


double f(double x){


  return (pow(x,6) - x - 1.0  );
}


//newton
double dfdx(double x)
{
  return (6.0*pow(x,5)  - 1.0  );
}


void bisection(double a_, double b_, double tol_, int max_iter_){

    printf("MAX ITERS = %d \n", MAX_ITER);
}


                      
void newton( double x0, double tol, double max_iter){}




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
