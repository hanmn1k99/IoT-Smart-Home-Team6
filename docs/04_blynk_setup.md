# 04. Hướng dẫn thiết lập Blynk

Blynk là nền tảng giúp bạn tạo App điều khiển trên điện thoại và Dashboard trên Web cực kỳ nhanh chóng.

## 1. Tạo Template (Khuôn mẫu)
1. Đăng nhập vào [Blynk Cloud](https://blynk.cloud/).
2. Nhấn vào mục **Templates** (biểu tượng hình vuông kẻ ô vuông) -> **New Template**.
3. Khai báo:
   - Name: `Smart Lighting`
   - Hardware: `ESP32`
   - Connection: `WiFi`
4. Bấm **Done** để tạo.

## 2. Tạo Datastreams (Kênh dữ liệu)
Chuyển sang tab **Datastreams** bên trong Template vừa tạo. Bạn cần tạo 2 kênh giao tiếp:
1. Chọn **New Datastream** -> **Virtual Pin**.
   - Name: `Light Switch`
   - Pin: `V0`
   - Data Type: `Integer`
   - Min: `0`, Max: `1`. Bấm Create.
2. Chọn **New Datastream** -> **Virtual Pin**.
   - Name: `Light Sensor`
   - Pin: `V1`
   - Data Type: `Integer`
   - Min: `0`, Max: `4095`. Bấm Create.
3. Bấm **Save** ở góc trên cùng bên phải màn hình.

## 3. Tạo Thiết bị (Device) và lấy Token
1. Nhấn vào mục **Devices** (biểu tượng Kính lúp) -> **New Device** -> **From template**.
2. Chọn Template `Smart Lighting` bạn vừa làm, đặt tên cho thiết bị rồi bấm **Create**.
3. Trên màn hình sẽ xuất hiện một bảng đen chứa 3 dòng code bắt đầu bằng `#define`. Đó là **Template ID, Template Name** và **Auth Token**.
4. **Cấu hình ESP32:** Copy 3 dòng đó. Mở file `sketch.ino`, tìm phần CẤU HÌNH ở đầu file và dán đè lên phần cấu hình Blynk cũ.
5. **Cấu hình AI Node.js:** Copy riêng mã chuỗi của **Auth Token**. Mở file `.env` và dán vào biến `BLYNK_AUTH_TOKEN`.

## 4. Thiết kế giao diện trên điện thoại
- Cài App **Blynk IoT** trên điện thoại.
- Đăng nhập, mở thiết bị của bạn.
- Bấm vào biểu tượng cờ lê (Cài đặt góc phải trên cùng), ấn dấy `+` để thêm các **Widget**.
- Thêm 1 cái **Button**, gán nó vào Datastream `V0` (Dùng để ấn tắt/bật đèn).
- Thêm 1 cái **Gauge**, gán nó vào Datastream `V1` (Dùng để xem mức sáng tối thực tế).
