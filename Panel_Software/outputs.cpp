#include "outputs.h"
#include "config.h"

DigitalOutputs outputs = {false, false, false, false};

void initOutputs() {
  pinMode(PIN_RELAY_1, OUTPUT);
  pinMode(PIN_RELAY_2, OUTPUT);
  pinMode(PIN_RELAY_3, OUTPUT);
  pinMode(PIN_RELAY_4, OUTPUT);

  updateOutputs();
}

void updateOutputs() {
  digitalWrite(PIN_RELAY_1, outputs.relay1 ? OUTPUT_ACTIVE_STATE : !OUTPUT_ACTIVE_STATE);
  digitalWrite(PIN_RELAY_2, outputs.relay2 ? OUTPUT_ACTIVE_STATE : !OUTPUT_ACTIVE_STATE);
  digitalWrite(PIN_RELAY_3, outputs.relay3 ? OUTPUT_ACTIVE_STATE : !OUTPUT_ACTIVE_STATE);
  digitalWrite(PIN_RELAY_4, outputs.relay4 ? OUTPUT_ACTIVE_STATE : !OUTPUT_ACTIVE_STATE);
}

void setRelay(uint8_t relayNumber, bool state) {
  switch (relayNumber) {
    case 1: outputs.relay1 = state; break;
    case 2: outputs.relay2 = state; break;
    case 3: outputs.relay3 = state; break;
    case 4: outputs.relay4 = state; break;
    default: return;
  }
  updateOutputs();
}
