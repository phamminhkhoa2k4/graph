// include <stdio.h>
// include <stdlib.h>

#define MAX_N 100
#define MAX_M 500

typedef struct {
  int u, v, w;
} Edge;

typedef struct {
  int n, m;
  Edge edges[MAX_M];
} Graph;

void init_graph(Graph *g, int n) {
  g->n = n;
  g->m = 0;
}

void add_edge(Graph *g, int u, int v, int w) {
  if (g->m >= MAX_M) {
    printf("Too many edges.\n");
    return;
  }
  g->edges[g->m].u = u;
  g->edges[g->m].v = v;
  g->edges[g->m].w = w;
  g->m++;
}

int min_distance(int dist[], int n) {
  int min_index = -1, min_value = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (dist[i] < min_value && !visited[i]) {
      min_index = i;
      min_value = dist[i];
    }
  }
  return min_index;
}

void dijkstra(Graph *g, int n, int start) {
  int dist[n];
  bool visited[n];

  for (int i = 0; i < n; i++) {
    dist[i] = INT_MAX;
    visited[i] = false;
  }

  dist[start] = 0;

  for (int i = 0; i < n - 1; i++) {
    int u = min_distance(dist, n);
    visited[u] = true;

    for (int j = 0; j < g->m; j++) {
      if (g->edges[j].u == u && !visited[g->edges[j].v]) {
        int new_dist = dist[u] + g->edges[j].w;
        if (new_dist < dist[g->edges[j].v]) {
          dist[g->edges[j].v] = new_dist;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", dist[i]);
  }
}

int main() {
  // freopen("dt.txt", "r", stdin); //Bỏ dòng này khi nộp bài
  Graph G;
  int n, m, u, v, w;
  scanf("%d%d", &n, &m);
  init_graph(&G, n);

  for (int e = 0; e < m; e++) {
    scanf("%d%d%d", &u, &v, &w);
    add_edge(&G, u, v, w);
  }

  dijkstra(&G, n, 1);

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

// 6 9     20
// 1 2 7
// 1 3 9
// 1 5 14
// 2 3 10
// 2 4 15
// 3 4 11
// 3 5 2
// 4 6 6
// 5 6 9


