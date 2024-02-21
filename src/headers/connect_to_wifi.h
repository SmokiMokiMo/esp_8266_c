#ifndef CONNECT_TO_WIFI_H
#define CONNECT_TO_WIFI_H

#include <ESP8266WiFi.h>
#include "headers/lcd.h"
#include <cstdlib>

struct WiFicredentials {
    const char* ssid;
    const char* password;
};


void connectToWiFi();

#endif