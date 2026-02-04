#include <Arduino.h>

#include "config.h"
#include "inputs.h"
#include "outputs.h"
#include "system_state.h"
#include "logic.h"

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
