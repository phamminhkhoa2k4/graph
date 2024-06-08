Cho đồ thị đơn, vô hướng G = <V, E> có n đỉnh và m cung (n < 100, m < 500). Mỗi cung được gán một trọng số w (0 < w <= 100).

Viết chương trình tìm đếm xem có bao nhiêu đường đi ngắn nhất từ đỉnh 1 đến n.

Đầu vào (Input):

Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

- Dòng đầu tiên chứa 2 số nguyên n và m.

- m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả cung (u, v) có trọng số w.

Đầu ra (Output):

In ra màn hình chiều dài của đường đi ngắn nhất từ 1 đến n và số đường đi có chiều dài bằng với chiều dài dường đi ngắn nhất. Nếu không có đường đi từ 1 đến n, in ra -1 0.

Trong ví dụ đầu tiên có 2 đường đi từ 1 đến 3 là: 1 - 2 - 3 và 1 - 3. Cả hai đường đi này đều ngắn nhất và có chiều dài bằng 6.

Xem thêm ví dụ bên dưới.

Gợi ý:

Ngoài pi[v], ta định nghĩa thêm cnt[v]: số đường đi ngắn nhất từ s đến v.

Mỗi lần cập nhật pi[v] ta chú ý cập nhật lại cnt[v]. Nếu đường đi mới qua u tốt hơn thì cnt[v] = cnt[u]. Nếu bằng nhau thì cộng thêm: cnt[v] += cnt[u].

Chú ý:

Để chạy thử chương trình, bạn nên tạo một tập tin dt.txt chứa đồ thị cần kiểm tra.
Thêm dòng freopen("dt.txt", "r", stdin); vào ngay sau hàm main(). Khi nộp bài, nhớ gỡ bỏ dòng này ra.
Có thể sử dụng đoạn chương trình đọc dữ liệu mẫu sau đây:
	freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}




For example:

Input	Result
3 3     6 2
1 2 2
2 3 4
1 3 6

3 1
1 2 5

6 9
1 2 7
1 3 9
1 5 14
2 3 10
2 4 15
3 4 11
3 5 2
4 6 6
5 6 9
20 1
