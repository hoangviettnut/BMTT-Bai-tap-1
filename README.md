# BÀI TẬP 1 MÔN HỌC: BẢO MẬT THÔNG TIN
# SINH VIÊN THỰC HIỆN: LƯƠNG HOÀNG VIỆT - MSSV: K225480106073
## CÁC PHƯƠNG PHÁP MÃ HÓA CỔ ĐIỂN
## 1. CAESAR
### a) Tên gọi: 
Mã hóa Caesar (Xê da), còn gọi là mật mã dịch chuyển, là một trong những mật mã đơn giản và được biết đến nhiều nhất.
### b) Thuật toán mã hoá và giải mã:
Mã hóa:
Trong công thức Ci = (Pi + ki mod m) mod 26 , các biến có ý nghĩa như sau:

Ci: Ký tự mã hóa ở vị trí thứ i trong văn bản mã hóa.)
Pi: Ký tự cần mã hóa ở vị trí thứ i trong văn bản gốc.)
ki: Khóa hoặc "chìa khóa" sử dụng để mã hóa.)
m: Một giá trị hằng số (thường là kích thước của bảng mã hoặc tập hợp các ký tự có thể được mã hóa).)

Giải mã: Trong công thức Pi = (Ci - ki mod m) mod 26, giữa các biến, ta có:

Pi: Ký tự gốc ở vị trí thứ i trong văn bản gốc.)
Ci: Ký tự đã được mã hóa ở vị trí thứ i trong văn bản mã hóa.)
ki: Khóa hoặc "chìa khóa" sử dụng để mã hóa.)
m: Một giá trị hằng số (thường là kích thước của bảng mã hoặc tập hợp các ký tự có thể được mã hóa).)
### c) Không gian khóa: Là tập hợp tất cả các khóa có thể có cho mật mã đó, trong trường hợp này là tất cả các giá trị dịch chuyển có thể có từ 1 đến 25 (hoặc 0 đến 25), tạo nên một không gian khóa gồm 25 hoặc 26 khả năng khác nhau
### d) Cách phá mã ( mà không cần khóa):
Phân tích tần số từ:
- So sánh đầu ra với danh sách các từ tiếng Anh thông dụng.
- Đếm xem có bao nhiêu từ dễ nhận biết xuất hiện trong mỗi đầu ra.
Phân tích N-gram:
- Phân tích tần số của các cặp chữ cái (bigram) hoặc bộ ba (trigram) trong các văn bản được giải mã để phù hợp với các mẫu phổ biến trong tiếng Anh.
Khả năng đọc:
- Sử dụng phương pháp phỏng đoán đơn giản để chấm điểm kết quả đầu ra dựa trên các yếu tố như độ dài từ trung bình, sự hiện diện của các từ thông dụng và tính mạch lạc tổng thể.
### e) Cài đặt thuật toán bằng C++ và JS, HTML + CSS
C++: <img width="1483" height="762" alt="image" src="https://github.com/user-attachments/assets/85c9b02b-1157-4338-80bf-2a15590138ff" />
JS với giao diện HTML + CSS với chuỗi: "luong hoang viet":
Mã hóa: <img width="1920" height="1140" alt="image" src="https://github.com/user-attachments/assets/3185f2eb-48a8-4b95-b883-378e501e079d" />
Giải mã: <img width="1920" height="1140" alt="image" src="https://github.com/user-attachments/assets/f14e8181-1b7d-42bb-bc93-ff6ea2e5fd88" />
## 2. AFFINE
### a) Tên gọi: 
Hệ mật Affine là một mật mã khóa đối xứng cổ điển. Mỗi ký tự của của văn bản gốc được ánh xạ đến một kí tự duy nhất. Khi gộp các ký tự được ánh xạ chúng ta thu được văn bản mã hóa hay còn gọi là bản mã.
### b) Thuật toán mã hóa và giải mã:
Mã hóa:
Công thức của hệ mật Affine là 1 cặp khóa k={a, b} với điều kiện tiên quyết UCLN(a,26)=1.

Công thức mã hóa của hệ mật này là : y = (a*x + b) mod 26

Để giải mã được hệ mật này, trước hết ta cần tìm giá trị a^-1 thỏa mãn điều kiện a*a^-1 mod 26 = 1. Sau đó áp dụng công thức giải mã hệ mật là: x = a^-1*(y - b) mod 26

Giải mã: Công thức của hàm giải mã là: x = a^-1*(y - b) mod 26
### c) Không gian khóa: Là tập hợp tất cả các cặp khóa (a, b) có thể sử dụng trong mật mã Affine, nơi a là một số nguyên được chọn sao cho có ước chung lớn nhất (ƯCLN) là 1 với kích thước bảng chữ cái, và b là một số nguyên bất kỳ được chọn trong khoảng từ 0 đến kích thước bảng chữ cái trừ 1. Số lượng các khóa hợp lệ xác định kích thước của không gian khóa, và điều này ảnh hưởng đến độ bảo mật của mật mã. 
### d) Cách phá mã ( mà không cần khóa):
Phân tích tần suất (Frequency Analysis)
- Ý tưởng: Trong tiếng Việt hoặc tiếng Anh, một số chữ cái xuất hiện thường xuyên hơn (ví dụ: E, T, A trong tiếng Anh).
Tấn công vét cạn (Brute-force Attack)
- Không gian khóa: Với bảng chữ cái 26 ký tự, chỉ có 12 giá trị hợp lệ cho a (sao cho \gcd(a, 26) = 1) và 26 giá trị cho b, tổng cộng 312 cặp khóa.
- Thực hiện:
- Thử tất cả các cặp khóa (a, b).
- Giải mã bản mã với từng cặp và kiểm tra xem bản rõ có hợp lý không (dựa vào từ điển hoặc cấu trúc ngôn ngữ).
Giải hệ phương trình tuyến tính
- Nếu có ít nhất hai cặp ký tự bản rõ và bản mã tương ứng, có thể thiết lập hệ phương trình:
\begin{cases}


y_1 = a x_1 + b \mod 26 \\


y_2 = a x_2 + b \mod 26


\end{cases}
- Giải hệ để tìm a và b.
### e) Cài đặt thuật toán bằng C++ và JS, HTML + CSS







