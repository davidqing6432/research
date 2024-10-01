#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_THROWS 100000000 // 100 million
// Explore whether this is using forks or multi-threading
// Run for extended period of time, how many processes are created.

double monteCarloIntegration(int throw_count) {
    uint32_t seed = 1;
    clock_t start = clock();
    int inside_circle = 0;
    for (int i = 0; i < throw_count; i++) {
        double x = rand_r(&seed) / (double) RAND_MAX;
        double y = rand_r(&seed) / (double) RAND_MAX;
        if (x * x + y * y <= 1) {
            inside_circle++;
        }
    }
    clock_t end = clock();
    printf("Spent %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return (double) 4.0 * inside_circle / throw_count;
}

int main() {
  printf("Monte Carlo Integration: %f\n", monteCarloIntegration(NUM_THROWS));
  return 0;
}