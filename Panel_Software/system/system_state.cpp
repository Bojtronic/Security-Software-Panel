#include "system_state.h"

SystemState currentState = SystemState::IDLE;

void initSystemState() {
  currentState = SystemState::IDLE;
}
