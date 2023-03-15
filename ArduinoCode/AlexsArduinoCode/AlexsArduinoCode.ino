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
    Serial.begin(9600);
    pinMode(MotorDirectionA, OUTPUT);
    pinMode(MotorDirectionB, OUTPUT);
    pinMode(MotorOffOn, INPUT); //switch
    myServo.attach(SERVO_PIN);
    myServo.write(150);
}

void loop()
{

    OffOn = digitalRead(MotorOffOn);
    Serial.println(OffOn);
    if (OffOn == 1)
    {
        digitalWrite(MotorDirectionA, HIGH);
        digitalWrite(MotorDirectionB, LOW);
    }
    else if(OffOn == 0)
    {
        digitalWrite(MotorDirectionB, HIGH);
        digitalWrite(MotorDirectionA, LOW);
    }
}