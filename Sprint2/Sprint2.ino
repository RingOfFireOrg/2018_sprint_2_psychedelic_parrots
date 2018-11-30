// Include the Servo library
#include <Servo.h>
#include "ds_interface.h"

#define RX_FROM_NMCU 2
#define TX_TO_NMCU 3

// ---------------------------------------------------------------------------
/*
   Create a Drive Station Interface "DS_Interface" object
*/
DS_Interface ds(RX_FROM_NMCU, TX_TO_NMCU);
// Declare the variables

Servo ServoGrabber;
Servo ServoFrontRight;
Servo ServoFrontLeft;
Servo ServoBackLeft;
Servo ServoBackRight;
boolean StopForever; // Will be used to stop the robot in main loop

const int PIN_SERVO_GRABBER = 8;
const int PIN_SERVO_FRONT_RIGHT = 4;
const int PIN_SERVO_FRONT_LEFT = 5;
const int PIN_SERVO_BACK_RIGHT = 7;
const int PIN_SERVO_BACK_LEFT = 6;

void setup()
{
    Serial.begin(115200);
    Serial.println("Interfacing arduino with nodemcu");
    ds.init(); // setup drive station comms
    // Attach Servo Pin numbers
    ServoGrabber.attach(PIN_SERVO_GRABBER);
    ServoFrontRight.attach(PIN_SERVO_FRONT_RIGHT);
    ServoFrontLeft.attach(PIN_SERVO_FRONT_LEFT);
    ServoBackLeft.attach(PIN_SERVO_BACK_LEFT);
    ServoBackRight.attach(PIN_SERVO_BACK_RIGHT);

    // Reset the wheels
    stopWheels();
}

void loop()
{
    char input = ds.readInputIfAvailable();
    switch (input)
    {
    case 't':
        testServos();
        break;
    case 'w':
        driveFullSpeed();
        break;
    case 'd':
        turnRight();
        break;
    case 'a':
        turnLeft();
        break;
    case 's':
        stopWheels();
        break;
    case 'x':
        driveBackwards();
        break;
    case 'i':
        magnetIn();
        break;
    case 'o':
        magnetOut();
        break;
    case 'p':
        magnetMiddle();
        break;
    default:
        break;
    }
}

void testServos()
{
    ServoBackLeft.write(180);
    delay(500);
    ServoBackLeft.write(90);
    ServoBackRight.write(0);
    delay(500);
    ServoBackRight.write(90);
    ServoFrontLeft.write(180);
    delay(500);
    ServoFrontLeft.write(90);

    ServoFrontRight.write(0);
    delay(500);
    stopWheels();
}

void magnetIn()
{
    ServoGrabber.write(180);
}

void magnetOut()
{
    ServoGrabber.write(0);
}

void magnetMiddle()
{
    ServoGrabber.write(90);
}

void turnRight()
{
    driveSpeed(100, -100);
}
void turnLeft()
{
    driveSpeed(-100, 100);
}
void driveBackwards()
{
    driveSpeed(-100, -100);
}
void driveFullSpeed()
{
    driveSpeed(100, 100);
}

void stopWheels()
{
    driveSpeed(0, 0);
}

// This is -100 to 100 with 0 being stopped
void driveSpeed(int leftMotorSpeed, int rightMotorSpeed)
{
    ServoBackLeft.write(map(leftMotorSpeed, -100, 100, 0, 180));
    ServoBackRight.write(map(rightMotorSpeed, -100, 100, 180, 0));
    ServoFrontLeft.write(map(leftMotorSpeed, -100, 100, 0, 180));
    ServoFrontRight.write(map(rightMotorSpeed, -100, 100, 180, 0));
}
