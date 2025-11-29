#ifndef MOTOR_H      // if MOTOR_H is NOT defined yet…
#define MOTOR_H      // …define it now

#include <Arduino.h>
#include <string.h>
#include <stdio.h>
/*
    Constants for the GPIO pins for Motors A, B, C, and D
    Pin Mapping
*/
//FIRST MOTOR DRIVER for TB6612FNG 
const int MotorDriver1_STBY = 32;
//MOTOR A
const int PWMA1 = 23;
const int PIN1_AIN1 = 22;
const int PIN1_AIN2 = 21;
//MOTOR B
const int PWMB1 = 5;
const int PIN1_BIN1 = 19;
const int PIN1_BIN2 = 18;
//SECOND MOTOR DRIVER for TB6612FNG
const int MotorDriver2_STBY = 4;
//MOTOR C
const int PWMA2 = 17;
const int PIN2_AIN1 = 2;
const int PIN2_AIN2 = 16;
//MOTOR D
const int PWMB2 = 27;
const int PIN2_BIN1 = 25;
const int PIN2_BIN2 = 26;

//SERVO MOTOR potentially to use
// GPIO PINS availabe to use: 14, 15, 33, 34, 35, 36, 39

//-------const int SERVOMOTOR = 13;

const int PWMA1_CHANNEL = 0;
const int PWMB1_CHANNEL = 1;
const int PWMA2_CHANNEL = 2;
const int PWMB2_CHANNEL = 3;

const int PWM_FREQ    = 20000; // 20 kHz
const int PWM_RES = 8;


// Initialize motors
void MotorA();
void MotorB();
void MotorC();
void MotorD();

// Move motors
void AdjustMotorA_Speed();
void AdjustMotorB_Speed();
void AdjustMotorC_Speed();
void AdjustMotorD_Speed();

// Motor_Forward
void Motor_Forward(int run);
// Motor_Backward
void Motor_Backward(int run);
// Motor_Left();
void Motor_Left(int run);
// Motor_Right();
void Motor_Right(int run);
// Motor_Stop
void Motor_Stop();
#endif              // end of protection
