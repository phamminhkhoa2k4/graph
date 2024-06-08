
// Cho cấu trúc dữ liệu đồ thị được khai báo sử dụng ma trận đỉnh - cung như sau:

typedef struct {
    int A[100][500];
    int n, m;
} Graph;
Giả sử đồ thị vô hướng, không chứa khuyên.

Viết hàm add_edge(Graph* G, int e, int x, int y) để thêm cung e = (x, y) vào đồ thị G.

void add_edge(Graph* G, int e, int x, int y) {
}
// Ma trận đỉnh - cung (add_edge)
void add_edge(Graph* G, int e, int x, int y) {
    // Đảm bảo các giá trị x và y nằm trong phạm vi hợp lệ của đồ thị
    if (x >= 0 && x < G->n && y >= 0 && y < G->n && e >= 0 && e < G->m) {
        // Thêm cung e vào giữa đỉnh x và y
        G->A[x][e] = 1;
        G->A[y][e] = 1;
    }
}
