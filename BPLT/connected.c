// include <stdio.h>
// include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void init_graph(Graph *G, int num_vertices) {
    G->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            G->matrix[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v) {
    G->matrix[u - 1][v - 1] = 1;
}

void dfs(Graph *G, int v, bool visited[]) {
    visited[v] = true;
    for (int i = 0; i < G->num_vertices; i++) {
        if (G->matrix[v][i] && !visited[i]) {
            dfs(G, i, visited);
        }
    }
}

bool is_strong_connected(Graph *G) {
    bool visited[MAX_VERTICES] = {false};
    dfs(G, 0, visited);
    // Kiểm tra xem tất cả các đỉnh đã được duyệt qua hay không
    for (int i = 0; i < G->num_vertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    // Reset visited array để thực hiện DFS từ một đỉnh ngẫu nhiên
    for (int i = 0; i < G->num_vertices; i++) {
        visited[i] = false;
    }
    dfs(G, G->num_vertices - 1, visited);
    // Kiểm tra xem tất cả các đỉnh đã được duyệt qua hay không
    for (int i = 0; i < G->num_vertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    if (is_strong_connected(&G)) {
        printf("strong connected\n");
    } else {
        printf("unconnected\n");
    }

    return 0;
}


// Viết chương trình kiểm tra xem một đồ thị có hướng có liên thông mạnh không.

// Đầu vào (Input):

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

// - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u, v mô tả cung (u, v).

// Chú ý: đồ thị không chứa đa cung.

// Đầu ra (Output):

// In ra màn hình strong connected nếu đồ thị đã cho liên thông mạnh, ngược lại in ra unconnected.

// Xem thêm ví dụ bên dưới.



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


// For example:

// Input	Result
// 5 7
// 1 2
// 2 3
// 3 1
// 2 4
// 3 4
// 4 5
// 5 3
// strong connected
