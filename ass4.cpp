#include <mpi.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int rank, size;
    const int n = 4; // matrix size 4x4

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Ensure we run with 4 processes
    if (size != 4) {
        if (rank == 0) cout << "Run with 4 processes!" << endl;
        MPI_Finalize();
        return 0;
    }

    int A[n][n];  // full matrix
    int x[n];     // vector
    int local_row[n]; // one row for each process
    int local_result = 0;
    int result[n]; // final result vector

    // Root process initializes data
    if (rank == 0) {
        // Example matrix
        int tempA[4][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };
        int tempX[4] = {1, 1, 1, 1};

        // Copy into A and x
        for (int i = 0; i < n; i++) {
            x[i] = tempX[i];
            for (int j = 0; j < n; j++)
                A[i][j] = tempA[i][j];
        }
    }

    // Broadcast vector x to all processes
    MPI_Bcast(x, n, MPI_INT, 0, MPI_COMM_WORLD);

    // Scatter rows of A: each process gets 1 row
    MPI_Scatter(A, n, MPI_INT, local_row, n, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process computes its row dot product
    for (int j = 0; j < n; j++)
        local_result += local_row[j] * x[j];

    // Gather results into final vector y
    MPI_Gather(&local_result, 1, MPI_INT, result, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Root prints result
    if (rank == 0) {
        cout << "Result vector: ";
        for (int i = 0; i < n; i++)
            cout << result[i] << " ";
        cout << endl;
    }

    MPI_Finalize();
    return 0;
}
