#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ================= PIN CONFIGURATION =================
// Entradas digitales
#define PIN_SENSOR_IN     34   // Sensor de entrada
#define PIN_SENSOR_OUT    35   // Sensor de salida

#define PIN_BUTTON_1      26
#define PIN_BUTTON_2      27
#define PIN_BUTTON_3      14

// Salidas digitales
#define PIN_RELAY_1       23
#define PIN_RELAY_2       32
#define PIN_RELAY_3       33
#define PIN_RELAY_4       25

// ================= GENERAL CONFIG =================
#define INPUT_ACTIVE_STATE   HIGH    // Botones activos en HIGH
#define OUTPUT_ACTIVE_STATE  HIGH    // Relé activo en HIGH
#define UNLOCK_TIMEOUT_MS 5000       // 5 segundos

#endif
