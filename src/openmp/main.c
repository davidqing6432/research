#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

/* Monte Carlo Integration */

double monteCarloIntegration(int throw_count) {
    clock_t start = clock();
    int inside_circle = 0;

    // Seed the random number generator for each thread
    unsigned int seed;

    // Parallelize using OpenMP with reduction to sum up the count of points inside the circle
    #pragma omp parallel private(seed) reduction(+:inside_circle)
    {
        seed = time(NULL) ^ omp_get_thread_num(); // Unique seed for each thread
        #pragma omp for
        for (int i = 0; i < throw_count; i++) {
            double x = rand_r(&seed) / (double) RAND_MAX;
            double y = rand_r(&seed) / (double) RAND_MAX;
            if (x * x + y * y <= 1) {
                inside_circle++;
            }
        }
    }

    clock_t end = clock();
    printf("Spent %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return (double) 4.0 * inside_circle / throw_count;
}

int main() {
    int throw_count = 100000000;
    printf("Monte Carlo Integration: %f\n", monteCarloIntegration(throw_count));
    return 0;
}