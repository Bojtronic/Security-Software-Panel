#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ================= PIN CONFIGURATION =================
// Entradas digitales
#define PIN_SENSOR_IN       34   // Sensor de entrada
#define PIN_SENSOR_OUT      35   // Sensor de salida

#define PIN_BUTTON_1        26    // Boton del control remoto para DESBLOQUEAR la puerta (A)
#define PIN_BUTTON_2        27    // Boton del control remoto para BLOQUEAR la puerta (C)
#define PIN_BUTTON_3        14    // Boton del control remoto para EMERGENCIA (B - D)

// Salidas digitales
#define PIN_RELAY_1         23    // Contacto para BLOQUEAR y DESBLOQUEAR la puerta
#define PIN_RELAY_2         32    // Contacto para la LUZ DE EMERGENCIA afuera de la sucursal
#define PIN_RELAY_3         33    // Contacto para la SEÑAL DE EMERGENCIA que se envia a monitoreo
#define PIN_RELAY_4         25    // Contacto adicional

// Señales digitales
#define PIN_BATTERY_LOW     39    // Indica que la bateria está descargada
#define PIN_BATTERY_CHARGE  18    // Activa la carga de la bateria

// Obtener hora mediante I2C
#define PIN_SDA             21    // Pin 5 del chip DS1307
#define PIN_SCL             21    // Pin 6 del chip DS1307

// ================= GENERAL CONFIG =================
#define INPUT_ACTIVE_STATE      HIGH    // Botones activos en HIGH
#define OUTPUT_ACTIVE_STATE     HIGH    // Relé activo en HIGH
#define UNLOCK_TIMEOUT_MS       5000    // 5 segundos

#endif
