#include "inputs.h"
#include "config.h"

DigitalInputs inputs = {
  .sensorIn = false,
  .sensorOut = false,
  .button1 = false,
  .button2 = false,
  .button3 = false
};

void initInputs() {
  pinMode(PIN_SENSOR_IN, INPUT);
  pinMode(PIN_SENSOR_OUT, INPUT);

  pinMode(PIN_BUTTON_A, INPUT);
  pinMode(PIN_BUTTON_B, INPUT);
  pinMode(PIN_BUTTON_C, INPUT);
  pinMode(PIN_BUTTON_D, INPUT);
}

void readInputs() {
  inputs.sensorIn  = (digitalRead(PIN_SENSOR_IN) == INPUT_ACTIVE_STATE);
  inputs.sensorOut = (digitalRead(PIN_SENSOR_OUT) == INPUT_ACTIVE_STATE);

  inputs.buttona = (digitalRead(PIN_BUTTON_A) == INPUT_ACTIVE_STATE); // Boton del control remoto para DESBLOQUEAR (A) la puerta 
  inputs.buttonb = (digitalRead(PIN_BUTTON_B) == INPUT_ACTIVE_STATE); // Boton del control remoto para RESET (B) para volver a funcionar normal despues de bloquear, desbloquear o activar emergencia
  inputs.buttonc = (digitalRead(PIN_BUTTON_C) == INPUT_ACTIVE_STATE); // Boton del control remoto para BLOQUEAR (C) la puerta
  inputs.buttond = (digitalRead(PIN_BUTTON_D) == INPUT_ACTIVE_STATE); // Boton del control remoto para EMERGENCIA (D)
}

