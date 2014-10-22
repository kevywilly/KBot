#ifndef MiniDrive_h
#define MiniDrive_h

#include "Arduino.h"

// Arduino 5V to pin 15 on SN754410

#define MOTOR1_P1 12 // pin 2 on SN754410
#define MOTOR1_P2 13 // pin 7 on SN754410
#define MOTOR2_P1 7 // pin 15 on SN754410
#define MOTOR2_P2 8 // pin 10 on SN754410
#define MOTOR1_PWM 11 // pin 1 on SN754410
#define MOTOR2_PWM 6 // pin 9 on SN754410

#define NUM_MOTOR_PINS 4
#define NUM_MOTOR_PWMS 2

const int FORWARD[NUM_MOTOR_PINS] = {HIGH,LOW,HIGH,LOW};
const int BACKWARD[NUM_MOTOR_PINS] = {LOW,HIGH,LOW,HIGH};
const int LEFT_SPIN[NUM_MOTOR_PINS] = {LOW,HIGH,HIGH,LOW};
const int RIGHT_SPIN[NUM_MOTOR_PINS] = {HIGH,LOW,LOW,HIGH};

const int MOTOR_PINS[NUM_MOTOR_PINS] = {MOTOR1_P1, MOTOR1_P2, MOTOR2_P1, MOTOR2_P2};
const int MOTOR_PWMS[NUM_MOTOR_PWMS] = {MOTOR1_PWM, MOTOR2_PWM};

const float MOTOR1_SHIFT = 0;
const float MOTOR2_SHIFT = 0;

class MiniDrive {

	public:

		void init(void);
		void forward(int speed);
		void forwardLeft(int speed);
		void backwardLeft(int speed);
		void spinLeft(int speed);
		void forwardRight(int speed);
		void backwardRight(int speed);
		void spinRight(int speed);
		void backward(int speed);
		void brake();
		void spin(int speed, int dir[4]);
		void setDirection(const int dir[4]);
		
		static int currentSpeed[2];
		static int previousSpeed[2];
		static int currentDirection[4];
		static int previousDirection[4];

	private:

		void setSpeed(int speed1, int speed2);
		
		void drive(int speed1, int speed2, const int dir[4]);
		void resumeSpeed(void);
		void pauseSpeed(void);
};



#endif
