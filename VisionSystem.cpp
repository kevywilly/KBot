

#include "VisionSystem.h"
#include <Servo.h>
#include <NewPing.h>

VisionSystem::VisionSystem(int servo_pin, int front_pin, int back_pin, int max_distance) {
 _servo_pin = servo_pin;
 _front_pin = front_pin;
 _back_pin = back_pin;
 _max_distance = max_distance; 
}

float VisionSystem::getProximity(int d_uS) {
	 NewPing sonar1(_front_pin, _front_pin, _max_distance);
  _servo.attach(_servo_pin);
  _servo.writeMicroseconds(d_uS);
  delay(400);
  float dist = sonar1.ping_cm(); 
  delay(50);
  if(dist == 0.0)
  	return _max_distance;
  else
  	return dist;

}
void VisionSystem::look(void) {
	backProximity = lookBehind();
 	rightProximity = getProximity(TORIGHT);
 	leftProximity = getProximity(TOLEFT);
 	frontProximity = getProximity(AHEAD);
}

float VisionSystem::lookBehind(void) {
  NewPing sonar2(_back_pin, _back_pin, _max_distance);
  float dist = sonar2.ping_cm(); 
  delay(50);
  if(dist == 0.0)
  	return _max_distance;
  else
  	return dist;
}
