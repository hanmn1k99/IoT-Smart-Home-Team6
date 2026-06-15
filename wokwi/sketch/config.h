#ifndef CONFIG_H
#define CONFIG_H

// --- BLYNK CLOUD CONFIGURATION ---
// Thay thế bằng thông tin từ Blynk Template của bạn
#define BLYNK_TEMPLATE_ID "REPLACE_WITH_YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "REPLACE_WITH_YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "REPLACE_WITH_YOUR_AUTH_TOKEN"

// --- WIFI CONFIGURATION ---
// Dùng Wokwi-GUEST cho giả lập Wokwi
#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""

// --- THINGSPEAK CONFIGURATION ---
// Thay thế bằng Write API Key của Channel ThingSpeak
#define THINGSPEAK_SERVER "api.thingspeak.com"
#define THINGSPEAK_API_KEY "REPLACE_WITH_THINGSPEAK_WRITE_API_KEY"

// --- HARDWARE PINS ---
#define LED_PIN 2       // Đèn
#define LDR_PIN 36      // VP - Cảm biến ánh sáng

#endif // CONFIG_H
