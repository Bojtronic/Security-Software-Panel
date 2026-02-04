#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

#include <Arduino.h>

// Estados del sistema de puertas
enum class SystemState : uint8_t {
  LOCKED,       // Puertas bloqueadas
  UNLOCKED      // Puertas liberadas temporalmente
};

extern SystemState currentState;

// Tiempo en que se liberaron las puertas
extern unsigned long unlockStartTime;

// Inicialización
void initSystemState();

#endif
