/**
 * This is test block comment.
 */
// Include the Servo library 
#include <Servo.h> 

// Declare the variables 

 Servo ServoGrabber;
 Servo ServoFrontRight; 
 Servo ServoFrontLeft;
 Servo ServoBackLeft;
 Servo ServoBackRight;
 boolean StopForever; // Will be used to stop the robot in main loop

void setup() { 
    // Setup the environment
    StopForever = false;
    // Attach Servo Pin numbers
    ServoGrabber.attach(1);
    ServoFrontRight.attach(2);
    ServoFrontLeft.attach(3);
    ServoBackLeft.attach(4);
    ServoBackRight.attach(5);
    Serial.begin(9600); // Starts the serial communication
    // Reset the wheels
    ServoBackRight.write(90);
    ServoBackLeft.write(90);
    ServoFrontLeft.write(90);
    ServoFrontRight.write(90);
}

void Stop(){
    // Stop wheels from turning
    ServoBackRight.write(90);
    ServoBackLeft.write(90);
    ServoFrontLeft.write(90);
    ServoFrontRight.write(90);
}

void Forward(){
    // Stop wheels from turning
    ServoBackRight.write(120);
    ServoFrontRight.write(120);
    ServoBackLeft.write(90);
    ServoFrontLeft.write(90);
}  

void loop(){ 
    if (StopForever == false)
    {
     Forward();
     delay(5000);
     //ServoRight.write(0);
     //delay(1000);
     //ServoRight.write(45);
     StopForever = true;
    }
    else{
        Stop();
    }
}