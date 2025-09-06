#include <stdio.h>
#include <time.h>

int main() {
    // Start the clock
    clock_t start_time = clock();

    // Your program's code goes here
    // For demonstration, we'll use a simple loop
    for (long i = 0; i < 1000000000; i++) {
        // Simulate some work
    }

    // End the clock
    clock_t end_time = clock();

    // Calculate the elapsed time in seconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the elapsed time
    printf("Execution time: %.6f seconds\n", elapsed_time);

    return 0;
}

