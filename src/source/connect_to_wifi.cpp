#include "headers/connect_to_wifi.h"
#include <vector>


std::vector<WiFicredentials> wifiVector = {
    {"Smka", "74617461smka"},
    {"Boosteroid 2G", "YourDeviceOurPower"}
};

void connectToWiFi() {
    for (const auto &cred : wifiVector) {
        int i = 0;
        WiFi.begin(cred.ssid, cred.password);
        while (i < 5) {            
            delay(1000);

            if (WiFi.status() == WL_CONNECTED) {
                Serial.print("Connected to SSID: ");
                Serial.println(cred.ssid);
                sendToLCD("Connected to ... ", cred.ssid);
                return;
            }

            Serial.print("Try connect to SSID: ");
            Serial.print(cred.ssid);
            Serial.print(". Retrying- ");
            Serial.println(i);
            sendToLCD("Try connect to:", cred.ssid);
            i++;
        }
    }
    sendToLCD("WiFi Failed!!!", "Stop Program!!");
    Serial.println("Failed connect to Wifi");
    delay(5000);
    exit(EXIT_FAILURE);
}