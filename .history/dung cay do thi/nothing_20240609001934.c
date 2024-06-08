#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100005

// Định nghĩa cấu trúc đồ thị
typedef struct {
    int data[MAX];
    int size;
} List;

List* makeList() {
    List* lst = (List*)malloc(sizeof(List));
    lst->size = 0;
    return lst;
}

void add(List* lst, int value) {
    lst->data[lst->size++] = value;
}

typedef struct {
    List* adj[MAX];
    int parent[MAX];
} Graph;

// Khởi tạo đồ thị
void init_graph(Graph* G, int n) {
    for (int i = 1; i <= n; i++) {
        G->adj[i] = makeList();
        G->parent[i] = 0;
    }
}

// Thêm cạnh vào đồ thị
void add_edge(Graph* G, int u, int v) {
    add(G->adj[u], v);
    add(G->adj[v], u);
}

// Duyệt đồ thị theo chiều rộng
void BFS(Graph* G, int start) {
    bool visited[MAX] = {false};
    int queue[MAX], front = 0, rear = -1;

    visited[start] = true;
    G->parent[start] = 0;
    queue[++rear] = start;

    while (front <= rear) {
        int u = queue[front++];
        for (int i = 0; i < G->adj[u]->size; i++) {
            int v = G->adj[u]->data[i];
            if (!visited[v]) {
                visited[v] = true;
                G->parent[v] = u;
                queue[++rear] = v;
            }
        }
    }
}

int main() {
    // freopen("dt.txt", "r", stdin); // Bỏ comment khi test local, nhớ xóa khi submit
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    BFS(&G, 1); // Bắt đầu duyệt từ đỉnh 1

    // In ra cây duyệt đồ thị
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i, G.parent[i]);
    }

    return 0;
}


// Cho một đồ thị vô hướng đơn. Hãy dựng (các) cây DUYỆT ĐỒ THỊ khi duyệt đồ thị theo chiều rộng bắt đầu từ đỉnh 1.

// Nếu đồ thị không liên thông, sau khi duyệt xong lần 1, tìm đỉnh có chỉ số nhỏ nhất chưa duyệt mà duyệt nó, và cứ tiếp tục như thế cho đến khi tất cả các đỉnh đều được duyệt.

// Quy ước:

// Các đỉnh kề của 1 đỉnh được liệt kê theo thứ tự tăng dần


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
