void setupDrive() {
  motor_L.setSpeed(0);
  motor_R.setSpeed(0);
  motor_T.setSpeed(0);
  motor_B.setSpeed(0);
}

void loopDrive() {
  uint16_t minValue = 1000;
  uint16_t maxValue = 2000;
  uint16_t centerPoint = 1500;
  uint16_t deadPoint = 10;
  int16_t currentMaxSpeedValue = maxSpeedValue;

  topMotorSpeedTarget = 0;
  bottomMotorSpeedTarget = 0;
  leftMotorSpeedTarget = 0;
  rightMotorSpeedTarget = 0;

  if (driveValueHorizontal >= 1000 && driveValueHorizontal <= 2000) {
    if (driveValueHorizontal < centerPoint - deadPoint || driveValueHorizontal > centerPoint + deadPoint) {
      joystickX = map(driveValueHorizontal, minValue, maxValue, -maxSpeedValue, maxSpeedValue);

      topMotorSpeedTarget = joystickX;
      bottomMotorSpeedTarget = joystickX;
    }
  }

  if (driveValueVertical >= 1000 && driveValueVertical <= 2000) {

    if (driveValueVertical < centerPoint - deadPoint || driveValueVertical > centerPoint + deadPoint) {
      joystickY = map(driveValueVertical, minValue, maxValue, -maxSpeedValue, maxSpeedValue);

      leftMotorSpeedTarget = joystickY;
      rightMotorSpeedTarget = joystickY;
    }
  }

  if (driveRotation >= 1000 && driveRotation <= 2000) {
    if (driveRotation < centerPoint - deadPoint || driveRotation > centerPoint + deadPoint) {
      joystickRotate = map(driveRotation, minValue, maxValue, maxSpeedValue, -maxSpeedValue);

      topMotorSpeedTarget -= joystickRotate;
      bottomMotorSpeedTarget += joystickRotate;
      leftMotorSpeedTarget -= joystickRotate;
      rightMotorSpeedTarget += joystickRotate;
    }
  }

  leftMotorSpeedTarget = constrain(leftMotorSpeedTarget, -currentMaxSpeedValue, currentMaxSpeedValue);
  rightMotorSpeedTarget = constrain(rightMotorSpeedTarget, -currentMaxSpeedValue, currentMaxSpeedValue);
  topMotorSpeedTarget = constrain(topMotorSpeedTarget, -currentMaxSpeedValue, currentMaxSpeedValue);
  bottomMotorSpeedTarget = constrain(bottomMotorSpeedTarget, -currentMaxSpeedValue, currentMaxSpeedValue);

  Serial.print("   Motors: ");

  Serial.print("    Left ");
  Serial.print(leftMotorSpeedTarget);
  Serial.print("    Right ");
  Serial.print(rightMotorSpeedTarget);
  Serial.print("    Top ");
  Serial.print(topMotorSpeedTarget);
  Serial.print("    Bottom ");
  Serial.println(bottomMotorSpeedTarget);


  motor_L.setSpeed(leftMotorSpeedTarget);
  motor_R.setSpeed(rightMotorSpeedTarget);
  motor_T.setSpeed(topMotorSpeedTarget);
  motor_B.setSpeed(bottomMotorSpeedTarget);
}