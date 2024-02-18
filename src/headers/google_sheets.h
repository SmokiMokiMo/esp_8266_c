#ifndef GOOGLE_SHEETS_H
#define GOOGLE_SHEETS_H

#include "HTTPSRedirect.h"

extern const char *GScriptId;
extern String payload_base;
extern String payload;
extern const char* host;
extern const int httpsPort;
extern const char* fingerprint;
extern String url;
extern HTTPSRedirect* client;
extern const char* val0;
extern int val1;
extern int val2;

void connectToSheets();
void esp_arduion_sheet(const char* val0, int val1, int val2);

#endif