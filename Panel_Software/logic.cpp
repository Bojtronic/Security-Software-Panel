#include "logic.h"
#include "inputs.h"
#include "outputs.h"
#include "system_state.h"
#include "config.h"

// ================= MODOS DE OPERACIÓN =================
enum class OperationMode : uint8_t {
  NORMAL,
  FORCE_BLOCK,
  FORCE_UNLOCK
};

static OperationMode currentMode = OperationMode::NORMAL;

// ================= LÓGICA PRINCIPAL =================
void updateLogic() {

  unsigned long now = millis();

  // ---------- CAMBIO DE MODO POR BOTONES ----------
  if (inputs.button1) {
    currentMode = OperationMode::FORCE_BLOCK;
  }
  else if (inputs.button2) {
    currentMode = OperationMode::FORCE_UNLOCK;
  }
  else if (inputs.button3) {
    currentMode = OperationMode::NORMAL;
  }

  // ---------- MODO FORZADO ----------
  if (currentMode == OperationMode::FORCE_BLOCK) {
    outputs.relay1 = LOW;
    outputs.relay2 = LOW;
    outputs.relay3 = LOW;
    outputs.relay4 = LOW;
    currentState = SystemState::LOCKED;
    return;
  }

  if (currentMode == OperationMode::FORCE_UNLOCK) {
    outputs.relay1 = HIGH;
    outputs.relay2 = HIGH;
    outputs.relay3 = HIGH;
    outputs.relay4 = HIGH;
    currentState = SystemState::UNLOCKED;
    return;
  }

  // ---------- MODO NORMAL ----------
  bool presenceDetected = inputs.sensorIn || inputs.sensorOut;

  switch (currentState) {

    case SystemState::LOCKED:
      if (presenceDetected) {
        // Liberar puertas y arrancar temporizador
        outputs.relay1 = HIGH;
        outputs.relay2 = HIGH;
        outputs.relay3 = HIGH;
        outputs.relay4 = HIGH;

        unlockStartTime = now;
        currentState = SystemState::UNLOCKED;
      }
      break;

    case SystemState::UNLOCKED:
      // Si ya no hay presencia → bloquear
      if (!presenceDetected) {
        outputs.relay1 = LOW;
        outputs.relay2 = LOW;
        outputs.relay3 = LOW;
        outputs.relay4 = LOW;

        currentState = SystemState::LOCKED;
      }
      // Si pasó el tiempo máximo → bloquear
      else if (now - unlockStartTime >= UNLOCK_TIMEOUT_MS) {
        outputs.relay1 = LOW;
        outputs.relay2 = LOW;
        outputs.relay3 = LOW;
        outputs.relay4 = LOW;

        currentState = SystemState::LOCKED;
      }
      break;
  }
}
