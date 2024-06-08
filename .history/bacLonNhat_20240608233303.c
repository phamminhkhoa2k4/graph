#include <stdio.h>

#define MAX_VERTICES 1000

typedef struct {
    int edges[MAX_VERTICES][MAX_VERTICES];
    int n; // số đỉnh
    int m; // số cạnh
} Graph;

void init_graph(Graph *G, int n) {
    G->n = n;
    G->m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G->edges[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v) {
    if (G->edges[u-1][v-1] == 0 && G->edges[v-1][u-1] == 0) {
        G->edges[u-1][v-1] = 1;
        G->edges[v-1][u-1] = 1;
        G->m++;
    }
}

int degree(Graph *G, int u) {
    int deg = 0;
    for (int v = 0; v < G->n; v++) {
        if (G->edges[u-1][v] == 1) {
            deg++;
        }
    }
    return deg;
}

int main() {
    // freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    
    Graph G;
    int n, m, u, v;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for (int e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    int max_degree = -1;
    int vertex_with_max_degree = -1;
    
    for (int i = 1; i <= n; i++) {
        int deg = degree(&G, i);
        if (deg > max_degree || (deg == max_degree && i < vertex_with_max_degree)) {
            max_degree = deg;
            vertex_with_max_degree = i;
        }
    }
    
    printf("%d %d\n", vertex_with_max_degree, max_degree);
    
    return 0;
}
