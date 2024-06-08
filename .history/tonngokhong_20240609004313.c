#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

// Biến toàn cục để lưu trữ ma trận kề
int graph[MAX][MAX];
int visited[MAX]; // Mảng lưu trữ các đỉnh đã được duyệt

// Hàm DFS kiểm tra tính kết nối
void DFS(int start, int n) {
    visited[start] = 1; // Đánh dấu đỉnh đã được duyệt

    for (int i = 1; i <= n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(i, n); // Gọi đệ quy DFS cho đỉnh kề chưa được duyệt
        }
    }
}

// Hàm kiểm tra tính liên thông của đồ thị
bool isConnected(int n) {
    // Khởi tạo mảng visited
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    // Tìm một đỉnh bất kỳ và duyệt toàn bộ đồ thị từ đó
    int start;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            start = i;
            break;
        }
    }

    DFS(start, n);

    // Kiểm tra xem tất cả các đỉnh đã được duyệt hay chưa
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Khởi tạo ma trận kề
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }

    // Nhập các cặp cây có thể chuyển qua lại
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Vì đồ thị là vô hướng
    }

    // Kiểm tra tính liên thông của đồ thị
    if (isConnected(n)) {
        printf("DUOC\n");
    } else {
        printf("KHONG\n");
    }

    return 0;
}




// Tôn Ngộ Không là một trong các nhân vật chính của truyện Tây du ký. Khi còn ở Hoa Quả Sơn, Tôn Ngộ Không là vua của loài khỉ. Hoa Quả Sơn có rất nhiều cây ăn trái, nên loài khỉ rất thích. Do đặc tính của mình, khỉ không thích đi bộ mà chỉ thích chuyền từ cây này sang một cây khác. Tuy nhiên, nếu khoảng cách giữa hai cây quá xa thi chúng không thể chuyền qua lại được.

// Đường đường là vua của loài khỉ, Tôn Ngộ Không muốn vạch ra một kế hoạch hái trái cây trên tất cả các cây có trên Hoa Quả Sơn mà không cần phải nhảy xuống đất. Tôn Ngộ Không dự định sẽ bắt đầu leo lên một cây, hái trái của cây này, sau đó chuyền qua một cây kế tiếp hái trái của này và tiếp tục như thế cho đến khi tất cả các cây đều được hái trái. Một cây có thể được chuyền qua chuyền lại nhiều lần.

// Hãy giúp Tôn Ngộ Không kiểm tra xem kế hoạch này có thể thực hiện được không.

// Đầu vào (Input):
// Giả sử số lượng cây ăn trái ở Hoa Quả Sơn là n cây và được đánh số từ 1 đến n.

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số cây và số cặp cây có thể chuyền qua lại.

// - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng có thể chuyền từ cây u sang cây v hoặc chuyền từ cây v sang cây u.

// Đầu ra (Output):

// Nếu kế hoạch của Tôn Ngộ Không có thể thực hiện được DUOC, ngược lại in ra KHONG.

// Xem thêm ví dụ bên dưới. Trong ví dụ đầu tiên, Tôn Ngộ Không bắt đầu từ cây 1, chuyền qua cây 2, sau đó chuyền ngược về 1, chuyền tiếp sang 3 và sau cùng là sang 4.

// For example:

// Input	Result
// 4 3     DUOC
// 2 1
// 1 3
// 3 4

// 4 2      KHONG
// 1 2
// 3 4

