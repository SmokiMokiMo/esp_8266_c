#include "headers/dht_sensor.h"

DHT dht(DHT_PIN, DHT_TYPE);

void dht_init() {
  dht.begin();
}

SensorData measureTempAndHumid() {
  SensorData data;
  data.temperature = dht.readTemperature();
  data.humidity = dht.readHumidity();
  return data;
}
