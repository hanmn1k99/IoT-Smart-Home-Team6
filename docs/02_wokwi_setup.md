# 02. Hướng dẫn thiết lập trên Wokwi (Dành cho tài khoản Miễn phí)

Wokwi là trình giả lập mạch điện cực kỳ mạnh mẽ chạy ngay trên trình duyệt web. Do tài khoản Wokwi miễn phí không hỗ trợ tải lên thư mục hay file header (`.h`) tuỳ chỉnh, nên toàn bộ mã nguồn của dự án này đã được gộp gọn vào một file `.ino` duy nhất.

## 1. Khởi tạo Project trên Wokwi
1. Truy cập [Wokwi.com](https://wokwi.com/).
2. Nếu bạn chưa có tài khoản, hãy đăng ký (Sign up) bằng Google hoặc GitHub để lưu dự án vĩnh viễn.
3. Ở trang chủ, bấm vào phần **Start from Scratch**, chọn vi điều khiển là **ESP32** (không phải ESP32-C3 hay S2 nhé).

## 2. Nạp cấu hình mạch điện (Diagram)
Thay vì ngồi kéo thả từng linh kiện, bạn chỉ cần dán file cấu hình:
1. Nhìn lên màn hình Wokwi, bạn sẽ thấy 2 tab chính là `sketch.ino` và `diagram.json`.
2. Bấm sang tab **`diagram.json`**.
3. Copy toàn bộ nội dung từ file [diagram.json](../../wokwi/diagram.json) trong máy tính của bạn, xóa nội dung cũ trên Wokwi đi và **Dán (Paste)** vào.
4. Ngay lập tức, bên khung mạch điện sẽ tự động vẽ ra:
   - Vi điều khiển ESP32
   - 1 Bóng đèn LED đỏ (đại diện cho bóng đèn phòng)
   - 1 Quang trở LDR (cảm biến ánh sáng)
   - Điện trở bảo vệ mạch

## 3. Nạp mã nguồn và Thư viện
1. Bấm sang tab **`sketch.ino`** trên Wokwi.
2. Copy toàn bộ nội dung từ file [sketch.ino](../../wokwi/sketch/sketch.ino) trong máy tính của bạn, xóa code cũ trên Wokwi và **Dán (Paste)** vào.
3. **Quan trọng: Thêm thư viện Blynk.** 
   - Trên Wokwi, bấm vào thẻ **Library Manager** (biểu tượng cuốn sách) hoặc bấm nút `+` cạnh tên file `sketch.ino`.
   - Chọn "Add a new library...".
   - Gõ chữ `Blynk` vào ô tìm kiếm và chọn thư viện **Blynk** của Volodymyr Shymanskyy. (Nếu không làm bước này, Wokwi sẽ báo lỗi không tìm thấy `BlynkSimpleEsp32.h` ở dòng 30).
4. Kéo lên đầu file `sketch.ino`, bạn sẽ thấy khu vực **CẤU HÌNH API VÀ WIFI**. Tại đây, bạn sẽ phải thay thế các đoạn chữ `REPLACE_WITH_...` bằng các Token thật lấy từ Blynk và ThingSpeak (tôi sẽ hướng dẫn lấy chúng ở file số 03 và 04).
   > *Tạm thời bạn cứ giữ nguyên đó, sau khi đọc xong bài 03 và 04 hãy quay lại thay đổi.*

## 4. Chạy và quan sát mô phỏng
- Sau khi đã điền đủ Token, bấm nút **Play** (biểu tượng ▶️ màu xanh lá cây) ở góc trên khung mạch điện.
- Đợi khoảng vài giây để hệ thống biên dịch.
- Nhìn xuống cửa sổ **Serial Monitor** (cửa sổ đen bên dưới mạch điện). Nếu thấy các dòng chữ báo `Connecting to Blynk...` và `Blynk is connected` thì chúc mừng bạn, ESP32 ảo đã lên mạng thành công!
- **Thao tác tay:** Bấm chuột vào cảm biến ánh sáng LDR trên mạch, Wokwi sẽ hiện ra một thanh trượt mô phỏng độ sáng (Lux). Kéo thanh trượt để thay đổi ánh sáng và theo dõi xem hệ thống AI của bạn có phản ứng tự động bật tắt đèn hay không.
