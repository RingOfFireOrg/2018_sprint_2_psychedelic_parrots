// Include the Servo library
#include <Servo.h>

// Declare the variables

Servo ServoGrabber;
Servo ServoFrontRight;
Servo ServoFrontLeft;
Servo ServoBackLeft;
Servo ServoBackRight;
boolean StopForever; // Will be used to stop the robot in main loop

const int PIN_SERVO_GRABBER = 1;
const int PIN_SERVO_FRONT_RIGHT = 4;
const int PIN_SERVO_FRONT_LEFT = 5;
const int PIN_SERVO_BACK_RIGHT = 7;
const int PIN_SERVO_BACK_LEFT = 6;

void setup()
{
    Serial.begin(9600); // Starts the serial communication
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
    driveSpeed(100, 100);
    delay(1000);
    stopWheels();
    delay(1000);
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
