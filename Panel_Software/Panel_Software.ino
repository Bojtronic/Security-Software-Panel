#include <Arduino.h>

#include "config/config.h"
#include "io/inputs.h"
#include "io/outputs.h"
#include "system/system_state.h"

void setup() {
  initInputs();
  initOutputs();
  initSystemState();
}

void loop() {
  readInputs();

  // Aquí irá la lógica del sistema (FSM / reglas)
  // Por ahora solo estructura

  updateOutputs();
}
