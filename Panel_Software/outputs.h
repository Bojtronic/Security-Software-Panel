#ifndef OUTPUTS_H
#define OUTPUTS_H

#include "config.h"

struct DigitalOutputs {
  bool relay1 = false;
  bool relay2 = false;
  bool relay3 = false;
  bool relay4 = false;
};

extern DigitalOutputs outputs;

void initOutputs();
void processOutputs();
void updateOutputs();

#endif
