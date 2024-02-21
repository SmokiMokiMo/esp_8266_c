#include <Arduino.h>
#include <Wire.h>


#include "headers/dht_sensor.h"
#include "headers/google_sheets.h"
#include "headers/lcd.h"
#include "headers/connect_to_wifi.h"
#include "headers/time.h"
// #include "headers/azure_iot_hub_client.h"

unsigned long previousMillis = 0;
const long interval = 10000;

void setup() {
  Wire.begin(); // Initialize I2C communication protocol
  Serial.begin(115200); // Initialize and adjust speed for USB communication
  Serial.println("\nI2C Scanner");
  dht_init(); // Initialize DHT11 sensor
  lcd_init(); // Initialize LCD
  pinMode(LED_BUILTIN, OUTPUT); // Turn ON LED on ESP8266
  connectToWiFi(); // Connect to WiFi
  connectToSheets(); // Esteblish connection to goole sheets 
  timeInit();  
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval){

    DateTime formattedTime = getTime();
    SensorData sensorData = measureTempAndHumid(true);
    sendToLCD(("T:" + String(sensorData.temperature) + "-"+"H:" + String(sensorData.humidity)).c_str(),
              String(formattedTime.formattedTime).c_str());    
    esp_arduion_sheet((formattedTime.formattedTime).c_str(), sensorData.temperature, sensorData.humidity);

    //sendSensDataToSheets(sensorData.temperature, sensorData.humidity);
    previousMillis = currentMillis;
  }  
}