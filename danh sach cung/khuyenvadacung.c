// include <stdio.h>

#define MAX_EDGES 1000

typedef struct {
    int x, y;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_EDGES];
} Graph;

void init_graph(Graph* G, int n){
    G->n = n;
    G->m = 0;
}

int degree(Graph* G, int x) {
    int degree_count = 0;
    for (int i = 0; i < G->m; ++i) {
        if (G->edges[i].x == x || G->edges[i].y == x) {
            degree_count++;
        }
    }
    return degree_count;
}

int main() {
    Graph G;
    init_graph(&G, 5); // Khởi tạo đồ thị có 5 đỉnh
    G.m = 5; // Giả sử có 5 cung

    // Gán các cung
    G.edges[0].x = 0; G.edges[0].y = 1;
    G.edges[1].x = 0; G.edges[1].y = 2;
    G.edges[2].x = 1; G.edges[2].y = 2;
    G.edges[3].x = 1; G.edges[3].y = 3;
    G.edges[4].x = 2; G.edges[4].y = 4;

    // In bậc của mỗi đỉnh
    for (int i = 0; i < G.n; ++i) {
        printf("Degree of vertex %d: %d\n", i, degree(&G, i));
    }

    return 0;
}




// Cho cấu trúc dữ liệu đồ thị được cài đặt bằng phương pháp "Danh sách cung" như sau:

// typedef struct  {
// 	 int x, y;
// } Edge;
// typedef struct {
// 	int n, m;
// 	Edge edges[MAX_EDGES];
// } Graph;
// Các cung được lưu trong danh sách edges với chỉ số từ 0, 1, 2, ..., m-1

// Hàm khởi tạo đồ thị:

// void init_graph(Graph* G, int n){
// 	G->n = n;
// 	G->m = 0;
// }


// Giả sử đồ thị có thể chứa khuyên và đa cung.

// Viết hàm degree(Graph* G, int x) để tính bậc của đỉnh x.

// int degree(Graph* G, int x) {
// }
// Chú ý:

// - Bạn có thể viết thêm hàm nếu thấy cần thiết

// - Copy toàn bộ hàm degree dán vào ô trả lời