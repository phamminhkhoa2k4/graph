#include <stdio.h>

#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
    ElementType data[MAX_ELEMENTS];
    int size;
} List;

/* Tao danh sach rong */
void make_null(List* L) {
    L->size = 0;
}

/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
    L->data[L->size] = x;
    L->size++;
}

/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List* L, int i) {
    return L->data[i-1];
}

/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
    return L->size;
}

/* Sap xep danh sach */
void sort_list(List* L) {
    for (int i = 0; i < L->size - 1; i++) {
        for (int j = i + 1; j < L->size; j++) {
            if (L->data[i] > L->data[j]) {
                int temp = L->data[i];
                L->data[i] = L->data[j];
                L->data[j] = temp;
            }
        }
    }
}

/* Loai bo cac phan tu trung lap trong danh sach */
void unique_list(List* L) {
    int unique_size = 0;
    for (int i = 0; i < L->size; i++) {
        if (i == 0 || L->data[i] != L->data[i - 1]) {
            L->data[unique_size] = L->data[i];
            unique_size++;
        }
    }
    L->size = unique_size;
}

typedef struct {
    int A[100][500];
    int n, m;
} Graph;

void List_neighbors(Graph* G, int x, List* L) {
    make_null(L);
    for (int i = 0; i < G->m; i++) {
        if (G->A[x][i] == 1) {
            for (int j = 0; j < G->n; j++) {
                if (G->A[j][i] == 1 && j != x) {
                    push_back(L, j);
                }
            }
        }
    }
    sort_list(L);
    unique_list(L);
}

int main() {
    Graph G;
    G.n = 5; // Số đỉnh
    G.m = 5; // Số cạnh
    
    // Giả sử đây là ma trận đỉnh - cung của đồ thị
    int matrix[5][5] = {
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    // Copy ma trận vào cấu trúc đồ thị
    for (int i = 0; i < G.n; i++) {
        for (int j = 0; j < G.m; j++) {
            G.A[i][j] = matrix[i][j];
        }
    }

    List neighbors;
    List_neighbors(&G, 2, &neighbors);

    // In danh sách các đỉnh kề của đỉnh 2
    for (int i = 1; i <= count_list(&neighbors); i++) {
        printf("%d ", element_at(&neighbors, i));
    }

    return 0;
}






















// Cho cấu trúc dữ liệu đồ thị được khai báo sử dụng ma trận đỉnh - cung như sau:

// typedef struct {
//     int A[100][500];
//     int n, m;
// } Graph;
// Giả sử đồ thị không chứa khuyên.

// Viết hàm List neighbors(Graph* G, int x) trả về danh sách các đỉnh kề của x.

// Chú ý: các đỉnh kề của x được sắp xếp theo thứ tự tăng dần và không trùng nhau. Ví dụ: nếu các đỉnh kề của 1 là 4 và 2 thì danh sách trả về chứa: 2 và 4.

// Cấu trúc dữ liệu List được định nghĩa như bên dưới:

// #define MAX_ELEMENTS 100
// typedef int ElementType;
// typedef struct {
// ElementType data[MAX_ELEMENTS];
// int size;
// } List;
// /* Tao danh sach rong */
// void make_null(List* L) {
// L->size = 0;
// }
// /* Them mot phan tu vao cuoi danh sach */
// void push_back(List* L, ElementType x) {
// L->data[L->size] = x;
// L->size++;
// }
// /* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
// ElementType element_at(List* L, int i) {
// return L->data[i-1];
// }
// /* Tra ve so phan tu cua danh sach */
// int count_list(List* L) {
// return L->size;
// }
