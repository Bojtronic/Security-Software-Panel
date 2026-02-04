#include "system_state.h"

SystemState currentState = SystemState::LOCKED;
unsigned long unlockStartTime = 0;

void initSystemState() {
  currentState = SystemState::LOCKED;
  unlockStartTime = 0;
}
