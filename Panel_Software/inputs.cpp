#include "inputs.h"
#include "config.h"

DigitalInputs inputs = {false, false, false, false, false};

void initInputs() {
  pinMode(PIN_SENSOR_IN, INPUT);
  pinMode(PIN_SENSOR_OUT, INPUT);

  pinMode(PIN_BUTTON_1, INPUT_PULLUP);
  pinMode(PIN_BUTTON_2, INPUT_PULLUP);
  pinMode(PIN_BUTTON_3, INPUT_PULLUP);
}

void readInputs() {
  inputs.sensorIn  = digitalRead(PIN_SENSOR_IN);
  inputs.sensorOut = digitalRead(PIN_SENSOR_OUT);

  inputs.button1 = (digitalRead(PIN_BUTTON_1) == INPUT_ACTIVE_STATE);
  inputs.button2 = (digitalRead(PIN_BUTTON_2) == INPUT_ACTIVE_STATE);
  inputs.button3 = (digitalRead(PIN_BUTTON_3) == INPUT_ACTIVE_STATE);
}
