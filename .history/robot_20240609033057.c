#include <stdio.h>
#include <limits.h>

#define MAX_ROW 100
#define MAX_COL 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

int bellmanFord(int maze[MAX_ROW][MAX_COL], int M, int N) {
    int dist[MAX_ROW][MAX_COL];
    
    // Khởi tạo ma trận khoảng cách ban đầu
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    
    dist[0][0] = maze[0][0]; // Khoảng cách từ điểm bắt đầu đến chính nó là giá trị của ô đó

    // Duyệt qua tất cả các ô trong mê cung
    for (int k = 0; k < M * N - 1; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // Cập nhật khoảng cách nếu tìm thấy đường đi ngắn hơn
                if (i < M - 1) { // Kiểm tra có thể đi xuống không
                    dist[i + 1][j] = min(dist[i + 1][j], dist[i][j] + maze[i + 1][j]);
                }
                if (j < N - 1) { // Kiểm tra có thể đi sang phải không
                    dist[i][j + 1] = min(dist[i][j + 1], dist[i][j] + maze[i][j + 1]);
                }
            }
        }
    }
    
    // Trả về khoảng cách tối ưu từ góc trên bên trái đến góc dưới bên phải
    return dist[M - 1][N - 1];
}

int main() {
    int M, N;
    int maze[MAX_ROW][MAX_COL];

    // Nhập số hàng và số cột
    printf("Nhap so hang va so cot: ");
    scanf("%d %d", &M, &N);

    // Nhập mê cung
    printf("Nhap cac so trong me cung:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // Tìm đường đi có chi phí thấp nhất
    int minCost = bellmanFord(maze, M, N);

    // In ra kết quả
    printf("Chi phi thap nhat: %d\n", minCost);

    return 0;
}


// Cho một mê cung số được biểu diễn bằng một mảng 2 chiều chứa các con số từ 0 đến 9 (xem

// hình bên dưới).




// Một con robot được đặt tại góc trên bên trái của mê cung và muốn đi đến góc dưới bên phải của mê cung. Con robot có thể đi lên, xuống, qua trái và qua phải 1 ô. Chi phí để đi đến một ô bằng với con số bên trong ô đó.

// Hãy tìm cách giúp con robot đi đến ô góc dưới phải sao cho tổng chi phí thấp nhất.

// Đường đi có chi phí thấp nhất cho ví dụ này là 24.



// Đầu vào (Input):

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// Dòng dầu chứa 2 số nguyên M N (M: số hàng, N: số cột)
// M dòng tiếp theo mô tả các số trong mê cung


// Đầu ra (Output):

// In ra màn hình chi phí thấp nhất để con robot đi từ góc trên bên trái về góc dưới bên phải. Ví dụ trên, cần in ra màn hình: 24.
// Xem thêm các ví dụ bên dưới.

// Gợi ý:

// Mô hình hoá bài toán về đồ thị có hướng

// Đỉnh ~ ô
// Cung ~ hai ô cạnh nhau
// Trọng số cung (u, v) = giá trị của ô tương ứng với đỉnh v.
// Xem tài liệu thực hành để biết cách đặt tên cho các ô.



// For example:

// Input	Result
// 4 5         24
// 0 3 1 2 9
// 7 3 4 9 9
// 1 7 5 5 3
// 2 3 4 2 5

// 3 3          18
// 1 2 3
// 2 4 4
// 1 4 10

// 4 3           17
// 1 2 2
// 2 1 4
// 4 2 1
// 8 4 10

