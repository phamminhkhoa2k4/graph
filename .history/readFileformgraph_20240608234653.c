// include <stdio.h>
// include <stdlib.h>

#define MAX_VERTICES 100

void readGraph(const char *filePath, int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int *n, int *m) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filePath);
        exit(1);
    }

    fscanf(file, "%d %d", n, m);

    // Initialize adjacency matrix with 0
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    // Read edges and update the adjacency matrix
    for (int i = 0; i < *m; i++) {
        int u, v;
        fscanf(file, "%d %d", &u, &v);
        // Convert to 0-based index
        u--;
        v--;
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }

    fclose(file);
}

void printAdjacencyMatrix(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    const char *filePath = "dt1.txt";
    readGraph(filePath, adjacencyMatrix, &n, &m);
    printAdjacencyMatrix(adjacencyMatrix, n);

    return 0;
}
