// include <stdio.h>

typedef struct {
    int A[100][500];
    int n, m;
} Graph;

void add_edge(Graph* G, int e, int x, int y) {
    // Kiểm tra x và y có hợp lệ không
    if (x < 0 || x >= G->n || y < 0 || y >= G->n) {
        printf("Invalid vertices\n");
        return;
    }

    // Kiểm tra cung đã tồn tại chưa
    if (G->A[x][y] == 1 || G->A[y][x] == 1) {
        printf("Edge already exists\n");
        return;
    }

    // Thêm cung vào đồ thị
    G->A[x][y] = 1;
    G->A[y][x] = 1;

    // Tăng số lượng cung m của đồ thị lên
    G->m++;
}

int main() {
    // Khởi tạo đồ thị G
    Graph G;
    G.n = 5; // Số đỉnh của đồ thị
    G.m = 0; // Số cung ban đầu là 0

    // Khởi tạo ma trận đỉnh - cung
    for (int i = 0; i < G.n; i++) {
        for (int j = 0; j < G.n; j++) {
            G.A[i][j] = 0; // Khởi tạo ma trận ban đầu với các giá trị 0
        }
    }

    // Thêm các cung vào đồ thị
    add_edge(&G, 1, 0, 1);
    add_edge(&G, 2, 1, 2);
    add_edge(&G, 3, 2, 3);
    add_edge(&G, 4, 3, 4);
    add_edge(&G, 5, 4, 0);

    // In ra ma trận đỉnh - cung của đồ thị
    printf("Ma tran dinh - cung cua do thi:\n");
    for (int i = 0; i < G.n; i++) {
        for (int j = 0; j < G.n; j++) {
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
