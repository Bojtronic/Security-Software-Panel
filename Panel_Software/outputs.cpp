#include "outputs.h"
#include "inputs.h"
#include "rtc.h"
#include "config.h"

enum RelayMode
{
  AUTO_MODE,
  FORCE_ON,
  FORCE_OFF,
  EMERGENCY
};

RelayMode relayMode = AUTO_MODE;
RelayMode previousMode = AUTO_MODE;

unsigned long unlockTimer = 0;
unsigned long chargeTimer = 0;

bool charging = false;
bool batteryLow = false;
bool unlockActive = false;

bool autoModeActive = false;
bool forceOnActive = false;
bool forceOffActive = false;
bool emergencyActive = false;

void initOutputs()
{
  pinMode(PIN_RELAY_1, OUTPUT);
  pinMode(PIN_RELAY_2, OUTPUT);
  pinMode(PIN_RELAY_3, OUTPUT);
  pinMode(PIN_RELAY_4, OUTPUT);
  pinMode(PIN_BATTERY_CHARGE, OUTPUT);

  digitalWrite(PIN_RELAY_1, LOW);
  digitalWrite(PIN_RELAY_2, LOW);
  digitalWrite(PIN_RELAY_3, LOW);
  digitalWrite(PIN_RELAY_4, LOW);
  digitalWrite(PIN_BATTERY_CHARGE, LOW);
}

void processOutputs()
{

  autoModeActive = digitalRead(PIN_BUTTON_B);
  forceOnActive = digitalRead(PIN_BUTTON_A);
  forceOffActive = digitalRead(PIN_BUTTON_C);
  emergencyActive = digitalRead(PIN_BUTTON_D);

  batteryLow = digitalRead(PIN_BATTERY_LOW);

  bool noPressed = !autoModeActive && !forceOnActive && !forceOffActive && !emergencyActive;

  bool noValid =
      // combinaciones de 2 botones
      (autoModeActive && forceOnActive) ||
      (autoModeActive && forceOffActive) ||
      (autoModeActive && emergencyActive) ||
      (forceOnActive && forceOffActive) ||
      (forceOnActive && emergencyActive) ||
      (forceOffActive && emergencyActive) ||

      // combinaciones de 3 botones
      (autoModeActive && forceOnActive && forceOffActive) ||
      (autoModeActive && forceOnActive && emergencyActive) ||
      (autoModeActive && forceOffActive && emergencyActive) ||
      (forceOnActive && forceOffActive && emergencyActive) ||

      // los 4 botones
      (autoModeActive && forceOnActive && forceOffActive && emergencyActive);

  // -------------------------------------------------------------------------------------

  if (noValid)
  {
    relayMode = AUTO_MODE;
    digitalWrite(PIN_RELAY_2, LOW);
    digitalWrite(PIN_RELAY_3, LOW);
  }
  else if (emergencyActive)
  {
    relayMode = EMERGENCY;
  }
  else if (forceOnActive)
  {
    relayMode = FORCE_ON;
    digitalWrite(PIN_RELAY_2, LOW);
    digitalWrite(PIN_RELAY_3, LOW);
  }
  else if (forceOffActive)
  {
    relayMode = FORCE_OFF;
    digitalWrite(PIN_RELAY_2, LOW);
    digitalWrite(PIN_RELAY_3, LOW);
  }
  else if (autoModeActive)
  {
    relayMode = AUTO_MODE;
    digitalWrite(PIN_RELAY_2, LOW);
    digitalWrite(PIN_RELAY_3, LOW);
  }
  else if (noPressed)
  {
    relayMode = previousMode;
  }

  // -------------------------------------------------------------------------------------

  switch (relayMode)
  {

  case AUTO_MODE:

    if (digitalRead(PIN_SENSOR_IN) || digitalRead(PIN_SENSOR_OUT))
    {
      unlockActive = true;
      unlockTimer = millis();
    }

    if (unlockActive && (millis() - unlockTimer >= UNLOCK_TIMEOUT_MS))
    {
      unlockActive = false;
    }

    digitalWrite(PIN_RELAY_1, unlockActive);
    previousMode = AUTO_MODE;
    break;

  case EMERGENCY:
    digitalWrite(PIN_RELAY_2, HIGH);
    digitalWrite(PIN_RELAY_3, HIGH);
    previousMode = EMERGENCY;
    break;

  case FORCE_ON:
    digitalWrite(PIN_RELAY_1, HIGH);
    previousMode = FORCE_ON;
    break;

  case FORCE_OFF:
    digitalWrite(PIN_RELAY_1, LOW);
    previousMode = FORCE_OFF;
    break;
  }

  // -------------------------------------------------------------------------------------

  // Iniciar carga
  if (batteryLow && !charging)
  {
    charging = true;
    chargeTimer = millis();

    digitalWrite(PIN_BATTERY_CHARGE, HIGH);
  }

  // Mantener carga activa por timeout
  if (charging)
  {
    if (millis() - chargeTimer >= CHARGE_TIMEOUT_MS)
    {
      digitalWrite(PIN_BATTERY_CHARGE, LOW);

      charging = false;
      chargeTimer = 0;
    }
  }
}
