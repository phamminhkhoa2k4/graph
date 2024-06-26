
// include <stdio.h>
// include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph* G, int V) {
    G->V = V;
    int i, j;
    for (i = 1; i <= V; ++i) {
        for (j = 1; j <= V; ++j) {
            G->adj[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int u, int v) {
    G->adj[u][v] = 1;
}

bool is_cyclic_util(Graph* G, int v, bool visited[], bool rec_stack[]) {
    if (!visited[v]) {
        visited[v] = true;
        rec_stack[v] = true;

        int i;
        for (i = 1; i <= G->V; ++i) {
            if (G->adj[v][i]) {
                if (!visited[i] && is_cyclic_util(G, i, visited, rec_stack)) {
                    return true;
                } else if (rec_stack[i]) {
                    return true;
                }
            }
        }
    }
    rec_stack[v] = false;
    return false;
}

bool is_cyclic(Graph* G) {
    bool visited[MAX_VERTICES] = {false};
    bool rec_stack[MAX_VERTICES] = {false};

    int v;
    for (v = 1; v <= G->V; ++v) {
        if (is_cyclic_util(G, v, visited, rec_stack)) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.

    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; ++e) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    if (is_cyclic(&G)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}



// Cho G=<V, E> là một đồ thị vô hướng đơn (không có khuyên, không có đa cung). Hãy viết chương trình kiểm tra xem có chứa chu trình hay không.

// Chu trình là một đường đi đơn cung có đỉnh đầu trùng với đỉnh cuối.

// Đầu vào (Input):

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

// - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u, v mô tả cung (u, v).

// Đầu ra (Output):

// In ra màn hình YES nếu đồ thị có chứa chu trình, ngược lại in ra NO

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
// 3 2  
// 1 3
// 2 3
// NO
// 7 9
// 1 2
// 1 3
// 1 4
// 2 3
// 2 6
// 3 5
// 3 7
// 4 5
// 5 7
// YES
// 7 9
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 3 5
// 3 6
// 4 7
// 5 7
// YES
// 3 2
// 1 2
// 2 3
// NO
// 4 3
// 1 2
// 2 3
// 2 4
// NO
