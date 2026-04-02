#include <Wire.h>

#define DS1307_ADDRESS 0x68

byte decToBcd(byte val) {
  return ((val / 10 * 16) + (val % 10));
}

void setup() {
  Wire.begin(21, 22); // SDA, SCL

  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(0x00); // Registro inicial

  // CONFIGURA AQUÍ LA FECHA Y HORA
  Wire.write(decToBcd(0));   // Segundos (0-59)
  Wire.write(decToBcd(30));  // Minutos (0-59)
  Wire.write(decToBcd(14));  // Hora (0-23)
  Wire.write(decToBcd(3));   // Día de la semana (1=Lunes, opcional)
  Wire.write(decToBcd(2));   // Día del mes (1-31)
  Wire.write(decToBcd(4));   // Mes (1-12)
  Wire.write(decToBcd(26));  // Año (00-99 → 2026)

  Wire.endTransmission();

  Serial.begin(115200);
  Serial.println("Hora y fecha configuradas");
}

void loop() {
}