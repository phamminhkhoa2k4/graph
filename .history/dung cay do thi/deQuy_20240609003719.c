// include <stdio.h>
// include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int data[MAX_VERTICES][MAX_VERTICES];
    int size;
} Graph;

void init_graph(Graph* G, int n) {
    G->size = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            G->data[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int u, int v) {
    G->data[u][v] = 1;
    G->data[v][u] = 1;
}

void dfs(Graph* G, int u, int parent[], bool visited[]) {
    visited[u] = true;
    for (int v = 1; v <= G->size; v++) {
        if (G->data[u][v] && !visited[v]) {
            parent[v] = u;
            dfs(G, v, parent, visited);
        }
    }
}

int main() {
    freopen("dt.txt", "r", stdin); // Remember to remove this line before submission

    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    int parent[MAX_VERTICES] = {0}; // Initialize all parent nodes to 0
    bool visited[MAX_VERTICES] = {false}; // Initialize all vertices as not visited

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(&G, i, parent, visited);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i, parent[i]);
    }

    return 0;
}
