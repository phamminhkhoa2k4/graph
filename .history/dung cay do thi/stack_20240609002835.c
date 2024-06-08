#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int data[MAX_VERTICES];
    int size;
} Stack;

typedef struct {
    int data[MAX_VERTICES];
    int size;
} List;

typedef struct {
    int n;
    int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

void make_null_stack(Stack *S) {
    S->size = 0;
}

void push(Stack *S, int x) {
    S->data[S->size] = x;
    S->size++;
}

int top(Stack *S) {
    return S->data[S->size - 1];
}

void pop(Stack *S) {
    S->size--;
}

bool empty(Stack *S) {
    return S->size == 0;
}

void init_graph(Graph *G, int n) {
    G->n = n;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v) {
    G->A[u][v] = 1;
    G->A[v][u] = 1; // for undirected graph
}

int parent[MAX_VERTICES];

void depth_first_search(Graph *G, int s) {
    Stack frontier;
    make_null_stack(&frontier);
    push(&frontier, s);
    parent[s] = 0;

    while (!empty(&frontier)) {
        int u = top(&frontier);
        pop(&frontier);
        for (int v = 1; v <= G->n; v++) {
            if (G->A[u][v] == 1 && parent[v] == 0) {
                parent[v] = u;
                push(&frontier, v);
            }
        }
    }
}

int main() {
    freopen("dt.txt", "r", stdin); // Remember to remove this line before submitting.
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (parent[i] == 0) {
            depth_first_search(&G, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i, parent[i]);
    }

    return 0;
}
