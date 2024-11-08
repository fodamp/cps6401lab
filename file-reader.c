#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
int main()
    {
          int number[SIZE]; 
          int i=0;
          FILE* in_file = fopen("scores-data.txt", "r"); //only open a pre-exisiting file in read mode. 
         
          if (! in_file ) // equivalent to saying if ( in_file == NULL ) 
             {  
                printf("oops, file can't be read\n"); 
                exit(-1); 
             } 
          // attempt to read the next line and store 
          // the value in the "number" variable 
          while ( fscanf(in_file, "%d", & number[i] ) == 1 )  
             { 
               printf("We just read %d\n", number[i]);
               i++; 
             } 
      return 0;
    }
