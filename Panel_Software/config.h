#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ================= PIN CONFIGURATION =================
// Entradas digitales
#define PIN_SENSOR_IN       34   // Sensor de entrada
#define PIN_SENSOR_OUT      35   // Sensor de salida

#define PIN_BUTTON_A        26    // Boton del control remoto para DESBLOQUEAR (A) la puerta 
#define PIN_BUTTON_B        27    // Boton del control remoto para RESET (B) para volver a funcionar normal despues de bloquear, desbloquear o activar emergencia
#define PIN_BUTTON_C        14    // Boton del control remoto para BLOQUEAR (C) la puerta
#define PIN_BUTTON_D        13    // Boton del control remoto para EMERGENCIA (D)   -  se debe verificar la funcionalidad de este pin sino cambiar a 13, 19 o 4

//#define PIN_BUTTON_A        26
//#define PIN_BUTTON_B        27
//#define PIN_BUTTON_C        25
//#define PIN_BUTTON_D        33

// Salidas digitales
#define PIN_RELAY_1         23    // Contacto para BLOQUEAR y DESBLOQUEAR la puerta
#define PIN_RELAY_2         32    // Contacto para la LUZ DE EMERGENCIA afuera de la sucursal
#define PIN_RELAY_3         33    // Contacto para la SEÑAL DE EMERGENCIA que se envia a monitoreo
#define PIN_RELAY_4         25    // Contacto adicional

//#define PIN_RELAY_1         23
//#define PIN_RELAY_2         32
//#define PIN_RELAY_3         19
//#define PIN_RELAY_4         18

// Señales digitales
#define PIN_BATTERY_LOW     39    // Indica que la bateria está descargada
#define PIN_BATTERY_CHARGE  18    // Activa la carga de la bateria

//#define PIN_BATTERY_LOW     39
//#define PIN_BATTERY_CHARGE  4

// Obtener hora mediante I2C
#define PIN_SDA             21    // Pin 5 del chip DS1307
#define PIN_SCL             22    // Pin 6 del chip DS1307

// ================= GENERAL CONFIG =================
#define INPUT_ACTIVE_STATE      HIGH    // Botones activos en HIGH
#define OUTPUT_ACTIVE_STATE     HIGH    // Relé activo en HIGH
#define UNLOCK_TIMEOUT_MS       5000    // 5 segundos (5000 ms)
#define CHARGE_TIMEOUT_MS       7200000 // 2 horas (7200000 ms) 2*60*60*1000

// ================= HORARIO =================
#define AUTO_LOCK_HOUR_ON       18      // 6 PM
#define AUTO_LOCK_HOUR_OFF      8       // 8 AM

#endif
