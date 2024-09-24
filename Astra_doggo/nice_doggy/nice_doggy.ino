#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN_PULSE  150 
#define SERVOMAX_PULSE  600 

int angle0 = 90;
int angle1 = 110;
int angle2 = 100;
int increment0 = 1;
int increment1 = 1;
int increment2 = 1;
int dig = 140;
int a = 170;
int b = 185;
int c = 5;
int d = 0;
int i = -1;
int i1 = -1;
int i3 = -1;
int i4 = -1;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);

  // Move servos to initial positions
  setServoAngle(7, 80);
  setServoAngle(8, 90);
  setServoAngle(6, 70);
  setServoAngle(9, 110);

  setServoAngle(0, a);
  setServoAngle(1, b);
  setServoAngle(14, c);
  setServoAngle(15, d);

  delay(10000);
}

void loop() {
  for (;;) {
    if (b >= 205 || b <= 185) {
      i1 = -i1;
    }
    b += i1;
    setServoAngle(1, b);
    if (b == 205) {
      //setServoAngle(6, 60);
      //break;
    }

    if (b == 185) {
     // setServoAngle(6, 80);
      break;
    }
    delay(5);
  }

  delay(5);

  for (;;) {
    if (c <= 5 || c >= 25) {
      i3 = -i3;
    }
    c += i3;
    setServoAngle(14, c);
    if (c == 25) {
     // setServoAngle(8, 110);
     break;
    }

    if (c == 5) {
      //setServoAngle(8, 90);
      //break;
      
    }
    delay(5);
  }
  delay(5);

  
    for (;;) {
    if (d <= 0 || d >= 20) {
      i4 = -i4;
    }
    d += i4;
    delay(5);
    setServoAngle(15, d);

    if (d == 0) {
      //setServoAngle(9, 130);
      //break;
    }

    if (d == 20) {
     // setServoAngle(9, 110);
      break;
    }
  }
delay(5);
  for (;;) {
    if (a >= 190 || a <= 170) {
      i = -i;
    }
    a += i;
    setServoAngle(0, a);
    delay(5);

    if (a == 190) {
      //setServoAngle(7, 60);
     // break;
    }

    if (a == 170) {
      //setServoAngle(7, 80);
      break;
    }
  }
  delay(5);
}

void setServoAngle(uint8_t n, int angle) {
  int pulse = map(angle, 0, 180, SERVOMIN_PULSE, SERVOMAX_PULSE);
  pwm.setPWM(n, 0, pulse);
}
