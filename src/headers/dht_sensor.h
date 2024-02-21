#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <DHT.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11

struct SensorData {
  int temperature;
  int humidity;
};

extern DHT dht;  // Declare the DHT instance

void dht_init();
SensorData measureTempAndHumid(bool lcdMesSend = false);

#endif // TIME_H