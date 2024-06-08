// include <stdio.h>
// include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int data[MAX_VERTICES][MAX_VERTICES];
    int size;
} Graph;

void init_graph(Graph* G, int n) {
    G->size = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            G->data[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int u, int v) {
    G->data[u][v] = 1;
    G->data[v][u] = 1;
}

void dfs(Graph* G, int u, int parent[], bool visited[]) {
    visited[u] = true;
    for (int v = 1; v <= G->size; v++) {
        if (G->data[u][v] && !visited[v]) {
            parent[v] = u;
            dfs(G, v, parent, visited);
        }
    }
}

int main() {
    freopen("dt.txt", "r", stdin); // Remember to remove this line before submission

    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    int parent[MAX_VERTICES] = {0}; // Initialize all parent nodes to 0
    bool visited[MAX_VERTICES] = {false}; // Initialize all vertices as not visited

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(&G, i, parent, visited);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i, parent[i]);
    }

    return 0;
}






// Cho một đồ thị vô hướng đơn. Hãy dựng (các) cây DUYỆT ĐỒ THỊ khi duyệt đồ thị theo chiều sâu (dùng ĐỆ QUY) bắt đầu từ đỉnh 1.

// Nếu đồ thị không liên thông, sau khi duyệt xong lần 1, tìm đỉnh có chỉ số nhỏ nhất chưa duyệt mà duyệt nó, và cứ tiếp tục như thế cho đến khi tất cả các đỉnh đều được duyệt.

// Quy ước:

// Các đỉnh kề của 1 đỉnh được liệt kê theo thứ tự tăng dần.


// Đầu vào (Input):
// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

// - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng mô tả cung (u, v).

// Đầu ra (Output):

// In ra cây duyệt đồ thị theo định dạng:

// 1 <đỉnh cha của 1>
// 2 <đỉnh cha của 2>
// ....
// i <đỉnh cha của i>
// ...
// n <đỉnh cha của n>

// Quy ước: Nếu 1 đỉnh không có đỉnh cha (nó là đỉnh gốc của cây) thì đỉnh cha của nó là 0.

// Xem thêm các ví dụ bên dưới.



// Gợi ý:

// Sử dụng mảng parent[u] để lưu đỉnh cha của đỉnh u.
// Trong quá trình duyệt, thay vì in các đỉnh ra màn hình, ghi nhận lại đỉnh cha của các đỉnh.
// Thêm 1 tham số p (đỉnh cha của đỉnh u) cho hàm visit(). Khi gọi đệ quy duyệt v ta truyền u như là đỉnh cha của v.
// void visit(Graph* G, int u, int p) {
//     ...
//     for (các đỉnh kề v của u)
//         visit(G, v, u);
// }
// Khi duyệt xong lần lượt in ra u và parent[u] (u chạy từ 1 đến n).


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