#include <stdio.h>
#include <stdlib.h>
#include "sparse.h"

extern void run_power_iteration(CSRMatrix* transition_matrix, double* rank_vector, int max_epochs, double damping);

int main() {
    printf("🕸️  Initializing MatrixSparse-PageRank Engine...\n\n");

    int total_nodes = 3;
    int non_zero_elements = 4;
    CSRMatrix web_graph = create_csr_matrix(total_nodes, total_nodes, non_zero_elements);

    // Representing a transition link setup using explicit CSR configurations
    web_graph.values[0] = 0.5;  web_graph.col_indices[0] = 1;
    web_graph.values[1] = 0.5;  web_graph.col_indices[1] = 2;
    web_graph.values[2] = 1.0;  web_graph.col_indices[2] = 0;
    web_graph.values[3] = 1.0;  web_graph.col_indices[3] = 1;

    web_graph.row_pointers[0] = 0;
    web_graph.row_pointers[1] = 2; // Node 0 points to 1 and 2
    web_graph.row_pointers[2] = 3; // Node 1 points to 0
    web_graph.row_pointers[3] = 4; // Node 2 points to 1

    double analytical_ranks[3] = {0.333, 0.333, 0.333}; // Uniform initial distribution probability vector

    run_power_iteration(&web_graph, analytical_ranks, 20, 0.85);

    printf("✨ Stationary Probability Vectors Calculated:\n");
    for(int i = 0; i < total_nodes; i++) {
        printf("   • Node ID [%d] -> Computed Centrality Probability Value: %.4f\n", i, analytical_ranks[i]);
    }

    free_csr_matrix(&web_graph);
    return 0;
}
