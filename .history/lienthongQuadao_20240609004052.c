#include <stdio.h>
#include <stdbool.h>

#define MAXN 10000
#define MAXM 10000

// Khai báo cấu trúc đỉnh của đồ thị
struct Node {
    int data;
    struct Node* next;
};

// Khai báo cấu trúc danh sách liên kết
struct LinkedList {
    struct Node* head;
};

// Hàm khởi tạo danh sách liên kết
void initList(struct LinkedList* list) {
    list->head = NULL;
}

// Hàm thêm một đỉnh vào danh sách liên kết
void addEdge(struct LinkedList* adj_list, int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj_list[u].head;
    adj_list[u].head = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = u;
    newNode->next = adj_list[v].head;
    adj_list[v].head = newNode;
}

// Hàm DFS để duyệt đồ thị
void DFS(struct LinkedList* adj_list, int u, bool visited[]) {
    visited[u] = true;
    struct Node* temp = adj_list[u].head;
    while (temp != NULL) {
        int v = temp->data;
        if (!visited[v]) {
            DFS(adj_list, v, visited);
        }
        temp = temp->next;
    }
}

// Hàm kiểm tra tính liên thông của đồ thị
bool isConnected(int n, struct LinkedList* adj_list) {
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    DFS(adj_list, 0, visited);

    // Kiểm tra xem tất cả các đỉnh có được duyệt hay không
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct LinkedList adj_list[MAXN];
    for (int i = 0; i < n; i++) {
        initList(&adj_list[i]);
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj_list, u - 1, v - 1);
    }

    if (isConnected(n, adj_list)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}




// Có n hòn đảo và m cây cầu. Mỗi cây cầu bắt qua 2 hòn đảo. Một hôm chúa đảo tự hỏi là với các cây cầu hiện tại thì đứng ở một hòn đảo bất kỳ có thể nào đi đến được tất cả các hòn đảo khác hay không.

// Hãy giúp chúa đảo viết chương trình kiểm tra.

// Đầu vào (Input):

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đảo và số cây cầu.

// - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng có 1 cây cầu bắt qua hai hòn đảo u và v.

// Đầu ra (Output):

// Nếu có thể đi được in ra màn hình YES, ngược lại in ra NO.

// Xem thêm ví dụ bên dưới.

// For example:

// Input	Result
// 4 3     YES
// 1 2
// 2 3
// 3 4

// 4 2      NO
// 3 4
// 1 2

