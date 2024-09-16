#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Monte Carlo Integration */

#define NUM_THROWS 100000000 // 100 million
// Number of processes defined in the Makefile

double monteCarloIntegration(int throw_count) {
    MPI_Init(NULL, NULL);
    MPI_Barrier(MPI_COMM_WORLD);
    double start = MPI_Wtime();
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int inside_per_process = 0;
    int throws_per_process = throw_count / size;
    int throws_remainder = throw_count % size;
    int throws = throws_per_process;
    if (rank < throws_remainder) {
      throws++;
    }
    srand(time(NULL) + rank);
    for (int i = 0; i < throws; i++) {
      double x = rand() / (double) RAND_MAX;
      double y = rand() / (double) RAND_MAX;
      if (x * x + y * y <= 1) {
        inside_per_process++;
      }
    }
    int total_inside_circle = 0;
    MPI_Reduce(&inside_per_process, &total_inside_circle, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0) {
      double pi = (double) 4.0 * total_inside_circle / throw_count;
      double end = MPI_Wtime();
      printf("Spent %f seconds\n", end - start);
      printf("Monte Carlo Integration: %f\n", pi);
    }
    MPI_Finalize();
    // return (double) 4.0 * inside_circle / THROW_COUNT;
}

int main() {
  monteCarloIntegration(NUM_THROWS);
  return 0;
}