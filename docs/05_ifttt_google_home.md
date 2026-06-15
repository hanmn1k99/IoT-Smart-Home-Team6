# 05. Hướng dẫn thiết lập IFTTT và Google Home

## 1. Chuẩn bị Webhook của Blynk
- Cú pháp Webhook: `https://blynk.cloud/external/api/update?token=BLYNK_AUTH_TOKEN&v0=VALUE`
- Thay `VALUE` bằng 1 để bật, 0 để tắt.

## 2. Tạo Applet trên IFTTT
1. Đăng nhập [IFTTT](https://ifttt.com/) bằng tài khoản Google (chung tài khoản với Google Assistant trên điện thoại).
2. Tạo Applet mới:
   - **If This:** Chọn **Google Assistant V2**. Chọn trigger phát âm lệnh (vd: "Bật đèn phòng").
   - **Then That:** Chọn **Webhooks** -> Make a web request. 
   - Điền URL của Blynk (với `VALUE=1`). Method chọn `GET`.
3. Tạo thêm một Applet tương tự cho lệnh tắt đèn (với `VALUE=0`).

## 3. Sử dụng
- Bật Google Assistant trên điện thoại và đọc lệnh.
- IFTTT sẽ gọi Webhook và đèn trên Wokwi sẽ phản hồi ngay lập tức.
