# 03. Hướng dẫn thiết lập ThingSpeak

ThingSpeak sẽ đóng vai trò như bộ nhớ đám mây của dự án, lưu trữ mọi thay đổi về ánh sáng và trạng thái của đèn để AI có thể lấy ra phân tích.

## 1. Đăng ký và Tạo Channel
1. Truy cập [ThingSpeak.com](https://thingspeak.com/) và tạo tài khoản (nếu chưa có).
2. Tại màn hình chính, nhấn vào nút **New Channel**.
3. Điền thông tin cho Channel:
   - **Name:** `Smart Lighting History`
   - Đánh dấu tích vào **Field 1**, đặt tên là: `Light Status` (Trạng thái đèn: 0 là Tắt, 1 là Bật).
   - Đánh dấu tích vào **Field 2**, đặt tên là: `LDR Value` (Giá trị cảm biến độ sáng từ ESP32).
4. Cuộn xuống cuối trang và nhấn **Save Channel**.

## 2. Lấy API Keys để kết nối
Để ESP32 có thể gửi dữ liệu lên ThingSpeak, và Node.js AI lấy được dữ liệu về, bạn cần các chuỗi mã khóa (API Key).

1. Sau khi tạo Channel, chuyển sang tab **API Keys**.
2. **Cho ESP32:**
   - Copy đoạn mã ở dòng **Write API Key**.
   - Mở file `sketch.ino`, tìm khu vực CẤU HÌNH ở đầu file.
   - Dán đè mã vừa copy vào vị trí `REPLACE_WITH_THINGSPEAK_WRITE_API_KEY`.
3. **Cho Node.js AI:**
   - Copy đoạn mã ở dòng **Read API Key**.
   - Copy số **Channel ID** (nằm ngay dưới tiêu đề tên Channel của bạn).
   - Mở file `.env` trong project Node.js và dán chúng vào 2 biến `THINGSPEAK_READ_API_KEY` và `THINGSPEAK_CHANNEL_ID`.
