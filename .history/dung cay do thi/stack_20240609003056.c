// include <stdio.h>
// include <stdbool.h>
// include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int data[MAX_VERTICES];
    int size;
} Stack;

typedef struct {
    int data[MAX_VERTICES];
    int size;
} List;

typedef struct {
    int n;
    int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

void make_null_stack(Stack *S) {
    S->size = 0;
}

void push(Stack *S, int x) {
    S->data[S->size] = x;
    S->size++;
}

int top(Stack *S) {
    return S->data[S->size - 1];
}

void pop(Stack *S) {
    S->size--;
}

bool empty(Stack *S) {
    return S->size == 0;
}

void init_graph(Graph *G, int n) {
    G->n = n;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v) {
    G->A[u][v] = 1;
    G->A[v][u] = 1; // for undirected graph
}

int parent[MAX_VERTICES];

void depth_first_search(Graph *G, int s) {
    Stack frontier;
    make_null_stack(&frontier);
    push(&frontier, s);
    parent[s] = 0;

    while (!empty(&frontier)) {
        int u = top(&frontier);
        pop(&frontier);
        for (int v = 1; v <= G->n; v++) {
            if (G->A[u][v] == 1 && parent[v] == 0) {
                parent[v] = u;
                push(&frontier, v);
            }
        }
    }
}

int main() {
    //freopen("dt.txt", "r", stdin); // Remember to remove this line before submitting.
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (parent[i] == 0) {
            depth_first_search(&G, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i, parent[i]);
    }

    return 0;
}





// Cho một đồ thị vô hướng đơn. Hãy dựng (các) cây DUYỆT ĐỒ THỊ khi duyệt đồ thị theo chiều sâu (dùng NGĂN XẾP) bắt đầu từ đỉnh 1.

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
// Sử dụng 1 stack lưu các cặp <u, parent>. Khi xét đỉnh v (là kề của u) để đưa vào stack, ta đưa cả <v, u> vào stack. Lúc này u được xem như là parent của v.
// typedef struct {
//     int u;
//     int parent;
// } ELEMENT_TYPE;
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