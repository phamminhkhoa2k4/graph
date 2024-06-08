#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int data[MAX_VERTICES];
    int size;
} Stack;

void make_null_stack(Stack *stack) {
    stack->size = 0;
}

void push(Stack *stack, int value) {
    stack->data[stack->size] = value;
    stack->size++;
}

int top(Stack *stack) {
    return stack->data[stack->size - 1];
}

void pop(Stack *stack) {
    stack->size--;
}

typedef struct {
    int n;
    int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph *graph, int n) {
    graph->n = n;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            graph->A[i][j] = 0;
        }
    }
}

void add_edge(Graph *graph, int u, int v) {
    graph->A[u][v] = 1;
    graph->A[v][u] = 1;
}

bool visited[MAX_VERTICES];

void depth_first_search(Graph *graph, int start) {
    Stack stack;
    make_null_stack(&stack);

    make_null_stack(&stack);
    push(&stack, start);
    visited[start] = true;

    while (stack.size > 0) {
        int u = top(&stack);
        pop(&stack);
        printf("%d\n", u);

        int v;
        for (v = 1; v <= graph->n; v++) {
            if (graph->A[u][v] == 1 && !visited[v]) {
                push(&stack, v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            depth_first_search(&G, i);
        }
    }

    return 0;
}




// Cho một đồ thị vô hướng đơn. Hãy in ra thứ tự của các đỉnh khi duyệt đồ thị theo chiều sâu (sử dụng NGĂN XẾP) bắt đầu từ đỉnh 1.

// Nếu đồ thị không liên thông, sau khi duyệt xong lần 1, tìm đỉnh có chỉ số nhỏ nhất chưa duyệt mà duyệt nó, và cứ tiếp tục như thế cho đến khi tất cả các đỉnh đều được duyệt.

// Quy ước:

// Các đỉnh kề của 1 đỉnh được liệt kê theo thứ tự tăng dần.


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