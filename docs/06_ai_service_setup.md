# 06. Hướng dẫn chạy AI Service

## 1. Cài đặt Node.js
- Đảm bảo máy tính đã cài Node.js (phiên bản 18 trở lên).
- Cài đặt các thư viện cần thiết bằng lệnh:
```bash
cd ai_service
npm install
```

## 2. Thiết lập môi trường
- Tạo file `.env` từ file `.env.example` hoặc copy trực tiếp file `.env.example` vào thư mục `ai_service/`.
- Thay thế các thông số API Key của ThingSpeak và Auth Token của Blynk vào file `.env`.

## 3. Khởi chạy
- Mở terminal trong thư mục `ai_service` và chạy lệnh:
```bash
npm start
```
- Module AI sẽ bắt đầu chạy, kết nối đến ThingSpeak lấy dữ liệu mỗi 30 giây, kết hợp phân tích múi giờ Việt Nam và in log ra màn hình, tự động bật tắt đèn nếu cần thiết.
