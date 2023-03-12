#include "Arduino.h"
#define MotorDirectionA 11
#define MotorDirectionB 10
#define MotorOffOn 7
#define SERVO_PIN 4
#include <Servo.h>
Servo myServo;
int OffOn;

void setup()
{
    // put your setup code here, to run once:
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(7, INPUT);
    myServo.attach(SERVO_PIN);
    myServo.write(150);
}

void loop()
{

    OffOn = digitalRead(MotorOffOn);
    if (OffOn == 1)
    {
        digitalWrite(MotorDirectionA, HIGH);
        digitalWrite(MotorDirectionB, LOW);
    }
    else
    {
        digitalWrite(MotorDirectionB, HIGH);
        digitalWrite(MotorDirectionA, LOW);
    }
}