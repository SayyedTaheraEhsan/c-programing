#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// Sequential quicksort
void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1, j, temp;
        for (j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Merge two sorted arrays
void merge(int *a, int n, int *b, int m, int *result) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }
    while (i < n) result[k++] = a[i++];
    while (j < m) result[k++] = b[j++];
}

int main(int argc, char *argv[]) {
    int rank, size, n = 16;
    int data[16] = {20, 2, 9, 35, 40, 1, 5, 3, 8, 31, 21, 22, 19, 12, 6, 7};

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int local_n = n / size;
    int *local_data = (int*)malloc(local_n * sizeof(int));

    // Scatter data among processes
    MPI_Scatter(data, local_n, MPI_INT, local_data, local_n, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process sorts its chunk
    quicksort(local_data, 0, local_n - 1);

    // Gather sorted subarrays at root
    int *gathered = NULL;
    if (rank == 0) {
        gathered = (int*)malloc(n * sizeof(int));
    }
    MPI_Gather(local_data, local_n, MPI_INT, gathered, local_n, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // Merge all sorted chunks
        int *merged = gathered;
        int merged_size = local_n;

        for (int i = 1; i < size; i++) {
            int *temp = (int*)malloc((merged_size + local_n) * sizeof(int));
            merge(merged, merged_size, gathered + i * local_n, local_n, temp);
            merged = temp;
            merged_size += local_n;
        }

        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", merged[i]);
        }
        printf("\n");
    }

    free(local_data);
    if (rank == 0) free(gathered);

    MPI_Finalize();
    return 0;
}