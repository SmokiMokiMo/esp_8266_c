// azure_iot_hub_client.cpp
/*#include "headers/azure_iot_hub_client.h"



// const char* connectionString = "https://dht11sensor3.azure-devices.net;DeviceId=7t7l177q9g;SharedAccessKey=7BijWFEBwBPv5zBKBkwDkLEykU8/XBvtYgwURoRPK+4=";


const char* SCOPE_ID = "0ne00BFF51A";
const char* DEVICE_ID = "7t7l177q9g";
const char* DEVICE_KEY = "7BijWFEBwBPv5zBKBkwDkLEykU8/XBvtYgwURoRPK+4=";

void on_event(IOTContext ctx, IOTCallbackInfo* callbackInfo) {
  // ConnectionStatus
  if (strcmp(callbackInfo->eventName, "ConnectionStatus") == 0) {
    LOG_VERBOSE("Is connected ? %s (%d)",
                callbackInfo->statusCode == IOTC_CONNECTION_OK ? "YES" : "NO",
                callbackInfo->statusCode);
    isConnected = callbackInfo->statusCode == IOTC_CONNECTION_OK;
    return;
  }

  // payload buffer doesn't have a null ending.
  // add null ending in another buffer before print
  AzureIOT::StringBuffer buffer;
  if (callbackInfo->payloadLength > 0) {
    buffer.initialize(callbackInfo->payload, callbackInfo->payloadLength);
  }

  LOG_VERBOSE("- [%s] event was received. Payload => %s\n",
              callbackInfo->eventName, buffer.getLength() ? *buffer : "EMPTY");

  if (strcmp(callbackInfo->eventName, "Command") == 0) {
    LOG_VERBOSE("- Command name was => %s\r\n", callbackInfo->tag);
  }
}
*/