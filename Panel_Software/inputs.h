#ifndef INPUTS_H
#define INPUTS_H

#include <Arduino.h>

// Estructura para entradas digitales
struct DigitalInputs {
  bool sensorIn;
  bool sensorOut;
  bool button1;
  bool button2;
  bool button3;
};

extern DigitalInputs inputs;

// Inicialización
void initInputs();

// Lectura de entradas
void readInputs();

#endif
