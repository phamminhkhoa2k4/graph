// include <stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500

typedef struct {
    int A[MAX_VERTICES][MAX_VERTICES];
    int n, m;
} Graph;

void init_graph(Graph* G, int n) {
    G->n = n;
    G->m = 0;
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph* G, int e, int x, int y) {
    G->A[x][y] = e;
}

int degree(Graph* G, int x) {
    int y, deg = 0;
    for (y = 1; y <= G->n; y++)
        if (G->A[x][y] > 0)
            deg++;
    return deg;
}

void get_adjacent_vertices(Graph* G, int x, int* adj_vertices, int* n_adj) {
    int y;
    *n_adj = 0;
    for (y = 1; y <= G->n; y++)
        if (G->A[x][y] > 0)
            adj_vertices[(*n_adj)++] = y;
}

int has_common_enemy(Graph* G, int x, int y) {
    int i;
    for (i = 1; i <= G->n; i++)
        if (G->A[x][i] == 1 && G->A[y][i] == 1)
            return 1;
    return 0;
}

void find_common_enemies(Graph* G, int x, int y) {
    int i, j;
    int common_enemies[MAX_VERTICES];
    int n_common = 0;

    for (i = 1; i <= G->n; i++) {
        if (i != x && i != y && has_common_enemy(G, x, i) && has_common_enemy(G, y, i)) {
            common_enemies[n_common++] = i;
        }
    }

    if (n_common == 0) {
        printf("KHONG CHUNG DOI THU\n");
    } else {
        for (i = 0; i < n_common; i++) {
            printf("%d ", common_enemies[i]);
        }
        printf("\n");
    }
}

int main() {
    Graph G;
    int n, m, u, v, e, x, y;
    // freopen("HeSinhThaiRung.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 1; e <= m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, 1, u, v);
        add_edge(&G, 1, v, u);
    }

    scanf("%d%d", &x, &y);
    find_common_enemies(&G, x, y);

    return 0;
}


// Trong hệ sinh thái rừng gồm có các loài động vật sau đây: gấu trúc, diều hâu, chim cú, sóc, quạ, thú có túi, chuột chù, chuột, chim gõ kiến. Những nhà nghiên cứu về hệ sinh thái này nhận thấy có sự tương tác của các loài vật này về nguồn thức ăn. Ví dụ: gấu trúc và cú cạnh tranh với nhau vì chúng có cùng nguồn thức ăn. Sự cạnh tranh được các nhà nghiên cứu tổng hợp lại như sau: 

// - (Gấu trúc và Chim cú)

// - (Gấu trúc và Diều hâu)

// - (Diều hâu và Chim cú)

// - (Gấu trúc và Sóc)

// - (Sóc và Quạ)

// - (Diều hâu và Quạ)

// - (Chim cú và Quạ)

// - (Thú có túi và Sóc)

// - (Thú có túi và Chuột chù)

// - (Thú có túi và Chim gõ kiến)

// - (Sóc và Chim gõ kiến)

// - (Chim gõ kiến và Chuột chù)

// - (Chuột chù và Chuột).

// Các nhà nghiên cứu cần biết giữa hai loài x và y thì chúng có chung những đối thủ cạnh tranh nào? Hãy viết chương trình để giúp các nhà nghiên cứu tìm ra đối thủ cạnh tranh chung của hai loài x và y.


// Để đơn giản trong cài đặt, ta đánh số lại mỗi loại động vật tương ứng với một con số như sau:


// Gấu trúc

// Diều hâu

// Chim cú

// Sóc

// Quạ

// Thú có túi

// Chuột chù

// Chuột

// Chim gõ kiến

// 1

// 2

// 3

// 4

// 5

// 6

// 7

// 8

// 9

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// Đầu vào (Input):

// - Dòng đầu tiên chứa số nguyên n tương ứng là số loài động vật trong hệ sinh thái rừng

// - n dòng kế tiếp, mỗi dòng chứa n số nguyên w cách nhau một khoảng trắng. 

// w=0: nói rằng động vật (dòng) thứ i  và động (cột) thứ j không là đối thủ cạnh tranh.
// w=1: nói rằng động vật (dòng) thứ i  và động (cột) thứ j là đối thủ cạnh tranh.
// - Dòng cuối cùng chứ 2 số nguyên x y là hai loài mà các nhà nghiên cứu cần tìm những đối thủ cạnh tranh chung của chúng.

// Đầu ra (Output):

// - In ra màn danh sách những đối thủ cạnh tranh chung của hai loài theo thứ tự từ nhỏ đến lớn.

// - Nếu hai loài không có chung đối thủ cạnh tranh thì in ra "KHONG CHUNG DOI THU"

// - Xem thêm ví dụ bên dưới.

// - Có thể sử dụng đoạn chương trình đọc dữ liệu mẫu sau đây:

// 	Graph G;
// 	int n, m, u, v, e, x, y;
// 	freopen("HeSinhThaiRung.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này
// 	scanf("%d%d", &n, &m);
// 	init_graph(&G, n);
// 	//Đọc đồ thị
	
// 	...
	
// 	//Đọc 2 loài x và y
// 	scanf("%d%d", &x, &y);
// For example:

// Input	Result
// 9                       6 9
// 0 1 1 1 0 0 0 0 0
// 0 0 1 0 1 0 0 0 0
// 0 0 0 0 1 0 0 0 0
// 0 0 0 0 1 0 0 0 1
// 0 0 0 0 0 0 0 0 0
// 0 0 0 1 0 0 1 0 1
// 0 0 0 0 0 0 0 1 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 1 0 0
// 4 7

// 9                           4
// 0 1 1 1 0 0 0 0 0
// 0 0 1 0 1 0 0 0 0
// 0 0 0 0 1 0 0 0 0
// 0 0 0 0 1 0 0 0 1
// 0 0 0 0 0 0 0 0 0
// 0 0 0 1 0 0 1 0 1
// 0 0 0 0 0 0 0 1 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 1 0 0
// 1 9


// 9
// 0 1 1 1 0 0 0 0 0   KHONG CHUNG DOI THU
// 0 0 1 0 1 0 0 0 0
// 0 0 0 0 1 0 0 0 0
// 0 0 0 0 1 0 0 0 1
// 0 0 0 0 0 0 0 0 0
// 0 0 0 1 0 0 1 0 1
// 0 0 0 0 0 0 0 1 0
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 1 0 0
// 2 8

