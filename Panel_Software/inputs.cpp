#include "inputs.h"
#include "config.h"

void initInputs() {
  pinMode(PIN_SENSOR_IN, INPUT); // Necesita resistencia pull-down externa
  pinMode(PIN_SENSOR_OUT, INPUT); // Necesita resistencia pull-down externa

  pinMode(PIN_BUTTON_A, INPUT_PULLDOWN);
  pinMode(PIN_BUTTON_B, INPUT_PULLDOWN);
  pinMode(PIN_BUTTON_C, INPUT_PULLDOWN);
  pinMode(PIN_BUTTON_D, INPUT_PULLDOWN);

  pinMode(PIN_BATTERY_LOW, INPUT);
}

