#include <stdio.h>
#include <time.h>

int main() {
    struct timespec start_time, end_time;

    // Get the current time at the start
    clock_gettime(CLOCK_REALTIME, &start_time);

    // Your program's code goes here
    // For demonstration, we'll use a simple loop
    for (long i = 0; i < 1000000000; i++) {
        // Simulate some work
    }

    // Get the current time at the end
    clock_gettime(CLOCK_REALTIME, &end_time);

    // Calculate the elapsed time in seconds
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + 
                          (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    // Print the elapsed time
    printf("Execution time: %.6f seconds\n", elapsed_time);

    return 0;
}

