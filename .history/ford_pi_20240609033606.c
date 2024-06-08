#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500
#define INF 9999

// Định nghĩa cấu trúc đồ thị
typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_EDGES];
} Graph;

// Khởi tạo đồ thị
void init_graph(Graph *G, int n) {
    G->n = n;
    G->m = 0;
}

// Thêm cung vào đồ thị
void add_edge(Graph *G, int u, int v, int w) {
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].w = w;
    G->m++;
}

// Thuật toán Dijkstra
void Dijkstra(Graph *G, int s, int pi[], int p[]) {
    int i, j;
    bool S[MAX_VERTICES];
    for (i = 1; i <= G->n; i++) {
        pi[i] = INF;
        p[i] = -1;
        S[i] = false;
    }
    pi[s] = 0;

    for (j = 1; j <= G->n; j++) {
        int min_pi = INF;
        int u = -1;
        for (i = 1; i <= G->n; i++) {
            if (!S[i] && pi[i] < min_pi) {
                min_pi = pi[i];
                u = i;
            }
        }
        if (u == -1) break;
        S[u] = true;

        for (i = 0; i < G->m; i++) {
            if (G->edges[i].u == u) {
                int v = G->edges[i].v;
                int w = G->edges[i].w;
                if (pi[u] + w < pi[v]) {
                    pi[v] = pi[u] + w;
                    p[v] = u;
                }
            }
        }
    }
}

int main() {
    // freopen("dt.txt", "r", stdin); // Bỏ comment khi nộp bài
    Graph G;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for (e = 0; e < m; e++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    int pi[MAX_VERTICES], p[MAX_VERTICES];
    for (int i = 1; i <= n; i++) {
        Dijkstra(&G, i, pi, p);
        printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
    }

    return 0;
}
