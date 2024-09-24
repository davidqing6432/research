#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

#define NUM_THREADS 4
#define NUM_THROWS 100000000 // 100 million

/* Monte Carlo Integration */

double monteCarloIntegration(int throw_count) {
    double start = omp_get_wtime();
    int inside_circle = 0;

    // Seed the random number generator for each thread
    unsigned int seed;

    // Parallelize using OpenMP with reduction to sum up the count of points inside the circle
    #pragma omp parallel private(seed) reduction(+:inside_circle)
    {
        seed = omp_get_thread_num() + 1; // Unique non-zero seed for each thread
        #pragma omp for
        for (int i = 0; i < throw_count; i++) {
            double x = rand_r(&seed) / (double) RAND_MAX;
            double y = rand_r(&seed) / (double) RAND_MAX;
            if (x * x + y * y <= 1) {
                inside_circle++;
            }
        }
    }

    double end = omp_get_wtime();
    printf("Spent %f seconds\n", end - start);
    return (double) 4.0 * inside_circle / throw_count;
}

int main() {
    omp_set_num_threads(NUM_THREADS);
    printf("Monte Carlo Integration: %f\n", monteCarloIntegration(NUM_THROWS));
    return 0;
}