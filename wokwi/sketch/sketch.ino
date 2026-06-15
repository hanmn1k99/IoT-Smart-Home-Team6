#include "config.h"

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

  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASSWORD);

  // Đặt timer
  timer.setInterval(2000L, readSensors);
  timer.setInterval(15000L, sendDataToThingSpeak); // ThingSpeak free giới hạn 15s/lần
}

void loop() {
  Blynk.run();
  timer.run();
}
