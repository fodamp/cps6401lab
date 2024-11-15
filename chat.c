#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 31

int main()
{
    int number[SIZE];
    int numbmod[SIZE]; // Array to store modes
    int b = 0;
    double avg = 0.0;
    double sum = 0.0;
    double sdsum = 0.0;
    int counter = 0;
    int freq = 0;
    int multiplefreq = 0;
    int freqnum = -9999999;

    FILE* in_file = fopen("data_scores.txt", "r"); // Only open a pre-existing file in read mode. 
         
    if (!in_file) // Equivalent to saying if (in_file == NULL)
    {
        printf("Oops, file can't be read\n"); 
        exit(-1); 
    }

    // Read numbers into the array
    while (fscanf(in_file, "%d", &number[b]) == 1) 
    { 
        b++;
    }

    // Print the numbers read from the file for debugging purposes
    printf("Numbers read from file: ");
    for (int i = 0; i < b; i++) {
        printf("%d ", number[i]);
    }
    printf("\n");

    // Loop through each number in the array to find its frequency
    for (int q = 0; q < b; ++q)
    {
        sum += number[q];  // Find the sum of all the numbers in the array/file read
        counter = 0; // Reset counter for each new number

        // Count occurrences of number[q]
        for (int r = 0; r < b; ++r) 
        {
            if (number[r] == number[q]) // If number matches
                counter++; // Increase frequency
        }

        // Print frequency for each number for debugging purposes
        printf("Number %d has a frequency of %d\n", number[q], counter);

        // Skip if number[q] has already been processed
        int alreadyProcessed = 0;
        for (int m = 0; m < multiplefreq; ++m) {
            if (numbmod[m] == number[q]) {
                alreadyProcessed = 1;
                break;
            }
        }
        
        if (alreadyProcessed)
            continue;  // Skip the already processed number

        // If this frequency is greater than the current max frequency
        if (counter > freq) 
        {
            freq = counter; // Update maximum frequency
            freqnum = number[q]; // Update mode
            multiplefreq = 1; // Reset multiple frequency count
            numbmod[0] = number[q]; // Store first mode
        } 
        else if (counter == freq) // If there's a tie in frequency
        {
            // Store the number if it's not already in the modes array
            numbmod[multiplefreq] = number[q]; // Store mode
            ++multiplefreq; // Increase count of modes
        }
    }

    avg = sum / SIZE; // Calculate average

    // Calculate standard deviation
    for (int s = 0; s < b; ++s)
        sdsum += pow(fabs(number[s] - avg), 2);
    
    sdsum = sqrt(sdsum / SIZE);

    // Print the summary statistics
    printf("\nThe summary statistics of the grades:\n");
    for (int t = 0; t < b; ++t)
    {
        printf("Grade %d: %d\n", t + 1, number[t]);
    }

    printf("\n1. Average: %.3lf \n", avg);

    // Print all modes
    if (multiplefreq > 0)
    {
        for (int n = 0; n < multiplefreq; ++n)
        {
            printf("2. Mode %d: %d\n", n + 1, numbmod[n]);
        }
    }
    else
    {
        printf("2. Mode: %d \n", freqnum);
    }

    printf("3. Standard deviation: %.3lf \n", sdsum);
    
    return 0;
}

