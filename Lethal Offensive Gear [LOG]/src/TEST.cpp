#include <WiFi.h>
#include <Arduino.h>

const char* ssid = "ESP32_TEST";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);  // ESP32 creates its own Wi-Fi
  Serial.println("Access Point Started!");
  Serial.print("Connect to Wi-Fi: ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // do nothing
}
