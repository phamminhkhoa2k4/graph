// include <stdio.h>

typedef struct {
    int A[100][100];
    int n;
} Graph;

int deg(Graph* G, int x) {
    int degree = 0;
    for (int i = 0; i < G->n; i++) {
        if (G->A[x][i] == 1) {
            degree++;
        }
    }
    return degree;
}

int main() {
    Graph G;
    G.n = 5;
    int edges[5][2] = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}};
    // Initialize the adjacency matrix to 0
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            G.A[i][j] = 0;
        }
    }
    // Fill the adjacency matrix with the given edges
    for (int i = 0; i < 5; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        G.A[u][v] = 1;
        G.A[v][u] = 1;
    }
    int x = 1; // Change x to test different vertices (0-indexed)
    printf("Degree of vertex %d: %d\n", x + 1, deg(&G, x));
    return 0;
}




Cho cấu trúc dữ liệu đồ thị được khai báo sử dụng ma trận đỉnh - đỉnh như sau:

typedef struct {
    int A[100][100];
    int n;
} Graph;
Giả sử đồ thị vô hướng, không chứa khuyên, không chứa đa cung

Viết hàm int deg(Graph* G, int x) để tính bậc của đỉnh x.

int deg(Graph* G, int x) {
}