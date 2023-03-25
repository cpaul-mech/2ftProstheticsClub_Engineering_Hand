#include "arduino.h"
#define MotorDirectionA 11
#define MotorDirectionB 10
#define ForwardButtonPin 2
#define BackwardButtonPin 3

/*GLOBAL VARIABLES*/
enum
{
    DONOTHING,
    GOFORWARD,
    GOBACKWARD
} motorstate;

void setup()
{
    pinMode(MotorDirectionA, OUTPUT);
    pinMode(MotorDirectionB, OUTPUT);
    pinMode(ForwardButtonPin, INPUT); // switch
    pinMode(BackwardButtonPin, INPUT);
    digitalWrite(MotorDirectionA, HIGH);
    digitalWrite(MotorDirectionB, HIGH);
    motorstate = DONOTHING;
}

void loop()
{
    switch (motorstate)
    {
    case DONOTHING:
        if (digitalRead(ForwardButtonPin))
        {
            // go forwards!!
            digitalWrite(MotorDirectionA, HIGH);
            digitalWrite(MotorDirectionB, LOW);
            motorstate = GOFORWARD;
        }
        else if (digitalRead(BackwardButtonPin))
        {
            digitalWrite(MotorDirectionA, LOW);
            digitalWrite(MotorDirectionB, HIGH);
            motorstate = GOBACKWARD;
        }
        break;
    case GOFORWARD:
        if (!digitalRead(ForwardButtonPin))
        {
            digitalWrite(MotorDirectionA, LOW);
            digitalWrite(MotorDirectionB, LOW);
            motorstate = DONOTHING;
        }
        break;
    case GOBACKWARD:
        if (!digitalRead(BackwardButtonPin))
        {
            digitalWrite(MotorDirectionA, LOW);
            digitalWrite(MotorDirectionB, LOW);
            motorstate = DONOTHING;
        }
        break;
    }
}