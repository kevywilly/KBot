#include "MiniDrive.h"

  int MiniDrive::currentSpeed[2] = {0,0};
  int MiniDrive::previousSpeed[2] = {0,0};
  int MiniDrive::currentDirection[4] = {HIGH,LOW,HIGH,LOW};
  int MiniDrive::previousDirection[4] = {HIGH,LOW,HIGH,LOW};

  void MiniDrive::init(void) {
    for(int i=0; i < NUM_MOTOR_PINS; i++)
      pinMode(MOTOR_PINS[i],OUTPUT); 
 
    for(int i=0; i < NUM_MOTOR_PWMS; i++)
      pinMode(MOTOR_PWMS[i],OUTPUT);  
  }
  
  // Set speed of motors independently
  void MiniDrive::setSpeed(int speed1, int speed2) {

    // Copy current speed to previous speed
    for(int i; i < 2; i++)
      previousSpeed[i] = currentSpeed[i];

    // Change Speed
    analogWrite(MOTOR1_PWM, speed1+MOTOR1_SHIFT);
    analogWrite(MOTOR2_PWM, speed2+MOTOR2_SHIFT);

    // Store the current speed
    currentSpeed[0] = speed1;
    currentSpeed[1] = speed2;
  }

  void MiniDrive::resumeSpeed(void) {
    setSpeed(currentSpeed[0],currentSpeed[1]);
  }

  void MiniDrive::pauseSpeed(void) {
     analogWrite(MOTOR1_PWM, 0);
     analogWrite(MOTOR2_PWM, 0);
  }

  void MiniDrive::setDirection(const int dir[4]) {
    pauseSpeed();
    for(int i; i < 2; i++)
      previousDirection[i] = currentDirection[i];

    for(int i; i < NUM_MOTOR_PINS; i++) 
      digitalWrite(MOTOR_PINS[i], dir[i]);

    for(int i; i < 2; i++)
      currentDirection[i] = dir[i];
    resumeSpeed();
  }

  //Drive with independent speed setting for each wheel and direction
  void MiniDrive::drive(int speed1, int speed2, const int dir[4]) {
    setDirection(dir);
    setSpeed(speed1, speed2);
  }

  void MiniDrive::forward(int speed) {
    drive(speed, speed, FORWARD);
  }

  void MiniDrive::forwardLeft(int speed) {
    drive(speed/2, speed, FORWARD);
  }

  void MiniDrive::backwardLeft(int speed) {
    drive(speed, speed/2, BACKWARD);
  }

  void MiniDrive::spin(int speed, int dir[4]) {
    drive(speed, speed, dir);
  }
  
  void MiniDrive::spinLeft(int speed) {
    drive(speed, speed, LEFT_SPIN);
  }

  void MiniDrive::forwardRight(int speed) {
    drive(speed, speed/2, FORWARD);
  }

  void MiniDrive::backwardRight(int speed) {
    drive(speed/2, speed, BACKWARD);
  }

  void MiniDrive::spinRight(int speed) {
    drive(speed, speed, RIGHT_SPIN);
  }

  void MiniDrive::backward(int speed) {
    drive(speed, speed, BACKWARD);
  }

  void MiniDrive::brake() {
   drive(0,0,FORWARD); 
  }
