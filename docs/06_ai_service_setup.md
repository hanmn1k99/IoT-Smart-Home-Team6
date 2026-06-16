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

## 3. Khởi chạy (Cách thông thường)
- Mở terminal trong thư mục `ai_service` và chạy lệnh:
```bash
npm start
```
- Module AI sẽ bắt đầu chạy, kết nối đến ThingSpeak lấy dữ liệu mỗi 30 giây, kết hợp phân tích múi giờ Việt Nam và in log ra màn hình, tự động bật tắt đèn nếu cần thiết.

## 4. Khởi chạy trên VPS bằng Docker (Khuyên dùng)
Nếu bạn có VPS và muốn triển khai chuyên nghiệp, dự án đã có sẵn `docker-compose`. Ưu điểm là dễ dàng quản lý, chạy ngầm 24/7 và xóa sạch sành sanh chỉ với 1 câu lệnh khi hết môn học.

1. Tại VPS, clone dự án và tạo file `.env` như bước 2.
2. Di chuyển ra thư mục gốc (nơi chứa file `docker-compose.yml`), chạy lệnh:
```bash
docker compose up -d
```
3. Xem log chạy thực tế của AI:
```bash
docker logs -f iot-ai-service
```
4. Khi bảo vệ đồ án xong, để xóa hoàn toàn tiến trình và dọn dẹp bộ nhớ:
```bash
docker compose down --rmi all
```
