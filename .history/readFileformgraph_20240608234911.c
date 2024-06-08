// include <stdio.h>
// include <stdlib.h>


#define MAX_VERTICES 100

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

int main() {
    FILE *file;
    int n, m, u, v;
    
    // Mở tập tin đầu vào
    file = fopen("dt1.txt", "r");
    if (file == NULL) {
        printf("Không thể mở tập tin.\n");
        return 1;
    }
    
    // Đọc số đỉnh và số cung từ tập tin
    fscanf(file, "%d %d", &n, &m);
    
    // Khởi tạo ma trận kề
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
    
    // Đọc các cung và cập nhật ma trận kề
    for (int i = 0; i < m; i++) {
        fscanf(file, "%d %d", &u, &v);
        adjacency_matrix[u - 1][v - 1] = 1;
        adjacency_matrix[v - 1][u - 1] = 1; // vì đồ thị vô hướng
    }
    
    // Đóng tập tin
    fclose(file);
    
    // Hiển thị ma trận kề
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}



Hãy viết chương trình đọc đồ thị từ tập tin và hiển thị ma trận kề của đồ thị này.

Giả sử đồ thị được cho là đồ thị vô hướng đơn.

Đầu vào (Input):

Dữ liệu đầu vào được nhập từ tập tin dt1.txt với định dạng:

- Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

- m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v mô tả cung (u, v).

Đầu ra (Output):

In ra Ma trận kề (0/1) của đồ thị

Ví dụ:

Nếu đầu vào là:

4 4
1 2
1 3
2 3
3 4
Kết quả là:

0 1 1 0 
1 0 1 0 
1 1 0 1 
0 0 1 0