
#include "definitions.h"
#include "input.h"
#include "drive.h"

void setup() {
  Serial.begin(115200);
  Serial.println("OmniWheelCrossDroid starts...");

  setupInput();
  setupDrive();
}

void loop() {

  loopInput();
  loopDrive();

  delay(2);
}
