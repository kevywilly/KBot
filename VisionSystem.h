



#ifndef VisionSystem_h
#define VisionSystem_h

#include <Arduino.h>
#include <Servo.h>
#include <NewPing.h>

#define AHEAD 1500
#define TORIGHT 700
#define TOLEFT 2300



class VisionSystem {
  public:
    VisionSystem(int servo_pin, int front_pin, int back_pin, int max_distance);
    void look();
    float lookBehind(void);
    float getProximity(int d_uS);
    volatile float leftProximity;
    volatile float rightProximity;
    volatile float frontProximity;
    volatile float backProximity;
 
  private:
    int _front_pin;
    int _back_pin;
    int _servo_pin;
    int _max_distance;
    
    Servo _servo;
    /*NewPing* _sonar_front;
    NewPing* _sonar_back;
    */
};



#endif
