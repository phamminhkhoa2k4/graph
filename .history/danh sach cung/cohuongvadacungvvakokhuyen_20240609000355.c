
void add_edge(Graph* G, int x, int y) {
    if (x < 0 || x >= G->n || y < 0 || y >= G->n) {
        printf("Invalid vertex\n");
        return;
    }
    G->A[x][y]++;
}



// Cho cấu trúc dữ liệu Đồ thị (Graph) được khai báo sử dụng ma trận đỉnh - đỉnh như sau:

// typedef struct {
//     int A[100][100];
//     int m, n;
// } Graph;
// Giả sử đồ thị là đồ thị có hướng, có đa cung nhưng không có khuyên.

// Để biểu diễn đa cung, phần tử A[u][v] lưu trữ số cung từ đỉnh u đến đỉnh v.

// Viết hàm add_edge(Graph* G, int x, int y) để thêm cung (x, y) vào đồ thị G.

// void add_edge(Graph* G, int x, int y)  {
// }
// Hãy copy toàn bộ hàm add_edge dán vào ô trả lời.

// For example:

// Test	Result
// add_edge(&G, 1, 2);
// add_edge(&G, 1, 3);
// add_edge(&G, 3, 4);
// add_edge(&G, 3, 4);
// 0 1 1 0 
// 0 0 0 0 
// 0 0 0 2 
// 0 0 0 0 
// add_edge(&G, 1, 2);
// add_edge(&G, 2, 1);
// add_edge(&G, 3, 4);
// add_edge(&G, 2, 1);
// 0 1 0 0 
// 2 0 0 0 
// 0 0 0 1 
// 0 0 0 0 
