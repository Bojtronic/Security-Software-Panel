#ifndef INPUTS_H
#define INPUTS_H

#include <Arduino.h>

// Estructura para entradas digitales
struct DigitalInputs {
  bool sensorIn  = false;
  bool sensorOut = false;
  bool buttona   = false;
  bool buttonb   = false;
  bool buttonc   = false;
  bool buttond   = false;
};

extern DigitalInputs inputs;

// Inicialización
void initInputs();

// Lectura de entradas
void readInputs();

#endif
