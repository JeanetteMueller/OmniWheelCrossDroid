#include <CytronMotorDriver.h>

CytronMD motor_R(PWM_DIR, 3, 17);
CytronMD motor_L(PWM_DIR, 5, 16);

CytronMD motor_T(PWM_DIR, 6, 15);
CytronMD motor_B(PWM_DIR, 9, 14);

uint16_t driveValueHorizontal = 1500;
uint16_t driveValueVertical = 1500;
uint16_t driveRotation = 1500;

int16_t joystickX = 0;
int16_t joystickY = 0;
int16_t joystickRotate = 0;
int16_t leftMotorSpeedTarget = 0;
int16_t rightMotorSpeedTarget = 0;
int16_t topMotorSpeedTarget = 0;
int16_t bottomMotorSpeedTarget = 0;

int16_t maxSpeedValue = 255;

// RC Reviever
#include <IBusBM.h>
IBusBM *IBus = new IBusBM();
uint16_t ibusVar00 = 1500;
uint16_t ibusVar01 = 1500;
uint16_t ibusVar02 = 1000;
uint16_t ibusVar03 = 1500;
uint16_t ibusVar04 = 1000;
uint16_t ibusVar05 = 1000;
uint16_t ibusVar06 = 1000;
uint16_t ibusVar07 = 1000;
uint16_t ibusVar08 = 1000;
uint16_t ibusVar09 = 1000;