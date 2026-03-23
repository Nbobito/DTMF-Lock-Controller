#include <Arduino.h>
#include "lock_controller.h"

void setup() {
  Serial.begin(9600);
  lockControllerInit();
}

void loop() {
  lockControllerUpdate();
}