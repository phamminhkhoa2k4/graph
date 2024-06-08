//include <stdio.h>
//include <stdlib.h>

#define MAXN 1000

int graph[MAXN][MAXN];
int visited[MAXN];
int group[MAXN];
int N, M;

// Đánh dấu nhóm cho thành viên
void assignGroup(int u, int g) {
    group[u] = g;
    visited[u] = 1;
    for (int v = 1; v <= N; v++) {
        if (!visited[v] && !graph[u][v])
            assignGroup(v, 3 - g);
    }
}

int main() {
    // Nhập số thành viên và số cặp thành viên đã từng thi đấu với nhau
    scanf("%d %d", &N, &M);

    // Khởi tạo ma trận kề
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    // Kiểm tra xem có thể phân chia không
    for (int i = 1; i <= N; i++) {
        if (!visited[i])
            assignGroup(i, 1);
    }

    // In kết quả
    int impossible = 0;
    for (int i = 1; i <= N; i++) {
        if (group[i] == 0) {
            impossible = 1;
            printf("IMPOSSIBLE\n");
            break;
        }
    }
    if (!impossible) {
        for (int g = 1; g <= 2; g++) {
            for (int i = 1; i <= N; i++) {
                if (group[i] == g)
                    printf("%d ", i);
            }
            printf("\n");
        }
    }

    return 0;
}



// David là huấn luyện viên của một đội bóng gồm N thành viên. David muốn chia đội bóng thành hai nhóm. Để tăng tính đa dạng của các thành viên trong nhóm, David quyết định không xếp hai thành viên đã từng thi đấu với nhau vào chung một nhóm. Bạn hãy lập trình giúp David phân chia đội bóng.

// Đầu vào (Input):
// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// Dòng đầu tiên chứa 2 số nguyên N và M, tương ứng là số thành viên và số cặp thành viên đã từng thi đấu với nhau.
// M dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng 2 thành viên u và v đã từng thi đấu chung với nhau.
// Đầu ra (Output):

// Nếu phân chia được, hãy in ra các thành viên của mỗi nhóm. Nhóm của thành viên 1 sẽ được in trước, nhóm còn lại in ra sau. Các thành viên trong nhóm được in ra theo thứ tự tăng dần và in trên 1 dòng. Hai thành viên cách nhau 1 khoảng trắng.
// Nếu không thể phân chia, in ra IMPOSSIBLE


// Xem thêm các ví dụ bên dưới.

// For example:

// Input	Result
// 3 2
// 1 2
// 2 3
// 1 3
// 2
// 3 3
// 1 2
// 2 3
// 3 1
// IMPOSSIBLE
// 9 8
// 1 2
// 1 3
// 1 4
// 1 5
// 1 6
// 1 7
// 1 8
// 1 9
// 1
// 2 3 4 5 6 7 8 9
