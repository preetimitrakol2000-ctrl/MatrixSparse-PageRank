#include <math.h>
#include "sparse.h"

void run_power_iteration(CSRMatrix* transition_matrix, double* rank_vector, int max_epochs, double damping) {
    int n = transition_matrix->num_rows;
    double* temporary_vector = (double*)malloc(n * sizeof(double));

    for (int epoch = 0; epoch < max_epochs; epoch++) {
        spmv_csr(transition_matrix, rank_vector, temporary_vector);

        // Apply Google Damping Factor math: P(e) = (1 - d)/N + d * M * P(e-1)
        double teleport_bias = (1.0 - damping) / n;
        for (int i = 0; i < n; i++) {
            rank_vector[i] = teleport_bias + damping * temporary_vector[i];
        }
    }
    free(temporary_vector);
}
