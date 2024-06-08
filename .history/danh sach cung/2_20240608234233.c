// include <stdio.h>

#define MAX_EDGES 100  // Giả sử giới hạn tối đa số cung là 100

typedef struct {
    int x, y;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_EDGES];
} Graph;

// Hàm khởi tạo đồ thị
void init_graph(Graph* G, int n){
    G->n = n;
    G->m = 0;
}

// Hàm thêm cung vào đồ thị
void add_edge(Graph* G, int x, int y) {
    // Kiểm tra tính hợp lệ của cung
    if (x < 1 || x > G->n || y < 1 || y > G->n) {
        // Nếu cung không hợp lệ, không làm gì cả
        return;
    }

    // Thêm cung vào danh sách cung
    G->edges[G->m].x = x;
    G->edges[G->m].y = y;
    G->m++;  // Tăng số lượng cung trong đồ thị
}

int main() {
    Graph G;
    init_graph(&G, 5);  // Khởi tạo đồ thị với 5 đỉnh

    add_edge(&G, 1, 2);  // Thêm cung (1, 2)
    add_edge(&G, 2, 3);  // Thêm cung (2, 3)
    add_edge(&G, 5, 6);  // Cung không hợp lệ, không được thêm
    add_edge(&G, 4, 5);  // Thêm cung (4, 5)

    // In ra các cung trong đồ thị
    for (int i = 0; i < G.m; i++) {
        printf("Edge %d: (%d, %d)\n", i, G.edges[i].x, G.edges[i].y);
    }

    return 0;
}


Cho cấu trúc dữ liệu đồ thị được cài đặt bằng phương pháp "Danh sách cung" như sau:

typedef struct  {
	 int x, y;
} Edge;
typedef struct {
	int n, m;
	Edge edges[MAX_EDGES];
} Graph;
Các cung được lưu trong danh sách edges với chỉ số từ 0, 1, 2, ..., m-1

Hàm khởi tạo đồ thị:

void init_graph(Graph* G, int n){
	G->n = n;
	G->m = 0;
}


Viết hàm add_edge(Graph* G, int x, int y) để thêm cung (x, y) vào đồ thị G.

void add_edge(Graph* G, int x, int y) {
}
Chú ý:

- Nếu cung (x, y) không hợp lệ (vd: x < 1, y > n, ...) thì bỏ qua không làm gì cả.