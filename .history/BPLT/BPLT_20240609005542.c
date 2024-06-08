// include <stdio.h>
// include <stdlib.h>

#define MAX_VERTICES 100 // Số lượng đỉnh tối đa
#define MAX_EDGES 100    // Số lượng cung tối đa

typedef struct {
    int n;                   // Số lượng đỉnh
    int m;                   // Số lượng cung
    int A[MAX_VERTICES][MAX_VERTICES];  // Ma trận kề
} Graph;

int visited[MAX_VERTICES];   // Mảng kiểm tra đỉnh đã thăm hay chưa

void init_graph(Graph *G, int n) {
    int i, j;
    G->n = n;
    G->m = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph *G, int u, int v) {
    G->A[u][v] = 1;  // Cung từ u đến v
}

void DFS(Graph *G, int u) {
    visited[u] = 1;  // Đánh dấu đỉnh u đã thăm
    for (int v = 1; v <= G->n; v++) {
        if (G->A[u][v] != 0 && visited[v] == 0)  // Kiểm tra nếu có cung từ u đến v và v chưa được thăm
            DFS(G, v);  // Tiến hành duyệt đỉnh v
    }
}

int count_strongly_connected_components(Graph *G) {
    int count = 0;  // Số lượng BPLTM
    for (int u = 1; u <= G->n; u++)
        visited[u] = 0;  // Khởi tạo tất cả các đỉnh chưa được thăm
    for (int u = 1; u <= G->n; u++) {
        if (visited[u] == 0) {
            DFS(G, u);  // Duyệt đỉnh u và các đỉnh kết nối với u
            count++;
        }
    }
    return count;
}

int main() {
    freopen("dt.txt", "r", stdin); // Đọc dữ liệu từ tệp dt.txt
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    int result = count_strongly_connected_components(&G);
    printf("%d\n", result);

    return 0;
}




// Viết chương trình đếm số bộ phận liên thông mạnh (BPLTM) của một đồ thị có hướng.

// Đầu vào (Input):

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

// - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u, v mô tả cung (u, v).

// Chú ý: đồ thị không chứa đa cung.

// Đầu ra (Output):

// In ra màn hình một con số nguyên duy nhất chỉ số BPTLM của đồ thị.

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
// 5 7     1
// 1 2
// 2 3
// 3 1
// 2 4
// 3 4
// 4 5
// 5 3
