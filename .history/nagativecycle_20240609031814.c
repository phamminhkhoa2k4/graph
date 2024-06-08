#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct {
    int u, v;
    int weight;
} Edge;

typedef struct {
    int num_vertices, num_edges;
    Edge edges[MAX_EDGES];
} Graph;

Graph G;
int dist[MAX_VERTICES];

void init_graph(Graph *G, int num_vertices) {
    G->num_vertices = num_vertices;
    G->num_edges = 0;
}

void add_edge(Graph *G, int u, int v, int weight) {
    G->edges[G->num_edges].u = u;
    G->edges[G->num_edges].v = v;
    G->edges[G->num_edges].weight = weight;
    G->num_edges++;
}

void bellman_ford(int source) {
    int i, j;

    // Khởi tạo các khoảng cách ban đầu
    for (i = 1; i <= G.num_vertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Relax các cạnh để tìm đường đi ngắn nhất
    for (i = 1; i <= G.num_vertices - 1; i++) {
        for (j = 0; j < G.num_edges; j++) {
            int u = G.edges[j].u;
            int v = G.edges[j].v;
            int weight = G.edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Kiểm tra xem có chu trình âm hay không
    for (j = 0; j < G.num_edges; j++) {
        int u = G.edges[j].u;
        int v = G.edges[j].v;
        int weight = G.edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("negative cycle\n");
            return;
        }
    }

    printf("ok\n");
}

int main() {
    freopen("dt.txt", "r", stdin); // Bỏ dòng này khi nộp bài
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    // Chạy thuật toán Bellman-Ford từ mỗi đỉnh
    for (u = 1; u <= G.num_vertices; u++) {
        bellman_ford(u);
    }

    return 0;
}



// Viết chương trình kiểm tra một đồ thị có hướng (không có khuyên, không có đa cung) xem có chứa chu trình âm hay không.

// Chu trình âm là chu trình có tổng trọng số các cung trong chu trình nhỏ hơn 0.

// Đầu vào (Input):

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

// - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u, v, w mô tả cung (u, v) có trọng số w.

// Đầu ra (Output):

// In ra màn hình negative cycle nếu đồ thị có chứa chu trình âm, ngược lại in ra ok

// Xem thêm ví dụ bên dưới.

// Chú ý:

// Để chạy thử chương trình, bạn nên tạo một tập tin dt.txt chứa đồ thị cần kiểm tra.
// Thêm dòng freopen("dt.txt", "r", stdin); vào ngay sau hàm main(). Khi nộp bài, nhớ gỡ bỏ dòng này ra.
// Có thể sử dụng đoạn chương trình đọc dữ liệu mẫu sau đây:
// 	freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
// 	Graph G;
// 	int n, m, u, v, w, e;
// 	scanf("%d%d", &n, &m);
// 	init_graph(&G, n);
	
// 	for (e = 0; e < m; e++) {
// 		scanf("%d%d%d", &u, &v, &w);
// 		add_edge(&G, u, v, w);
// 	}




// For example:

// Input	Result
// 3 2  
// 1 3 1
// 3 1 1
// ok
// 7 10
// 1 2 1
// 1 3 1
// 1 4 1
// 2 3 1
// 2 6 1
// 3 7 1
// 4 5 1
// 5 3 1
// 5 7 1
// 3 1 1
// ok
// 7 12
// 1 2 1
// 1 3 1
// 2 4 1
// 2 5 1
// 2 6 1
// 3 2 1
// 3 5 1
// 3 6 1
// 4 7 1
// 5 7 1
// 6 4 1
// 2 1 1
// ok
// 3 3
// 1 2 4
// 2 3 -10
// 3 1 2
// negative cycle
// 3 3
// 1 2 1
// 2 3 1
// 3 1 1
// ok