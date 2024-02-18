#include <NTPClient.h>
#include <WiFiUdp.h>
#include "headers/time.h"

WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "pool.ntp.org");

void timeInit(){
    timeClient.begin();  // Initialize NTPClient
    timeClient.setTimeOffset(2 * 3600); // Adjust time zone offset (in seconds)
    timeClient.update();
    delay(300);
    // Attempt to update the time from the NTP server
    if (!timeClient.update()) {
        Serial.println("Failed to update time from NTP server. Check your internet connection.");        
    } else {
        Serial.println("Time updated successfully.");
    }
}

// Get current time components
DateTime getTime(){  
    
    time_t rawTime = timeClient.getEpochTime();
    Serial.print("Raw Epoch Time: " );
    Serial.println(rawTime);
    struct tm *timeinfo = localtime(&rawTime);
    
    DateTime dateTime;
    dateTime.formattedDate = ("[" + String(timeinfo->tm_year + 1900) + "." +
                           String(timeinfo->tm_mon + 1 < 10 ? "0" : "") + String(timeinfo->tm_mon + 1) + "." +
                           String(timeinfo->tm_mday < 10 ? "0" : "") + String(timeinfo->tm_mday) + "]");

    dateTime.formattedTime = (String(timeinfo->tm_hour < 10 ? "0" : "") + String(timeinfo->tm_hour) + ":" +
                           String(timeinfo->tm_min < 10 ? "0" : "") + String(timeinfo->tm_min) + ":" +
                           String(timeinfo->tm_sec < 10 ? "0" : "") + String(timeinfo->tm_sec));
    return dateTime;
}