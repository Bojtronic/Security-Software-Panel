#ifndef RTC_H
#define RTC_H

#include <Arduino.h>

struct ClockTime {
  uint8_t second;
  uint8_t minute;
  uint8_t hour;
  uint8_t day;
  uint8_t month;
  uint8_t year;
};

extern ClockTime rtcTime;

void initRTC();
void readRTC();

#endif
