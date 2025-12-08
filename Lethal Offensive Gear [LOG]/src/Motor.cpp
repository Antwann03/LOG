#include <Arduino.h>
#include "Motor.h"

void MotorA() {
  // Motor control pins
  pinMode(PIN1_AIN1, OUTPUT);
  pinMode(PIN1_AIN2, OUTPUT);
  pinMode(MotorDriver1_STBY, OUTPUT);
  // Enable motor driver
  digitalWrite(MotorDriver1_STBY, HIGH);
  // Setup PWM for speed control
  ledcSetup(PWMA1_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(PWMA1, PWMA1_CHANNEL);
  // Start with motor stopped
  digitalWrite(PIN1_AIN1, LOW);
  digitalWrite(PIN1_AIN2, LOW);
  ledcWrite(PWMA1_CHANNEL, 0);
}
void AdjustMotorA_Speed() {
  // Forward at 70% speed
  digitalWrite(PIN1_AIN1, HIGH);
  digitalWrite(PIN1_AIN2, LOW);
  ledcWrite(PWMA1_CHANNEL, 180); // duty 0-255
  delay(2000);
  // Stop
  ledcWrite(PWMA1_CHANNEL, 0);
  delay(1000);
  // Reverse at 70% speed
  digitalWrite(PIN1_AIN1, LOW);
  digitalWrite(PIN1_AIN2, HIGH);
  ledcWrite(PWMA1_CHANNEL, 180);
  delay(2000);
  // Stop
  ledcWrite(PWMA1_CHANNEL, 0);
  delay(1000);
}

void MotorB() {
  // Motor control pins
  pinMode(PIN1_BIN1, OUTPUT);
  pinMode(PIN1_BIN2, OUTPUT);
  pinMode(MotorDriver1_STBY, OUTPUT);
  // Enable motor driver
  digitalWrite(MotorDriver1_STBY, HIGH);
  // Setup PWM for speed control
  ledcSetup(PWMB1_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(PWMB1, PWMB1_CHANNEL);
  // Start with motor stopped
  digitalWrite(PIN1_BIN1, LOW);
  digitalWrite(PIN1_BIN2, LOW);
  ledcWrite(PWMB1_CHANNEL, 0);
}
void AdjustMotorB_Speed() {
  // Forward at 70% speed
  digitalWrite(PIN1_BIN1, HIGH);
  digitalWrite(PIN1_BIN2, LOW);
  ledcWrite(PWMB1_CHANNEL, 180); // duty 0-255
  delay(2000);
  // Stop
  ledcWrite(PWMB1_CHANNEL, 0);
  delay(1000);
  // Reverse at 70% speed
  digitalWrite(PIN1_BIN1, LOW);
  digitalWrite(PIN1_BIN2, HIGH);
  ledcWrite(PWMB1_CHANNEL, 180);
  delay(2000);
  // Stop
  ledcWrite(PWMB1_CHANNEL, 0);
  delay(1000);
}

void MotorC() {
  // Motor control pins
  pinMode(PIN2_AIN1, OUTPUT);
  pinMode(PIN2_AIN2, OUTPUT);
  pinMode(MotorDriver2_STBY, OUTPUT);
  // Enable motor driver
  digitalWrite(MotorDriver2_STBY, HIGH);
  // Setup PWM for speed control
  ledcSetup(PWMA2_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(PWMA2, PWMA2_CHANNEL);
  // Start with motor stopped
  digitalWrite(PIN2_AIN1, LOW);
  digitalWrite(PIN2_AIN2, LOW);
  ledcWrite(PWMA2_CHANNEL, 0);
}
void AdjustMotorC_Speed() {
  // Forward at 70% speed
  digitalWrite(PIN2_AIN1, HIGH);
  digitalWrite(PIN2_AIN2, LOW);
  ledcWrite(PWMA2_CHANNEL, 180); // duty 0-255
  delay(2000);
  // Stop
  ledcWrite(PWMA2_CHANNEL, 0);
  delay(1000);
  // Reverse at 70% speed
  digitalWrite(PIN2_AIN1, LOW);
  digitalWrite(PIN2_AIN2, HIGH);
  ledcWrite(PWMA2_CHANNEL, 180);
  delay(2000);
  // Stop
  ledcWrite(PWMA2_CHANNEL, 0);
  delay(1000);
}

void MotorD() {
  // Motor control pins
  pinMode(PIN2_BIN1, OUTPUT);
  pinMode(PIN2_BIN2, OUTPUT);
  pinMode(MotorDriver2_STBY, OUTPUT);
  // Enable motor driver
  digitalWrite(MotorDriver2_STBY, HIGH);
  // Setup PWM for speed control
  ledcSetup(PWMB2_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(PWMB2, PWMB2_CHANNEL);
  // Start with motor stopped
  digitalWrite(PIN2_BIN1, LOW);
  digitalWrite(PIN2_BIN2, LOW);
  ledcWrite(PWMB2_CHANNEL, 0);
}
void AdjustMotorD_Speed() {
  // Forward at 70% speed
  digitalWrite(PIN2_BIN1, HIGH);
  digitalWrite(PIN2_BIN2, LOW);
  ledcWrite(PWMB2_CHANNEL, 180); // duty 0-255
  delay(2000);
  // Stop
  ledcWrite(PWMB2_CHANNEL, 0);
  delay(1000);
  // Reverse at 70% speed
  digitalWrite(PIN2_BIN1, LOW);
  digitalWrite(PIN2_BIN2, HIGH);
  ledcWrite(PWMB2_CHANNEL, 180);
  delay(2000);
  // Stop
  ledcWrite(PWMB2_CHANNEL, 0);
  delay(1000);
}

void Motor_Forward(int run)
{
  //Enabling Motor Driver for Forward
  digitalWrite(MotorDriver1_STBY, HIGH);
  digitalWrite(MotorDriver2_STBY, HIGH);
  // MOTOR A (Left Front Wheel)
  digitalWrite(PIN1_AIN1, HIGH);
  digitalWrite(PIN1_AIN2, LOW);
  ledcWrite(PWMA1_CHANNEL, run);
  // MOTOR B (Right Front Wheel)
  digitalWrite(PIN1_BIN1, HIGH);
  digitalWrite(PIN1_BIN2, LOW);
  ledcWrite(PWMB1_CHANNEL, run);
  // MOTOR C (Left Rear Wheel)
  digitalWrite(PIN2_AIN1, HIGH);
  digitalWrite(PIN2_AIN2, LOW);
  ledcWrite(PWMA2_CHANNEL, run);
  // MOTOR D (Right Rear Wheel)
  digitalWrite(PIN2_BIN1, HIGH);
  digitalWrite(PIN2_BIN2, LOW);
  ledcWrite(PWMB2_CHANNEL, run);
}
void Motor_Backward(int run)
{
  //Enabling Motor Drivers for Backward
  digitalWrite(MotorDriver1_STBY, HIGH);
  digitalWrite(MotorDriver2_STBY, HIGH);
  // MOTOR A (Left Front Wheel)
  digitalWrite(PIN1_AIN1, LOW);
  digitalWrite(PIN1_AIN2, HIGH);
  ledcWrite(PWMA1_CHANNEL, run);
  // MOTOR B (Right Front Wheel)
  digitalWrite(PIN1_BIN1, LOW);
  digitalWrite(PIN1_BIN2, HIGH);
  ledcWrite(PWMB1_CHANNEL, run);
  // MOTOR C (Left Rear Wheel)
  digitalWrite(PIN2_AIN1, LOW);
  digitalWrite(PIN2_AIN2, HIGH);
  ledcWrite(PWMA2_CHANNEL, run);
  // MOTOR D (Right Rear Wheel)
  digitalWrite(PIN2_BIN1, LOW);
  digitalWrite(PIN2_BIN2, HIGH);
  ledcWrite(PWMB2_CHANNEL, run);
}
void Motor_Left(int run)
{
  //Enabling Motor Drivers for Left
  digitalWrite(MotorDriver1_STBY, HIGH);
  digitalWrite(MotorDriver2_STBY, HIGH);
  // MOTOR A (Left Front Wheel)
  digitalWrite(PIN1_AIN1, LOW);
  digitalWrite(PIN1_AIN2, HIGH);
  ledcWrite(PWMA1_CHANNEL, run);
  // MOTOR C (Left Rear Wheel)
  digitalWrite(PIN2_AIN1, LOW);
  digitalWrite(PIN2_AIN2, HIGH);
  ledcWrite(PWMA2_CHANNEL, run);
  // MOTOR B (Right Front Wheel)
  digitalWrite(PIN1_BIN1, HIGH);
  digitalWrite(PIN1_BIN2, LOW);
  ledcWrite(PWMB1_CHANNEL, run);
  // MOTOR D (Right Rear Wheel)
  digitalWrite(PIN2_BIN1, HIGH);
  digitalWrite(PIN2_BIN2, LOW);
  ledcWrite(PWMB2_CHANNEL, run);
}
void Motor_Right(int run)
{
  //Enabling Motor Drivers for Right
  digitalWrite(MotorDriver1_STBY, HIGH);
  digitalWrite(MotorDriver2_STBY, HIGH);
  // MOTOR A (Left Front Wheel)
  digitalWrite(PIN1_AIN1, HIGH);
  digitalWrite(PIN1_AIN2, LOW);
  ledcWrite(PWMA1_CHANNEL, run);
  // MOTOR C (Left Rear Wheel)
  digitalWrite(PIN2_AIN1, HIGH);
  digitalWrite(PIN2_AIN2, LOW);
  ledcWrite(PWMA2_CHANNEL, run);
  // MOTOR B (Right Front Wheel)
  digitalWrite(PIN1_BIN1, LOW);
  digitalWrite(PIN1_BIN2, HIGH);
  ledcWrite(PWMB1_CHANNEL, run);
  // MOTOR D (Right Rear Wheel)
  digitalWrite(PIN2_BIN1, LOW);
  digitalWrite(PIN2_BIN2, HIGH);
  ledcWrite(PWMB2_CHANNEL, run);
}
void Motor_Stop()
{
  // Enabling Motor Drivers for Stop
  digitalWrite(MotorDriver1_STBY, HIGH);
  digitalWrite(MotorDriver2_STBY, HIGH);
  // MOTOR A
  digitalWrite(PIN1_AIN1, LOW);
  digitalWrite(PIN1_AIN2, LOW);
  ledcWrite(PWMA1_CHANNEL, 0);
  // MOTOR B
  digitalWrite(PIN1_BIN1, LOW);
  digitalWrite(PIN1_BIN2, LOW);
  ledcWrite(PWMB1_CHANNEL, 0);
  // MOTOR C
  digitalWrite(PIN2_AIN1, LOW);
  digitalWrite(PIN2_AIN2, LOW);
  ledcWrite(PWMA2_CHANNEL, 0);
  // MOTOR D
  digitalWrite(PIN2_BIN1, LOW);
  digitalWrite(PIN2_BIN2, LOW);
  ledcWrite(PWMB2_CHANNEL, 0);
}