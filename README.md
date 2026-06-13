# MatrixSparse-PageRank

A clean-room implementation of the PageRank algorithm optimized using a **Compressed Sparse Row (CSR)** matrix data structure in pure C99. This engine is designed to handle large, sparse connection networks (like neural structures or web graphs) without wasting memory on empty elements ($0$).

## 🧮 Mathematical & DSA Foundations
* **Matrix Layout:** Compresses an $N \times N$ matrix into three flat 1D arrays (`values`, `column_indices`, `row_pointers`).
* **Memory Optimization:** Reduces space complexity from $O(N^2)$ to $O(NNZ)$, where $NNZ$ is the number of non-zero links.
* **Power Iteration:** Computes stationary probability distributions via recursive Markov Chain tracking.

## 📦 Compilation & Execution
```bash
gcc main.c sparse.c pagerank.c -o sparse_pagerank -lm
./sparse_pagerank
