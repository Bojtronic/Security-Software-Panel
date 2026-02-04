#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

#include <Arduino.h>

// Estados generales del sistema
enum class SystemState : uint8_t {
  IDLE,
  ACTIVE,
  ERROR,
  MANUAL
};

extern SystemState currentState;

// Inicialización
void initSystemState();

#endif
