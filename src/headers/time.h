#ifndef TIME_H
#define TIME_H

#include <NTPClient.h>
#include <WiFiUdp.h>

struct DateTime {
    String formattedDate;
    String formattedTime;
};

extern WiFiUDP ntpUDP;

void timeInit();
DateTime getTime();
#endif // TIME_H