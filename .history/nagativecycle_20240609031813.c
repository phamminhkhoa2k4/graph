


// Viết chương trình kiểm tra một đồ thị có hướng (không có khuyên, không có đa cung) xem có chứa chu trình âm hay không.

// Chu trình âm là chu trình có tổng trọng số các cung trong chu trình nhỏ hơn 0.

// Đầu vào (Input):

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

// - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u, v, w mô tả cung (u, v) có trọng số w.

// Đầu ra (Output):

// In ra màn hình negative cycle nếu đồ thị có chứa chu trình âm, ngược lại in ra ok

// Xem thêm ví dụ bên dưới.

// Chú ý:

// Để chạy thử chương trình, bạn nên tạo một tập tin dt.txt chứa đồ thị cần kiểm tra.
// Thêm dòng freopen("dt.txt", "r", stdin); vào ngay sau hàm main(). Khi nộp bài, nhớ gỡ bỏ dòng này ra.
// Có thể sử dụng đoạn chương trình đọc dữ liệu mẫu sau đây:
// 	freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
// 	Graph G;
// 	int n, m, u, v, w, e;
// 	scanf("%d%d", &n, &m);
// 	init_graph(&G, n);
	
// 	for (e = 0; e < m; e++) {
// 		scanf("%d%d%d", &u, &v, &w);
// 		add_edge(&G, u, v, w);
// 	}




// For example:

// Input	Result
// 3 2  
// 1 3 1
// 3 1 1
// ok
// 7 10
// 1 2 1
// 1 3 1
// 1 4 1
// 2 3 1
// 2 6 1
// 3 7 1
// 4 5 1
// 5 3 1
// 5 7 1
// 3 1 1
// ok
// 7 12
// 1 2 1
// 1 3 1
// 2 4 1
// 2 5 1
// 2 6 1
// 3 2 1
// 3 5 1
// 3 6 1
// 4 7 1
// 5 7 1
// 6 4 1
// 2 1 1
// ok
// 3 3
// 1 2 4
// 2 3 -10
// 3 1 2
// negative cycle
// 3 3
// 1 2 1
// 2 3 1
// 3 1 1
// ok