#include <stdio.h>
#include <limits.h>

#define MAX_N 100
#define MAX_M 500

#define INF INT_MAX

struct Edge {
    int to, weight;
};

typedef struct {
    struct Edge edges[MAX_N][MAX_M];
    int edge_count[MAX_N];
} Graph;

void add_edge(Graph *graph, int u, int v, int w) {
    graph->edges[u][graph->edge_count[u]].to = v;
    graph->edges[u][graph->edge_count[u]].weight = w;
    graph->edge_count[u]++;
}

void dijkstra(const Graph *graph, int dist[], int start, int n) {
    int visited[MAX_N] = {0};
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_dist = INF;
        int min_index = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_index = j;
            }
        }

        if (min_index == -1) {
            break; // Nếu không tìm thấy đỉnh tiếp theo, thoát vòng lặp
        }

        visited[min_index] = 1;

        for (int j = 0; j < graph->edge_count[min_index]; j++) {
            int neighbor = graph->edges[min_index][j].to;
            int weight = graph->edges[min_index][j].weight;
            if (!visited[neighbor] && dist[min_index] != INF && dist[min_index] + weight < dist[neighbor]) {
                dist[neighbor] = dist[min_index] + weight;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    Graph G;
    for (int i = 0; i < MAX_N; i++) {
        G.edge_count[i] = 0;
    }

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u - 1, v - 1, w); // Giảm 1 đơn vị để index từ 0
    }

    int dist[MAX_N];
    dijkstra(&G, dist, 0, n); // Tìm đường đi ngắn nhất từ đỉnh 1 (index 0) đến n (index n-1)

    if (dist[n - 1] == INF)
        printf("-1\n");
    else
        printf("%d\n", dist[n - 1]);

    return 0;
}


// Cho đồ thị có hướng G = <V, E> có n đỉnh và m cung (n < 100, m < 500). Mỗi cung được gán một trọng số w (0 < w <= 100).

// Viết chương trình tìm đường đi ngắn nhất từ đỉnh 1 đến n.

// Đầu vào (Input):

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m.

// - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả cung (u, v) có trọng số w.

// Đầu ra (Output):

// In ra màn hình chiều dài của đường đi ngắn nhất từ 1 đến n. Nếu không có đường đi từ 1 đến n, in ra -1.

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
// 		scanf("%d%d%d", &u, &v, &c);
// 		add_edge(&G, u, v, w);
// 	}




// For example:

// Input	Result
// 3 3     4
// 1 2 9
// 2 3 4
// 1 3 4

// 3 1     -1
// 1 2 5

// 6 9         20
// 1 2 7
// 1 3 9
// 1 5 14
// 2 3 10
// 2 4 15
// 3 4 11
// 3 5 2
// 4 6 6
// 5 6 9

