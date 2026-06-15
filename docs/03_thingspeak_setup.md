# 03. Hướng dẫn thiết lập ThingSpeak

## 1. Tạo Channel
1. Truy cập [ThingSpeak](https://thingspeak.com/), tạo tài khoản.
2. Tạo New Channel, đặt tên là `Smart Lighting History`.
3. Kích hoạt Field 1 (Light Status) và Field 2 (LDR Value). Lưu Channel.

## 2. Lấy API Keys
1. Mở tab **API Keys** của Channel vừa tạo.
2. Chép **Write API Key**, thay thế vào biến `THINGSPEAK_API_KEY` trong file `config.h` của ESP32.
3. Chép **Read API Key** và **Channel ID**, thay thế vào file `.env` ở project Node.js.
