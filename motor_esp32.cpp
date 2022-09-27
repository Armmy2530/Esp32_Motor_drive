#include <Arduino.h>
#include "motor_esp32.h"
#include <ESP32Servo.h>


Motor::Motor(int motor_A, int motor_B, int motor_PWM)
{
    A_pin = motor_A;
    B_pin = motor_B;
    PWM_pin = motor_PWM;
    pinMode(A_pin, OUTPUT);
    pinMode(B_pin, OUTPUT);
}

void Motor::m(int speed)
{
    if (speed > 0)
    {
        digitalWrite(A_pin, HIGH);
        digitalWrite(B_pin, LOW);
        analogWrite(PWM_pin, speed);
    }
    if (speed < 0)
    {
        digitalWrite(A_pin, LOW);
        digitalWrite(B_pin, HIGH);
        analogWrite(PWM_pin, -speed);
    }
    if (speed == 0)
    {
        digitalWrite(A_pin, LOW);
        digitalWrite(B_pin, LOW);
        analogWrite(PWM_pin, 0);
    }
    if (speed == -999)
    {
        digitalWrite(A_pin, LOW);
        digitalWrite(B_pin, LOW);
        analogWrite(PWM_pin, 255);
    }
}
