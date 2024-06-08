// include <stdio.h>

#define MAX_EDGES 100

typedef struct  {
    int x, y;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_EDGES];
} Graph;

void init_graph(Graph* G, int n) {
    G->n = n;
    G->m = 0;
}

void add_edge(Graph* G, int x, int y) {
    // Tạo một cung mới
    Edge e;
    e.x = x;
    e.y = y;

    // Thêm cung mới vào danh sách cung của đồ thị
    G->edges[G->m] = e;

    // Tăng số lượng cung của đồ thị
    G->m++;
}

int main() {
    Graph G;
    init_graph(&G, 5); // Khởi tạo đồ thị với 5 đỉnh

    add_edge(&G, 1, 2); // Thêm cung (1, 2)
    add_edge(&G, 2, 3); // Thêm cung (2, 3)
    add_edge(&G, 4, 5); // Thêm cung (4, 5)

    // In các cung của đồ thị
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