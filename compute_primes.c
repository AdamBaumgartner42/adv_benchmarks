#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void compute_primes(int limit) {
    bool *is_prime = malloc((limit + 1) * sizeof(bool));
    if (is_prime == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (int i = 2; i <= limit; i++) {
        is_prime[i] = true;
    }

    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    printf("Prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(is_prime);
}

int main() {
    int limit;
    printf("Enter the upper limit to compute prime numbers: ");
    scanf("%d", &limit);

    if (limit < 2) {
        printf("There are no prime numbers less than 2.\n");
    } else {
        compute_primes(limit);
    }

    return 0;
}

