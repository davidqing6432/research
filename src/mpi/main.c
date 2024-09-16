#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Monte Carlo Integration */

#define THROW_COUNT 10000000
double monteCarloIntegration() {
    clock_t start = clock();
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    printf("Hello, world! I am %d of %d\n", rank, size);
    // int inside_circle = 0;
    // for (int i = 0; i < THROW_COUNT; i++) {
    //     double x = rand() / (double) RAND_MAX;
    //     double y = rand() / (double) RAND_MAX;
    //     if (x * x + y * y <= 1) {
    //         inside_circle++;
    //     }
    // }
    MPI_Finalize();
    clock_t end = clock();
    printf("Spent %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    // return (double) 4.0 * inside_circle / THROW_COUNT;
    return 0.0;
}

int main() {
  printf("Monte Carlo Integration: %f\n", monteCarloIntegration());
  return 0;
}

  // int rank, size;
  // MPI_Init(&argc, &argv);
  // MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  // MPI_Comm_size(MPI_COMM_WORLD, &size);
  // printf("Hello, world! I am %d of %d\n", rank, size);
  // MPI_Finalize();
  // return 0;