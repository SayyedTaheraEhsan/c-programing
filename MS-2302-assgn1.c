#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, N;
    int *numbers = NULL;
    int local_n, *sub_array = NULL;
    int local_sum = 0, total_sum = 0;

    MPI_Init(&argc, &argv);               // Initialize MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get process rank
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Get total processes
    if (rank == 0) {
        // Take input from user
        printf("Enter total number of elements (N): ");
        scanf("%d", &N);
        // Allocate and read number
        numbers = (int *)malloc(N * sizeof(int));
        printf("Enter %d numbers:\n", N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &numbers[i]);
        }
    }
    // Broadcast N to all processors
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // Each process gets local_n elements
    local_n = N / size;
    int remainder = N % size;
    // Handle uneven distribution
    if (rank < remainder) {
        local_n++;
    }
    sub_array = (int *)malloc(local_n * sizeof(int));
    // Scatter data to all processors
    // First, prepare counts and displacements on root
    int *sendcounts = NULL;
    int *displs = NULL;

    if (rank == 0) {
        sendcounts = (int *)malloc(size * sizeof(int));
        displs = (int *)malloc(size * sizeof(int));
        int offset = 0;
        for (int i = 0; i < size; i++) {
            sendcounts[i] = N / size;
            if (i < remainder) sendcounts[i]++;
            displs[i] = offset;
            offset += sendcounts[i];
        }
    }

    MPI_Scatterv(numbers, sendcounts, displs, MPI_INT,
                 sub_array, local_n, MPI_INT, 0, MPI_COMM_WORLD);
    // Each process computes its local sum
    for (int i = 0; i < local_n; i++) {
        local_sum += sub_array[i];
    }

    // Reduce all local sums to root process
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Root prints the final result
    if (rank == 0) {
        printf("Total Sum = %d\n", total_sum);
        free(numbers);
        free(sendcounts);
        free(displs);
    }

    free(sub_array);
    MPI_Finalize();
    return 0;
}
