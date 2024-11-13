#include<stdio.h>


/*
argc (argument count):
An integer representing the number of arguments passed to the program, including the program name itself.
argv (argument vector):
An array of character pointers (strings) containing the actual arguments passed.
Usage: 
$ gcc -o hw argc-argv-hello-world.c
$ ./hw arg1 arg 2
here argv entry 0: ./hw
here argv entry 1: arg1
here argv entry 2: arg2
*/


int main(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
// int main(int n, char* arr[]){

//     printf("hello world! %d \n", n);


//     int i=0;
//     while (arr[i] != 0)
//         {
//         printf("arg is  %s \n ", arr[i]);
//         i++;
//         }//need the paranthesis in my compiler.

//     //printf("new  %s \n ", arr[1]);
//     return 0;
// }
