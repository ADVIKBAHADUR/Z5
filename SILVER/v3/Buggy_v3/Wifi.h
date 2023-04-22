#ifndef WIFI_H
#define WIFI_H
#include <WiFiNINA.h>
#include <Arduino.h>
#include <string>

void connect();
String readMessages();
String writeMessages(const char *msg);
#endif