# 02. Hướng dẫn thiết lập trên Wokwi

## 1. Khởi tạo Project
1. Vào [Wokwi](https://wokwi.com/), chọn tạo dự án ESP32 mới.
2. Sao chép nội dung file `wokwi/diagram.json` đè lên file diagram của bạn để tạo linh kiện.

## 2. Nạp mã nguồn
1. Mở file `wokwi/sketch/config.h`, điền các tham số API Key của bạn (nếu đã có). Nếu chưa, bạn có thể thực hiện sau ở các bài hướng dẫn Blynk/ThingSpeak.
2. Copy toàn bộ code trong `wokwi/sketch/sketch.ino` và dán vào tab code bên trái của Wokwi (phải giữ `config.h` cùng chung 1 thư mục/tab trên Wokwi nếu có thể, hoặc gộp toàn bộ `#define` vào đầu file `.ino` nếu Wokwi không hỗ trợ nhiều tab).
   > *Tip: Trên Wokwi, bấm mũi tên nhỏ cạnh tên file `sketch.ino` chọn "New File" và đặt tên là `config.h`, sau đó copy code vào.*

## 3. Khởi động
- Bấm nút Play màu xanh lá để chạy mô phỏng. 
- ESP32 sẽ hiển thị trong Serial Monitor việc kết nối tới WiFi (Wokwi-GUEST) và Blynk.
