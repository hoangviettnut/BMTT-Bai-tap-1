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
C++:<img width="1483" height="762" alt="image" src="https://github.com/user-attachments/assets/ff0fe1f5-f9a0-4264-bb8d-f48b7a7763bb" />
JS, HTML + CSS: 
Mã hóa:<img width="1920" height="1140" alt="image" src="https://github.com/user-attachments/assets/8f26e1f7-85b6-468b-ba45-27ff03b63630" />
Giải mã: <img width="1914" height="1028" alt="image" src="https://github.com/user-attachments/assets/6b379cb7-6463-4e71-b379-890294eab35c" />

## 3. HOÁN VỊ
### a) Tên gọi: là quá trình tìm kiếm và liệt kê tất cả các cách sắp xếp có thể có của một tập hợp các phần tử
### b) Thuật toán mã hóa và giải mã:
Mã hóa: Mã hóa hoán vị giữ nguyên ký tự gốc nhưng đổi vị trí của chúng theo một hoán vị đã định
Giải mã: Để giải mã, ta cần hoán vị ngược lại vị trí ban đầu.
### c) Không gian khóa: tập hợp tất cả các hoán vị có thể của n ký tự.
### d) Cách phá mã ( mà không cần khóa)
Phân tích tần suất (Frequency Analysis)
- Dù hoán vị thay đổi vị trí ký tự, tần suất xuất hiện của từng ký tự vẫn giữ nguyên.
- Ví dụ: nếu trong bản mã hóa, chữ "E" xuất hiện nhiều nhất, có thể đoán đó là chữ "E" trong tiếng Anh gốc.
- Phân tích này đặc biệt hiệu quả với ngôn ngữ có tần suất ký tự đặc trưng (như tiếng Anh, tiếng Việt).
Phân tích mẫu từ (Pattern Recognition)
- Nếu thông điệp đủ dài, có thể xuất hiện các từ quen thuộc hoặc cấu trúc ngữ pháp dễ đoán.
- Ví dụ: bản mã có đoạn "HTE" → có thể đoán là "THE" nếu biết ngôn ngữ gốc.
- Dùng từ điển để thử khớp các hoán vị có thể với từ thật.
Phân tích ngữ cảnh (Contextual Analysis)
- Nếu biết chủ đề hoặc nội dung dự đoán của thông điệp (ví dụ: là một lời chào, mật khẩu, hay tên người), có thể thử các hoán vị phù hợp với ngữ cảnh đó.
- Kết hợp với từ điển, mẫu câu, hoặc dữ liệu huấn luyện.
Tấn công đã biết bản rõ (Known-plaintext attack)
- Nếu kẻ tấn công biết một phần thông điệp gốc và bản mã tương ứng → có thể suy ra hoán vị.
- Ví dụ: biết "HELLO" được mã hóa thành "LHOEL" → có thể suy ra hoán vị là [3,1,4,0,2].
### e) Cài đặt thuật toán bằng C++ và JS, HTML + CSS
C++: <img width="1483" height="762" alt="image" src="https://github.com/user-attachments/assets/faf9bd7b-410b-43d6-b1f9-235a6b7593b2" />
JS, HTML + CSS: <img width="1915" height="1022" alt="image" src="https://github.com/user-attachments/assets/432ce3ad-9685-4487-90a0-b8bc3b001a0a" />

## 4. VIGENÈRE
### a) Tên gọi: là một phương pháp mã hóa mật mã thay thế dùng nhiều bảng chữ cái, sử dụng một từ khóa để xác định các phép dịch chuyển Caesar khác nhau cho từng chữ cái trong bản rõ.
### b) Thuật toán mã hóa và giải mã
Mã hóa: Giả sử:
- P_i là ký tự thứ i của bản rõ
- K_i là ký tự thứ i của khóa (đã lặp)
- C_i là ký tự thứ i của bản mã
Ta có công thức:
C_i = (P_i + K_i) \mod 26
Trong đó, các ký tự được chuyển sang số từ 0 đến 25 (A → 0, B → 1, ..., Z → 25)
Giải mã: P_i = (C_i - K_i + 26) \mod 26
### c) Không gian khóa: Không gian khóa của thuật toán Vigenère chính là tập hợp tất cả các khóa có thể sử dụng để mã hóa — và nó phụ thuộc vào độ dài khóa và bảng chữ cái.
### d) Cách phá mã ( mà không cần khóa): 
Phân tích tần suất (Frequency Analysis)
Vigenère là sự kết hợp của nhiều Caesar cipher, nếu khóa ngắn và lặp lại, thì mỗi ký tự trong bản mã sẽ bị dịch theo một chu kỳ cố định. Ta có thể:
- Tách bản mã thành các nhóm theo chu kỳ khóa (ví dụ: mỗi 3 ký tự nếu khóa dài 3)
- Với mỗi nhóm, áp dụng phân tích tần suất để đoán ký tự phổ biến nhất (thường là 'E' trong tiếng Anh)
- Từ đó suy ra dịch chuyển → suy ra từng ký tự của khóa
Phương pháp Kasiski (Kasiski Examination)
Kasiski là kỹ thuật để tìm độ dài khóa bằng cách:
- Tìm các chuỗi lặp lại trong bản mã (ví dụ: "XYXY")
- Ghi lại khoảng cách giữa các lần xuất hiện
- Tìm ước số chung lớn nhất của các khoảng cách → đó là độ dài khóa
Sau khi biết độ dài khóa, ta quay lại phân tích tần suất như ở bước 1.
Chỉ số trùng khớp (Index of Coincidence)
Một cách khác để đoán độ dài khóa là dùng chỉ số trùng khớp:
IC = \frac{\sum f_i(f_i - 1)}{N(N - 1)}
Trong đó:
- f_i là số lần xuất hiện của ký tự thứ i
- N là tổng số ký tự
Nếu IC gần 0.065 → có thể là tiếng Anh → dùng để xác định độ dài khóa.
### e) Cài đặt thuật toán bằng C++ và JS, HTML + CSS
C++:<img width="1483" height="762" alt="image" src="https://github.com/user-attachments/assets/241533ea-a8cf-4aac-b800-3a6f9292987d" />
JS, HTML + CSS: <img width="1919" height="1043" alt="image" src="https://github.com/user-attachments/assets/e0d58f0c-03e5-485a-9247-f5b7f138b898" />

## 5. PLAYFAIR
### a) Tên gọi: Là một phương pháp mật mã hóa đối xứng thủ công sử dụng ma trận 5x5 để mã hóa các cặp chữ cái (digraph), thay vì từng chữ cái riêng lẻ
### b) Thuật toán mã hóa và giải mã: 
Mã hóa: Ghép I và J thành một ký tự (thường dùng 'I')
- Tạo bảng 5×5 từ khóa (loại bỏ ký tự trùng, thêm các chữ cái còn lại)
- Chia bản rõ thành các cặp ký tự (digraphs):
- Nếu hai ký tự giống nhau → chèn 'X' vào giữa
- Nếu chuỗi có độ dài lẻ → thêm 'X' vào cuối
Giải mã: là quá trình đảo ngược quy tắc mã hóa:
- Cùng hàng → thay bằng ký tự bên trái (vòng tròn nếu đầu hàng)
- Cùng cột → thay bằng ký tự bên trên (vòng tròn nếu đầu cột)
- Khác hàng và cột → thay bằng ký tự ở góc đối diện
Sau khi giải mã:
- Loại bỏ ký tự 'X' dư nếu cần (ví dụ: giữa hai ký tự giống nhau)
- Khôi phục lại bản rõ ban đầu
### c) Không gian khóa: tập hợp tất cả các bảng chữ cái 5×5 có thể được tạo ra từ một khóa
### d) Cách phá mã ( mà không cần khóa): 
Phân tích tần suất digraphs (cặp ký tự)
Playfair mã hóa theo cặp, nên thay vì phân tích từng ký tự, ta phân tích tần suất các digraphs (ví dụ: TH, HE, IN, ER…).
Cách làm:
- Đếm tần suất các cặp trong bản mã
- So sánh với tần suất phổ biến trong ngôn ngữ (ví dụ tiếng Anh)
- Suy đoán các cặp tương ứng → từ đó khôi phục bảng mã
Phá bằng từ điển (dictionary attack)
Nếu biết hoặc nghi ngờ khóa là một từ có nghĩa (ví dụ: tên người, địa danh…), ta có thể:
- Tạo bảng Playfair từ các từ khóa phổ biến
- Mã hóa một số từ mẫu
- So sánh với bản mã → nếu khớp, ta tìm được khóa
Phá bằng giải thuật heuristic (tối ưu hóa)
Đây là cách hiện đại hơn, dùng thuật toán như:
- Hill Climbing
- Genetic Algorithm
- Simulated Annealing
Cách làm:
- Sinh ngẫu nhiên bảng Playfair
- Giải mã bản mã bằng bảng đó
- Đánh giá độ “giống ngôn ngữ” của kết quả (dựa vào từ vựng, ngữ pháp…)
- Lặp lại và cải thiện bảng cho đến khi ra bản rõ hợp lý
### e) Cài đặt thuật toán bằng C++ và JS, HTML + CSS
C++:<img width="1483" height="762" alt="image" src="https://github.com/user-attachments/assets/5888023f-7e2e-4dae-ab19-067461b01358" />
JS, HTML + CSS: <img width="1919" height="1035" alt="image" src="https://github.com/user-attachments/assets/3d4c7c52-3b4d-4062-980b-8aee3539a2bb" />

## NOTE: TOÀN BỘ CODE CHO CÁC THUẬT TOÁN ĐƯỢC UPLOAD Ở FOLDER BMTT















