#include <stdlib.h>
#include "sparse.h"

CSRMatrix create_csr_matrix(int rows, int cols, int nnz) {
    CSRMatrix mat;
    mat.num_rows = rows; mat.num_cols = cols; mat.nnz = nnz;
    mat.values = (double*)malloc(nnz * sizeof(double));
    mat.col_indices = (int*)malloc(nnz * sizeof(int));
    mat.row_pointers = (int*)malloc((rows + 1) * sizeof(int));
    return mat;
}

void spmv_csr(CSRMatrix* matrix, double* input_vector, double* output_vector) {
    // Compressed Sparse Matrix-Vector Multiplication (SpMV) loop
    for (int i = 0; i < matrix->num_rows; i++) {
        output_vector[i] = 0.0;
        int row_start = matrix->row_pointers[i];
        int row_end = matrix->row_pointers[i + 1];
        
        for (int j = row_start; j < row_end; j++) {
            output_vector[i] += matrix->values[j] * input_vector[matrix->col_indices[j]];
        }
    }
}

void free_csr_matrix(CSRMatrix* matrix) {
    free(matrix->values);
    free(matrix->col_indices);
    free(matrix->row_pointers);
}
