#include<stdio.h>



int mult(int a, int b)
{
	return a*b;
}


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	//printf("Swapping using pinters the values of a and b are a = %d  and b=%d \n", *a, *b);
	
}


int main()
{
 	int cat1;
 	//int *pntcat1 = &cat1;
 	//printf("value of pntcat1 = %d \n", *pntcat1);
 	
 	int cat2;
 	//int *pntcat2 = &cat2;
 	printf("Enter two intergers: \n");
 	scanf("%d %d", &cat1, &cat2);
 	
 	printf("The values of the integers before swapping is a = %d and b = %d\n", cat1, cat2);
 	
 	swap(&cat1, &cat2);
 	printf("The values of the integers after swapping is a = %d and b = %d\n", cat1, cat2);
 	
 	
 	printf("Product of %d and %d is %d\n", cat1, cat2, mult(cat1, cat2));
 	
 	return 0;

}
