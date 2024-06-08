// include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int handshakes[n + 1]; // Mảng lưu số lần bắt tay của mỗi người
    for (int i = 1; i <= n; i++) {
        handshakes[i] = 0; // Khởi tạo số lần bắt tay của mỗi người là 0
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        handshakes[a]++; // Tăng số lần bắt tay của người a lên 1
        handshakes[b]++; // Tăng số lần bắt tay của người b lên 1
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", handshakes[i]);
    }

    return 0;
}


// rong một buổi tiệc có n người tham dự trong đó có một số cặp đã bắt tay với nhau.

// Hỏi mỗi người đã bắt tay bao nhiêu lần. Dĩ nhiên, một người không thể tự bắt tay với chính mình và ta được biết rằng hai người chỉ bắt tay với nhau nhiều nhất 1 lần.

// Đầu vào

// Dữ liệu đầu vào được đọc từ bàn phím (stdin) với định dạng sau:

// Dòng đầu tiên gồm hai số nguyên n và m cách nhau một khoảng trắng với n là số người và m là tổng số lần bắt tay quan sát được.
// m dòng kế tiếp, mỗi dòng chứa 2 số nguyên a b cách nhau một khoảng trắng ý nói rằng người a và người b đã bắt tay với nhau.
// Đầu ra

// In ra màn hình (stdout) số lần bắt tay của từng người theo thứ tự từ 1 đến n, mỗi người 1 dòng.
// Xem chi tiết trong phần ví dụ.
// For example:

// Input	Result
// 4 5     3
// 1 2     3
// 1 3     2
// 1 4     2
// 2 3
// 2 4


// 11 6    
// 1 6
// 3 5
// 3 8
// 3 11
// 6 7
// 8 9

