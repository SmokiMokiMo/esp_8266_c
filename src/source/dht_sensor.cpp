#include "headers/dht_sensor.h"
#include "headers/lcd.h"

DHT dht(DHT_PIN, DHT_TYPE);

void dht_init() {
  dht.begin();
  sendToLCD("DHT11 Started!");

}

SensorData measureTempAndHumid(bool lcdMesSend) {
  SensorData data;
  data.temperature = dht.readTemperature();
  data.humidity = dht.readHumidity();
  

  return data;
}