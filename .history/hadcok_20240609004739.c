#include <stdio.h>
#include <stdbool.h>

#define MAXN 1000

int graph[MAXN][MAXN];
bool visited[MAXN];
bool stack[MAXN];

bool hasCycle(int u, int n) {
    if (stack[u]) // Đỉnh u đã được thăm trong quá trình DFS hiện tại, tức là có chu trình
        return true;
    if (visited[u]) // Đỉnh u đã được thăm trước đó, không cần duyệt lại
        return false;

    visited[u] = true;
    stack[u] = true;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (hasCycle(v, n))
                return true;
        }
    }

    stack[u] = false; // Khi kết thúc việc duyệt đỉnh u, ta loại bỏ nó khỏi stack
    return false;
}

bool canGetDrunk(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        stack[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(i, n))
                return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Khởi tạo ma trận kề
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = 1;
    }

    if (canGetDrunk(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}



// Thuyền trưởng Haddock (truyện Tintin) là một người luôn say xỉn. Vì thế đôi khi Tintin không biết ông ta đang say hay tỉnh. Một ngày nọ, Tintin hỏi ông ta về cách uống. Haddock nói như thế này: Có nhiều loại thức uống (soda, wine, water, …), tuy nhiên Haddock lại tuân theo quy tắc “để uống một loại thức uống nào đó cần phải uống tất cả các loại thức uống tiên quyết của nó”. Ví dụ: để uống rượu (wine), Haddock cần phải uống soda và nước (water) trước. Vì thế muốn say cũng không phải dễ !

// Cho danh sách các thức uống và các thức uống tiên quyết của nó. Hãy xét xem Haddock có thể nào say không ? Để làm cho Haddock say, ông ta phải uống hết tất cả các thức uống.

// Ví dụ 1:

// soda wine
// water wine
// Thức uống tiên quyết được cho dưới dạng a b, có nghĩa là để uống b bạn phải uống a trước. Trong ví dụ trên để uống wine, Haddock phải uống soda và water trước. Soda và water không có thức uống tiên quyết nên Haddock sẽ SAY.

// Ví dụ 2:

// soda wine
// water wine
// wine water
// Để uống wine, cần uống water. Tuy nhiên để uống water lại cần wine. Vì thế Haddock không thể uống hết được các thức uống nên ông ta KHÔNG SAY.

// Để đơn giản ta có thể giả sử các thức uống được mã hoá thành các số nguyên từ 1, 2, … và dữ liệu đầu vào được cho có dạng như sau (ví dụ 1):

// 3 2
// 1 2
// 3 2
// Có loại thức uống (soda: 1, wine: 2 và water: 3) và có 2 điều kiện tiên quyết

// 1 -> 2 và 3 -> 2.

// Với ví dụ 2, ta có dữ liệu:

// 3 3
// 1 2
// 3 2
// 2 3
// Viết chương trình đọc dữ liệu các thức uống và kiểm tra xem Haddock có thể say không. Nếu có in ra “YES”, ngược lại in ra “NO”.

// Đầu vào (Input):

// Dữ liệu đầu vào được nhập từ bàn phím (stdin) với định dạng:

// Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số thức uống và số điều kiện tiên quyết .
// m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng thức uống u là tiên quyết của thức uống v.
// Đầu ra (Output):

// Nếu Haddock có thể say in ra YES, ngược lại in ra NO.


// Xem thêm các ví dụ bên dưới.

// For example:

// Input	Result
// 3 2
// 1 2
// 3 2
// YES
// 3 3
// 1 2
// 3 2
// 2 3
// NO
// 5 5
// 1 2
// 2 3
// 3 4
// 4 2
// 5 4
// NO
