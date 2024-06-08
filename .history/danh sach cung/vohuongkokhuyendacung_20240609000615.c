typedef struct {
    int A[100][100];
    int n;
} Graph;

int edgeCount(Graph* G) {
    int count = 0;
    for (int i = 0; i < G->n; i++) {
        for (int j = 0; j < G->n; j++) {
            if (G->A[i][j] != 0) {
                count++;
            }
        }
    }
    // Vì đồ thị vô hướng nên ta cần chia 2 cho số cung để loại bỏ việc đếm cung lặp lại
    return count / 2;
}




// Cho cấu trúc dữ liệu đồ thị được khai báo sử dụng ma trận đỉnh - đỉnh như sau:

// typedef struct {
//     int A[100][100];
//     int n;
// } Graph;
// Giả sử đồ thị vô hướng, không chứa khuyên, nhưng có chứa đa cung

// Viết hàm int edgeCount(Graph* G) để đếm số cung của đồ thị G.

// int edgeCount(Graph* G) {
// }


// For example:

// Input	Result
// 4       7
// 0 2 1 0 
// 2 0 3 0 
// 1 3 0 1 
// 0 0 1 0

