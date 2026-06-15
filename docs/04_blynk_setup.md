# 04. Hướng dẫn thiết lập Blynk

## 1. Tạo Template
1. Truy cập [Blynk Cloud](https://blynk.cloud/).
2. Tạo Template mới: Hardware là ESP32, Connection là WiFi.
3. Trong tab **Datastreams**, tạo:
   - Datastream 1: Virtual Pin V0, Data Type Integer (Công tắc bật/tắt).
   - Datastream 2: Virtual Pin V1, Data Type Integer (Cảm biến).

## 2. Tạo Thiết bị
1. Tạo Device mới từ Template vừa lập.
2. Sao chép khối Template ID, Template Name, Auth Token.
3. Dán chúng vào phần đầu file `config.h` (ESP32) và điền `BLYNK_AUTH_TOKEN` vào file `.env` (Node.js AI).

## 3. Thiết kế giao diện
- Tải App Blynk IoT trên điện thoại hoặc dùng Web Dashboard, kéo thả một Button gán vào chân V0 và một Gauge gán vào chân V1 để quan sát trực quan.
