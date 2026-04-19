#include "outputs.h"
#include "inputs.h"
#include "rtc.h"
#include "config.h"

DigitalOutputs outputs = {};

enum Relay1Mode {
  AUTO_MODE,
  FORCE_ON,
  FORCE_OFF
};

Relay1Mode relay1Mode = AUTO_MODE;

unsigned long unlockTimer = 0;
bool unlockActive = false;
bool emergencyActive = false;
bool prevButtond = false;

bool isNightLock() {

  uint8_t h = rtcTime.hour;

  if (AUTO_LOCK_HOUR_ON > AUTO_LOCK_HOUR_OFF) {
    return (h >= AUTO_LOCK_HOUR_ON || h < AUTO_LOCK_HOUR_OFF);
  }

  return (h >= AUTO_LOCK_HOUR_ON && h < AUTO_LOCK_HOUR_OFF);
}

void initOutputs() {
  pinMode(PIN_RELAY_1, OUTPUT);
  pinMode(PIN_RELAY_2, OUTPUT);
  pinMode(PIN_RELAY_3, OUTPUT);
  pinMode(PIN_RELAY_4, OUTPUT);

  outputs = {};
  updateOutputs();
}

void processOutputs() {

  // RESET
  if (inputs.buttonb) {
    relay1Mode = AUTO_MODE;
    unlockActive = false;
    emergencyActive = false;
  }

  if (inputs.buttona) relay1Mode = FORCE_ON;
  if (inputs.buttonc) relay1Mode = FORCE_OFF;

  if (inputs.buttond && !prevButtond) {
    emergencyActive = true;
  }

  prevButtond = inputs.buttond;

  // =========================
  // RELAY 1
  // =========================

  if (isNightLock()) {
    outputs.relay1 = false;
  }
  else {

    switch (relay1Mode) {

      case FORCE_ON:
        outputs.relay1 = true;
        break;

      case FORCE_OFF:
        outputs.relay1 = false;
        break;

      case AUTO_MODE:

        if (inputs.sensorIn || inputs.sensorOut) {
          unlockActive = true;
          unlockTimer = millis();
        }

        if (unlockActive &&
            millis() - unlockTimer >= UNLOCK_TIMEOUT_MS) {
          unlockActive = false;
        }

        outputs.relay1 = unlockActive;
        break;
    }
  }

  outputs.relay2 = emergencyActive;
  outputs.relay3 = emergencyActive;
  outputs.relay4 = false;

  updateOutputs();
}

void updateOutputs() {
  digitalWrite(PIN_RELAY_1, outputs.relay1 ? OUTPUT_ACTIVE_STATE : !OUTPUT_ACTIVE_STATE);
  digitalWrite(PIN_RELAY_2, outputs.relay2 ? OUTPUT_ACTIVE_STATE : !OUTPUT_ACTIVE_STATE);
  digitalWrite(PIN_RELAY_3, outputs.relay3 ? OUTPUT_ACTIVE_STATE : !OUTPUT_ACTIVE_STATE);
  digitalWrite(PIN_RELAY_4, outputs.relay4 ? OUTPUT_ACTIVE_STATE : !OUTPUT_ACTIVE_STATE);
}
