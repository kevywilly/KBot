
#include "Arduino.h"
#include "Minidrive.h"
#include "VisionSystem.h"

#define SONAR_FRONT_PIN 4
#define SONAR_BACK_PIN 2
#define SONAR_MAX_DISTANCE 300
#define HEAD_PIN 10
#define DRIVESPEED 250
#define TURNSPEED 175



MiniDrive drive;
VisionSystem eyes(HEAD_PIN, SONAR_FRONT_PIN, SONAR_BACK_PIN, SONAR_MAX_DISTANCE);

void setup() {
  // Start Serial
  Serial.begin(9600);
  drive.init();
}

void loop() {
  //float distF = eyes.look(AHEAD);
  //Serial.println(distF);
  //float distB = eyes.lookBehind();
  avoid(); //(distF, distB);
  
}

void goStraight(int speed = DRIVESPEED) {
  drive.forward(DRIVESPEED);
}

void turn(){
  drive.brake();
  eyes.look();

  Serial.print("FRONT: ");
  Serial.println(eyes.frontProximity);
  Serial.print("RIGHT: ");
  Serial.println(eyes.rightProximity);
  Serial.print("LEFT: ");
  Serial.println(eyes.leftProximity);
  Serial.print("BACK: ");
  Serial.println(eyes.backProximity);

  uint8_t spinDelay = 100;

  if(eyes.frontProximity <= 25){
    spinDelay = 300;
    drive.backward(DRIVESPEED);
    if(eyes.backProximity > 15)
      delay(500);
    else
      delay(300);
  }
    
    if(eyes.rightProximity > eyes.leftProximity)
      drive.spinRight(DRIVESPEED);
    else
      drive.spinLeft(DRIVESPEED);

      delay(spinDelay);

  

}

void avoid() {

  float fp = eyes.getProximity(AHEAD);

  if(fp > 50) {
    goStraight();
  }
  else {
    turn();
  }
}



