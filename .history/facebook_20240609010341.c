acebook là một mạng xã hội lớn nhất toàn cầu với 2.2 tỷ người dùng đang hoạt động (số liệu quí 4 năm 2017 theo https://www.statista.com/).

Một người dùng trên facebook có thể "kết bạn" với một người dùng khác và hai người sẽ trở thành "bạn bè" của nhau (trên facebook).

Một trong các hoạt động mà người dùng làm thường xuyên là đăng (post) một bài viết/hình ảnh/video gọi chung là status lên dòng thời gian (timeline) của mình và các người dùng khác vào xem bình luận (comment) hoặc chia sẻ (share).

Người dùng có thể thiết lập để cho phép ai có thể xem được status của mình. Hiện tại facebook cung cấp các cấp độ sau:



Public: ai cũng xem được
Friends: bạn bè của bạn xem được
Friends except: bạn bè của bạn trừ 1 số người,
...
 Facebook đang dự kiến cho phép người dùng thiết lập là "friends of friends of friends of .... ". Thiết lập mới này cho phép khi bạn đăng một status, thì bạn của bạn, bạn của bạn của bạn, bạn của bạn của bạn của bạn, .... cũng sẽ xem được status này.

Nói theo cách bình dân là: "bạn của bạn cũng là bạn".

Nói theo toán học là: nếu có một dãy các phần tử a1, a2, ..., ak trong đó ai và ai+1 (i = 1, 2, ...) là bạn bè của nhau thì ak sẽ xem được status của a1.



2 tỷ người dùng là quá lớn. Do đó, để đơn giản hoá vấn đề ta chỉ xét những người dùng facebook đang học Lý thuyết đồ thị nhóm 2 (sáng thứ 3, không hơn 100 người) và đánh số các người dùng này lần lượt là: 1, 2, ..., n (n < 100).

Một ngày đẹp trời, người dùng X (1 <= X <= n) đăng một status rất hay với thiết lập mới "friends of friends of friends of .... ". Với thiết lập mới này, bạn hãy lập trình tìm xem những người dùng nào sẽ xem được status của X. 

Đầu vào (Input):

Dữ liệu đầu vào được nhập từ bàn phím (stdin) với định dạng:

Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là người dùng và cặp đã kết bạn.
m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng người u và v là bạn bè của nhau.
Dòng sau cùng chứa số nguyên X - người dùng đã đăng status.
Đầu ra (Output):

In ra màn hình (stdout) những người có thể xem được status của X (kể cả X) trên cùng 1 dòng, cách nhau 1 khoảng trắng, theo thứ tự từ nhỏ đến lớn.

Xem thêm ví dụ bên dưới.

For example:

Input	Result
4 3     1 2 3 4
1 2
2 3
3 4
1

4 2     3 4
3 4
1 2
4

4 2     1 4
2 3
1 4
1

10 6    
1 6
4 10
5 1
6 5
9 2
10 5
6

