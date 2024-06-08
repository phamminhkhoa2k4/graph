#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int n;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph* G, int n) {
    G->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G->adj[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int u, int v) {
    G->adj[u-1][v-1] = 1;
    G->adj[v-1][u-1] = 1;
}

void bfs(Graph* G, int start, int visited[]) {
    int queue[MAX_VERTICES], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int u = queue[front++];
        printf("%d\n", u + 1);
        for (int v = 0; v < G->n; v++) {
            if (G->adj[u][v] && !visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
            }
        }
    }
}

int main() {
    Graph G;
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    int visited[MAX_VERTICES] = {0};
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(&G, i, visited);
        }
    }

    return 0;
}

// Cho một đồ thị vô hướng đơn. Hãy in ra thứ tự của các đỉnh khi duyệt đồ thị theo chiều rộng bắt đầu từ đỉnh 1.

// Nếu đồ thị không liên thông, sau khi duyệt xong lần 1, tìm đỉnh có chỉ số nhỏ nhất chưa duyệt mà duyệt nó, và cứ tiếp tục như thế cho đến khi tất cả các đỉnh đều được duyệt.

// Quy ước:

// Các đỉnh kề của 1 đỉnh được liệt kê theo thứ tự tăng dần


// Đầu vào (Input):
// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

// - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng mô tả cung (u, v).

// Đầu ra (Output):

// In ra các đỉnh theo thứ tự duyệt, mỗi đỉnh trên 1 dòng.



// Xem thêm các ví dụ bên dưới.



// Hướng dẫn đọc dữ liệu và chạy thử chương trình

// Để chạy thử chương trình, bạn nên tạo một tập tin dt.txt chứa đồ thị cần kiểm tra.
// Thêm dòng freopen("dt.txt", "r", stdin); vào ngay sau hàm main(). Khi nộp bài, nhớ gỡ bỏ dòng này ra.
// Có thể sử dụng đoạn chương trình đọc dữ liệu mẫu sau đây:
// 	freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
// 	Graph G;
// 	int n, m, u, v, w, e;
// 	scanf("%d%d", &n, &m);
// 	init_graph(&G, n);
	
// 	for (e = 0; e < m; e++) {
// 		scanf("%d%d", &u, &v);
// 		add_edge(&G, u, v);
// 	}
