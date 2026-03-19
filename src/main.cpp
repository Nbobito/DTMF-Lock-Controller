#include <Arduino.h>
#include "lock_controller.h"

void setup() {
  lockControllerInit();
}

void loop() {
  lockControllerUpdate();
}