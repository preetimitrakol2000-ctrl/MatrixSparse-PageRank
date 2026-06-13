#ifndef SPARSE_H
#define SPARSE_H

typedef struct {
    int num_rows;
    int num_cols;
    int nnz; // Number of Non-Zero elements
    double* values;
    int* col_indices;
    int* row_pointers;
} CSRMatrix;

CSRMatrix create_csr_matrix(int rows, int cols, int nnz);
void spmv_csr(CSRMatrix* matrix, double* input_vector, double* output_vector);
void free_csr_matrix(CSRMatrix* matrix);

#endif
