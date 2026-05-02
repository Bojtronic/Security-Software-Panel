#include <Arduino.h>

#include "config.h"
#include "inputs.h"
#include "outputs.h"


void setup() {
  initInputs();
  initOutputs();
}

void loop() {
  processOutputs();
  delay(10);
}