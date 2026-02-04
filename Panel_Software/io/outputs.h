#ifndef OUTPUTS_H
#define OUTPUTS_H

#include <Arduino.h>

// Estructura para salidas digitales
struct DigitalOutputs {
  bool relay1;
  bool relay2;
  bool relay3;
  bool relay4;
};

extern DigitalOutputs outputs;

// Inicialización
void initOutputs();

// Aplicar estados a hardware
void updateOutputs();

// Funciones individuales (opcional)
void setRelay(uint8_t relayNumber, bool state);

#endif
