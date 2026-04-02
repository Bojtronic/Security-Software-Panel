#include <Wire.h>

#define DS1307_ADDRESS 0x68

byte bcdToDec(byte val) {
  return ((val / 16 * 10) + (val % 16));
}

void setup() {
  Wire.begin(21, 22);
  Serial.begin(115200);
}

void loop() {
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);

  int second = bcdToDec(Wire.read() & 0x7F);
  int minute = bcdToDec(Wire.read());
  int hour   = bcdToDec(Wire.read());
  int dayOfWeek = bcdToDec(Wire.read());
  int day   = bcdToDec(Wire.read());
  int month = bcdToDec(Wire.read());
  int year  = bcdToDec(Wire.read());

  Serial.print("Fecha: ");
  Serial.print(day);
  Serial.print("/");
  Serial.print(month);
  Serial.print("/20");
  Serial.print(year);

  Serial.print("  Hora: ");
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(second);

  delay(1000);
}
