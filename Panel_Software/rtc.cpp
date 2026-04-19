#include "rtc.h"
#include "config.h"
#include <Wire.h>

#define DS1307_ADDRESS 0x68

ClockTime rtcTime = {};

byte bcdToDec(byte val) {
  return ((val / 16 * 10) + (val % 16));
}

void initRTC() {
  Wire.begin(PIN_SDA, PIN_SCL);
}

void readRTC() {

  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);

  rtcTime.second = bcdToDec(Wire.read() & 0x7F);
  rtcTime.minute = bcdToDec(Wire.read());
  rtcTime.hour   = bcdToDec(Wire.read());
  Wire.read(); // dayOfWeek
  rtcTime.day   = bcdToDec(Wire.read());
  rtcTime.month = bcdToDec(Wire.read());
  rtcTime.year  = bcdToDec(Wire.read());
}
