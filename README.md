# 🏠 Cloud Smart Home – Hệ Thống Đèn Thông Minh (IoT)

<div align="center">

![ESP32](https://img.shields.io/badge/ESP32-Arduino-blue?style=for-the-badge&logo=arduino)
![Node.js](https://img.shields.io/badge/Node.js-20-green?style=for-the-badge&logo=nodedotjs)
![ThingSpeak](https://img.shields.io/badge/ThingSpeak-Cloud-009639?style=for-the-badge&logo=mathworks)
![Blynk](https://img.shields.io/badge/Blynk-IoT-1B9C85?style=for-the-badge)
![Google Home](https://img.shields.io/badge/Google-Home-4285F4?style=for-the-badge&logo=google)
![IFTTT](https://img.shields.io/badge/IFTTT-Automation-black?style=for-the-badge&logo=ifttt)
![Author](https://img.shields.io/badge/Author-nh%C3%B3m%205%20D23TXCN06--K-blueviolet?style=for-the-badge&logo=github)

**Hệ thống nhà thông minh – Điều khiển đèn bằng giọng nói, ứng dụng Blynk và AI tự động bật/tắt theo ánh sáng/thời gian thực (Node.js)**

👤 **Tác giả**: Nhóm 5 D23TXCN06-K

[📖 Tài Liệu](#-tài-liệu) · [🚀 Cài Đặt Nhanh](#-cài-đặt-nhanh) · [❓ Hỏi Đáp](#-hỏi-đáp)

</div>

---
---

👤 **Thông tin nhóm**
| Họ và Tên | Vai Trò |
|---|---|
| Lê Doãn Minh | Đốc công kiêm tester| 
| Hồ Lâm Sơn | 10 vạn câu hỏi |
| Trần Duy Vũ Anh | Dev chính |
| Nguyễn Minh Hân | Dev lỏ |

---

## 📋 Mục Lục

- [Giới Thiệu](#-giới-thiệu)
- [Tính Năng](#-tính-năng)
- [Kiến Trúc Hệ Thống](#-kiến-trúc-hệ-thống)
- [Yêu Cầu](#-yêu-cầu)
- [Cài Đặt Nhanh](#-cài-đặt-nhanh)
- [Cấu Hình Chi Tiết](#-cấu-hình-chi-tiết)
- [Cấu Trúc Project](#-cấu-trúc-project)
- [Tài Liệu](#-tài-liệu)
- [Hỏi Đáp](#-hỏi-đáp)

---

## 🌟 Giới Thiệu

**Cloud Smart Home** là hệ thống điều khiển bóng đèn thông minh sử dụng sức mạnh của các dịch vụ đám mây (ThingSpeak, Blynk). Hệ thống kết hợp với **Google Assistant qua IFTTT** để điều khiển bằng giọng nói, đồng thời được trang bị một module **AI viết bằng Node.js** để tự động phân tích thời gian và ánh sáng môi trường.

> 💡 **Giả lập phần cứng** bằng [Wokwi](https://wokwi.com) – không cần mua phần cứng ESP32 hay relay để bắt đầu!

---

## ✨ Tính Năng

| Tính Năng | Mô Tả |
|---|---|
| 🎙️ **Giọng nói** | "Hey Google, bật đèn phòng khách" qua IFTTT |
| 📱 **Blynk App** | Điều khiển mọi lúc mọi nơi bằng App trên điện thoại |
| ☁️ **ThingSpeak** | Lưu trữ lịch sử hoạt động và dữ liệu cảm biến |
| 🤖 **AI Node.js** | Tự động hóa dựa vào giờ Việt Nam (UTC+7) và dữ liệu quang trở |
| ⚡ **Wokwi** | Mô phỏng chính xác mạch ESP32 và cảm biến |
| 🌐 **Tích hợp Cloud**| Hệ thống phân tán, ổn định và dễ mở rộng |

---

## 🏗️ Kiến Trúc Hệ Thống

```
┌────────────────────────────────────────────────────────┐
│                    GOOGLE CLOUD                        │
│   [Google Assistant] ──► [IFTTT Webhooks]              │
└─────────────────────────────────┬──────────────────────┘
                                  │ HTTPS API
                    ┌─────────────▼──────────────────┐
                    │       Blynk Cloud (IoT)         │
                    │   - Quản lý trạng thái đèn      │
                    │   - Điều khiển qua App/Web      │
                    └──────┬──────────────▲───────────┘
                           │              │ HTTPS API
              ┌────────────▼──┐    ┌──────┴──────────┐
              │  Wokwi ESP32  │    │  Node.js        │
              │  (Phần cứng)  │    │  (AI Service)   │
              │  + Đèn LED    │    │  - Time Zone    │
              │  + Cảm biến   │    │  - Logic Bật/Tắt│
              └──────┬────────┘    └──────▲──────────┘
                     │                    │ JSON API
                     │ HTTP GET           │
              ┌──────▼────────────────────┴──────┐
              │          ThingSpeak              │
              │  - Lưu trữ Lịch sử               │
              │  - Phân tích dữ liệu             │
              └──────────────────────────────────┘
```

### Stack Công Nghệ

| Layer | Công Nghệ |
|---|---|
| **Phần cứng** | ESP32 trên [Wokwi](https://wokwi.com) |
| **Data Cloud** | ThingSpeak (MathWorks) |
| **Control App** | Blynk IoT |
| **Voice Control** | Google Assistant + IFTTT |
| **AI Module** | Node.js (Axios, dayjs) |

---

## 📦 Yêu Cầu

### Môi trường chạy AI
- **Node.js** bản 18+ (Dành cho Developer, tương thích với team React)
- NPM hoặc Yarn

### Dịch vụ Đám mây
- [Wokwi](https://wokwi.com) (miễn phí)
- [Blynk Cloud](https://blynk.cloud/)
- [ThingSpeak](https://thingspeak.com/)
- [IFTTT](https://ifttt.com/)

---

## 🚀 Cài Đặt Nhanh

### 1. Cấu hình môi trường Node.js (AI Service)

```bash
git clone <địa_chỉ_repo_này> iot-smart-lighting
cd iot-smart-lighting/ai_service

# Cài đặt thư viện
npm install

# Cấu hình biến môi trường
cp ../.env.example .env
nano .env  # Điền các Token và API Key
```

### 2. Khởi động phần cứng trên Wokwi

1. Copy toàn bộ code trong `wokwi/sketch/` vào dự án mới trên Wokwi.
2. Sửa thông tin WiFi (mặc định `Wokwi-GUEST`) và các Token trong `config.h`.
3. Copy `diagram.json` để có sẵn cấu hình linh kiện.
4. Nhấn **Play** để khởi động ESP32.

### 3. Chạy AI Service

Bạn có thể chạy trực tiếp bằng Node.js:
```bash
cd ai_service
npm start
```

**Hoặc chạy bằng Docker (Khuyên dùng cho VPS):**
```bash
docker compose up -d
# Chạy ngầm 24/7. Xem log bằng lệnh: docker logs -f iot-ai-service
# Khi đồ án kết thúc, xóa sạch bằng lệnh: docker compose down --rmi all
```

---

## ⚙️ Cấu Hình Chi Tiết

### Biến Môi Trường (`.env` tại thư mục root)

```env
# ThingSpeak Configuration
THINGSPEAK_READ_API_KEY=your_read_api_key_here
THINGSPEAK_CHANNEL_ID=1234567

# Blynk Configuration
BLYNK_AUTH_TOKEN=your_blynk_auth_token_here
```

### Cấu Hình ESP32 (`wokwi/sketch/config.h`)

```cpp
// Blynk
#define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
#define BLYNK_TEMPLATE_NAME "Smart Lighting"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxx"

// ThingSpeak
#define THINGSPEAK_API_KEY "xxxxxxxxxxxx"

// GPIO pins
#define LED_PIN 2    // Đèn phòng
#define LDR_PIN 36   // Cảm biến ánh sáng
```

---

## 📁 Cấu Trúc Project

```
iot-smart-lighting/
│
├── .env.example                # Template biến môi trường
├── README.md                   # Tài liệu chính
│
├── ai_service/                 # Node.js AI Module
│   ├── package.json
│   └── src/
│       ├── index.js            # Vòng lặp tự động hóa chính
│       ├── thingspeak.js       # Module đọc dữ liệu ThingSpeak
│       └── blynk.js            # Module điều khiển thiết bị qua Blynk
│
├── wokwi/                      # Cấu hình phần cứng Wokwi
│   ├── diagram.json            # Sơ đồ đấu nối (ESP32 + LED + LDR)
│   ├── wokwi.toml
│   └── sketch/
│       ├── sketch.ino          # Firmware điều khiển thiết bị
│       └── config.h            # File cấu hình GPIO và API Keys
│
└── docs/                       # Tài liệu hướng dẫn step-by-step
    ├── 01_architecture.md
    ├── 02_wokwi_setup.md
    ├── 03_thingspeak_setup.md
    ├── 04_blynk_setup.md
    ├── 05_ifttt_google_home.md
    └── 06_ai_service_setup.md
```

---

## 📖 Tài Liệu

| Tài Liệu | Mô Tả |
|---|---|
| [docs/01_architecture.md](docs/01_architecture.md) | Giải thích tổng quan về kiến trúc và luồng dữ liệu. |
| [docs/02_wokwi_setup.md](docs/02_wokwi_setup.md) | Cách nạp code và chạy mô phỏng. |
| [docs/03_thingspeak_setup.md](docs/03_thingspeak_setup.md) | Cách lưu dữ liệu lên đám mây. |
| [docs/04_blynk_setup.md](docs/04_blynk_setup.md) | Thiết lập Dashboard và App điều khiển. |
| [docs/05_ifttt_google_home.md](docs/05_ifttt_google_home.md)| Liên kết Google Assistant để điều khiển giọng nói. |
| [docs/06_ai_service_setup.md](docs/06_ai_service_setup.md) | Cài đặt và chạy Node.js AI Service. |

---

## ❓ Hỏi Đáp

<details>
<summary><b>Tại sao dùng Node.js cho AI Module?</b></summary>

Bởi vì Node.js có kiến trúc non-blocking I/O mạnh mẽ, phù hợp với việc gọi API liên tục tới ThingSpeak và Blynk. Đồng thời, do team có Developer chuyên về React/JS, việc sử dụng Node.js giúp team bảo trì mã nguồn dễ dàng hơn so với Python.
</details>

<details>
<summary><b>Cách điều khiển bằng Google Assistant?</b></summary>

Dự án sử dụng IFTTT để lắng nghe câu lệnh từ Google Assistant (ví dụ "Bật đèn"). IFTTT sẽ tạo một Webhook gọi đến API của Blynk, và Blynk sẽ đẩy lệnh điều khiển xuống mạch ESP32.
</details>

---

<div align="center">

## 👤 Đồ Án Kết Thúc Môn Học IoT
### ⭐ Giảng Viên Hướng Dẫn: ThS. Phan Thanh Hy ⭐
#### Hỗ trợ dự án: [Nguyễn Mnh Hân](https://minhhan.net)

⭐ **Hãy khám phá các thư mục `docs/` để tiến hành cài đặt dự án!** ⭐

</div>
