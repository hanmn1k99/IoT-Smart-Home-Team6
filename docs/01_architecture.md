# 01. Kiến Trúc và Luồng Dữ Liệu

## Tổng quan
Dự án **Cloud Smart Home** loại bỏ hoàn toàn việc tự host Server và MQTT (Mosquitto) như trước đây, thay vào đó tận dụng 100% sức mạnh của các dịch vụ đám mây (Blynk, ThingSpeak, IFTTT) để tối giản chi phí và thời gian triển khai.

## Các Component chính

1. **Khối phần cứng (Wokwi - ESP32)**
   - Nơi mô phỏng vi điều khiển ESP32 và các thiết bị vật lý.
   - Nhiệm vụ: 
     - Nhận lệnh từ Blynk Cloud để điều khiển bật/tắt đèn LED.
     - Đọc dữ liệu từ quang trở LDR và gửi đều đặn lên ThingSpeak.

2. **Khối đám mây lưu trữ (ThingSpeak)**
   - Đóng vai trò Data Warehouse lưu trữ trạng thái đèn và cường độ sáng.

3. **Khối điều khiển (Blynk)**
   - Đóng vai trò là Remote Control từ xa, giao diện người dùng chính (Mobile App).

4. **Khối Tự động hóa và Trí tuệ (AI Service - Node.js)**
   - Đóng vai trò là "Bộ não" của hệ thống.
   - Node.js lấy dữ liệu từ ThingSpeak, kết hợp với thời gian thực theo múi giờ Việt Nam để đưa ra quyết định bật hay tắt đèn tự động, sau đó gọi trực tiếp API của Blynk.

5. **Khối Giọng nói (Google Home + IFTTT)**
   - Google Assistant tiếp nhận lệnh bằng giọng nói, IFTTT sẽ đóng vai trò là webhook bắn trigger sang API của Blynk.
