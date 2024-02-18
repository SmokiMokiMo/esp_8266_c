#include <ESP8266WiFi.h>
#include "headers/connect_to_wifi.h"

void connectToWiFi() {
    const char* ssid = "Smka";
    const char* password = "74617461smka";

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}
