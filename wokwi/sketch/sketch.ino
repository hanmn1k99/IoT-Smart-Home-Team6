// ==========================================
// CẤU HÌNH API VÀ WIFI (Sửa các thông số ở đây)
// ==========================================

// --- BLYNK CLOUD CONFIGURATION ---
#define BLYNK_TEMPLATE_ID "REPLACE_WITH_YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "REPLACE_WITH_YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "REPLACE_WITH_YOUR_AUTH_TOKEN"

// --- WIFI CONFIGURATION ---
#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""

// --- THINGSPEAK CONFIGURATION ---
#define THINGSPEAK_SERVER "api.thingspeak.com"
#define THINGSPEAK_API_KEY "REPLACE_WITH_THINGSPEAK_WRITE_API_KEY"

// --- HARDWARE PINS ---
#define LED_PIN 2       // Đèn LED (thay cho Relay/Đèn)
#define LDR_PIN 36      // VP - Cảm biến ánh sáng quang trở (LDR)

// ==========================================
// MÃ NGUỒN CHÍNH
// ==========================================

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <HTTPClient.h>

BlynkTimer timer;

int lightStatus = 0;
int ldrValue = 0;

// Nhận lệnh bật tắt từ Blynk (Nút nhấn ở V0)
BLYNK_WRITE(V0) {
  lightStatus = param.asInt();
  digitalWrite(LED_PIN, lightStatus);
  Serial.print("Blynk command received. Light is now: ");
  Serial.println(lightStatus ? "ON" : "OFF");
}

// Hàm gửi dữ liệu lên ThingSpeak mỗi 15 giây
void sendDataToThingSpeak() {
  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "http://" + String(THINGSPEAK_SERVER) + "/update?api_key=" + String(THINGSPEAK_API_KEY) + "&field1=" + String(lightStatus) + "&field2=" + String(ldrValue);
    
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.println("Data sent to ThingSpeak successfully.");
    } else {
      Serial.println("Error sending to ThingSpeak.");
    }
    http.end();
  }
}

// Đọc cảm biến liên tục
void readSensors() {
  ldrValue = analogRead(LDR_PIN);
  Blynk.virtualWrite(V1, ldrValue); // Gửi độ sáng lên Blynk V1
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  digitalWrite(LED_PIN, LOW);

  Serial.println("Connecting to Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASSWORD);

  // Đặt timer
  timer.setInterval(2000L, readSensors); // Đọc LDR 2s/lần
  timer.setInterval(15000L, sendDataToThingSpeak); // Gửi ThingSpeak 15s/lần
}

void loop() {
  Blynk.run();
  timer.run();
}
