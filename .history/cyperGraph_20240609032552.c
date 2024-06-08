#include <stdio.h>
#include <limits.h>

// Số thành phố và số con đường
#define MAXN 1001
#define INF INT_MAX

int n, m;
int graph[MAXN][MAXN]; // Lưu trữ chiều dài của các con đường
int s, t; // Thành phố bắt đầu và kết thúc

// Hàm tìm đường đi ngắn nhất từ s đến t bằng thuật toán Dijkstra
int dijkstra(int s, int t) {
    int dist[MAXN];
    int visited[MAXN] = {0};
    
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
    }
    
    dist[s] = 0;
    
    for (int count = 1; count < n; ++count) {
        int u = -1, min_dist = INF;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }
        
        if (u == -1 || u == t) break;
        
        visited[u] = 1;
        
        for (int v = 1; v <= n; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    return dist[t];
}

int main() {
    // Đọc dữ liệu đầu vào
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        graph[u][v] = d;
        graph[v][u] = d; // Vì đường đi là hai chiều
    }
    scanf("%d %d", &s, &t);
    
    // Tìm và in ra đường đi ngắn nhất từ s đến t
    printf("%d\n", dijkstra(s, t));
    
    return 0;
}


// Đất nước CyberGraph có n thành phố và m con đường. Mỗi con đường nối 2 thành phố lại với nhau. tất cả các con đường đều là đường 2 chiều, mỗi con đường có một chiều dài nào đó. giữa hai thành phố có nhiều nhất là 1 con đường.

// Tổng thổng của nước này dự định sẽ đi từ thành phố s đến thành phố t. Đương nhiên, ông ta sẽ chọn hành trình có tổng chiều dài các con đường đi qua ngắn nhất.

// Hãy giúp Ngài tổng thổng tìm hành trình ngắn nhất đi từ s đến t.

// Đầu vào (Input):

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số thành phố và số con đường.

// - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u v d mô tả con đường nối hai thành phố u và v có chiều dài d.

// - Dòng cuối cùng chứa số nguyên s t là thành phố bắt đầu và kết thúc.

// Đầu ra (Output):

// In ra màn hình tổng chiều dài các con đường của hành trình ngắn nhất..

// Xem thêm ví dụ bên dưới.

// For example:

// Input	Result
// 4 3         12
// 1 2 5
// 2 3 2
// 3 4 5
// 1 4

// 4 3         7
// 1 2 3
// 2 4 4
// 1 4 10
// 1 4

// 4 4     8
// 1 2 2
// 2 4 4
// 1 3 6
// 1 4 10
// 2 3

