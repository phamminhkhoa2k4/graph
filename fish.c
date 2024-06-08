// include <stdio.h>
// include <stdbool.h>

#define MAX_N 1000

int n, m;
int A[MAX_N], B[MAX_N];
bool graph[MAX_N][MAX_N];
bool visited[MAX_N];
int group[MAX_N];

void dfs(int node, int g) {
    visited[node] = true;
    group[node] = g;
    
    for (int i = 1; i <= n; ++i) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, !g);
        }
    }
}

bool canDivide() {
    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (group[A[i]] == group[B[i]]) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &A[i], &B[i]);
        graph[A[i]][B[i]] = graph[B[i]][A[i]] = true;
    }

    if (canDivide()) {
        int count_A = 0, count_B = 0;
        for (int i = 1; i <= n; ++i) {
            if (group[i] == 0) {
                ++count_A;
            } else {
                ++count_B;
            }
        }
        printf("%d %d\n", count_A, count_B);
    } else {
        printf("-1 -1\n");
    }

    return 0;
}

// Nam vừa mới được chú Long tặng cho n con cá cảnh và 2 hồ cá. Tuy do bản tính tự nhiên, một số con cá "không thích" ở chung với nhau. Nếu thả chúng vào chung 1 hồ chúng sẽ cắn nhau và Nam không muốn điều đó xảy ra chút nào.

// Để đơn giản, ta đánh số các con cá lần lượt là 1, 2, ..., n và gọi hai hồ cá lần lượt là A và B.

// Bạn hãy lập trình giúp Nam tìm xem có thể phân chia các con cá vào 2 hai hồ cá hay không. Nếu được, đếm xem mỗi hồ có bao nhiêu con.

// Đầu vào (Input):
// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số con cá và số cặp cá "không thích" nhau.
// m dòng tiếp theo, mỗi dòng chứa 2 số nguyên a b nói rằng 2 con cá a và b sẽ cắn nhau nếu thả chúng vào chung một hồ.
// Đầu ra (Output):

// Nếu phân chia được, in ra x y với:
// x: số con cá trong hồ A (giả sử con cá số 1 luôn được thả trong hồ A)
// y: số con cá trong hồ B.
// Nếu không thể phân chia, in ra -1 -1


// Xem thêm các ví dụ bên dưới.

// For example:

// Input	Result
// 3 2     2 1
// 1 2
// 2 3

// 3 3     -1 -1
// 1 2
// 2 3
// 3 1

// 9 8     1 8
// 1 2
// 1 3
// 1 4
// 1 5
// 1 6
// 1 7

// 1 9     2 3
// 1 8
// 5 5
// 1 3
// 1 4
// 1 5
// 2 4
// 2 5
