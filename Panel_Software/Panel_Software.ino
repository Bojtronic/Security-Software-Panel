#include <Arduino.h>

#include "config.h"
#include "inputs.h"
#include "outputs.h"
#include "rtc.h"

//#include "system_state.h"
//#include "logic.h"

void setup() {
  initInputs();
  initOutputs();
  initRTC();
}

void loop() {
  readInputs();
  readRTC();
  processOutputs();
}