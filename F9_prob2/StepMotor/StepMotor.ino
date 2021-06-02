
/*
 Stepper Motor Control - speed control

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.

 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.

 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 64;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;  // number of steps the motor has taken
int motorSpeed = 0;
int halfPotentiometer = 511;
void setup() {
  // nothing to do inside the setup
  Serial.begin(9600);
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  Serial.print("Potenciomentro: ");
  Serial.println(sensorReading);
  
  motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  
  if(sensorReading < halfPotentiometer){
    motorSpeed = map(sensorReading, 0, halfPotentiometer, 70, 82);
    Serial.print("Velocidade: ");
    Serial.println(motorSpeed);
    myStepper.setSpeed(motorSpeed);
    if(motorSpeed < 20) {
      myStepper.step(20); 
    } else {
      myStepper.step(200); 
    } 
    
  } else if (sensorReading > halfPotentiometer){
    motorSpeed = map(sensorReading, halfPotentiometer, 1023, 70, 82);
    Serial.print("Velocidade: ");
    Serial.println(motorSpeed);
    myStepper.setSpeed(motorSpeed);
    if(motorSpeed < 20) {
      myStepper.step(20); 
    } else {
      myStepper.step(200); 
    } 
  } 
  

  
}