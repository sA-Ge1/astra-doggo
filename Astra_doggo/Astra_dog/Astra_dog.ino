#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN_PULSE  150 
#define SERVOMAX_PULSE  600 

int a = 185;
int b = 200;
int c = 0;
int d = 0;
int i = -1;
int i1 = -1;
int i3 = -1;
int i4 = -1;
int time=10;

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

  delay(1000000);
}

void loop() 

{
  int min=20;
  int max=50;
  move(b,min,max,i1,1,1);
  delay(time);
  move(c,min,max,i3,14,0);
  delay(time);
  move(d,min,max,i4,15,0);
  delay(time);
  move(a,min,max,i,0,1);
  delay(time);
}

void setServoAngle(uint8_t n, int angle) {
  int pulse = map(angle, 0, 180, SERVOMIN_PULSE, SERVOMAX_PULSE);
  pwm.setPWM(n, 0, pulse);
}

void move(int zero,int min, int max, int incr, int pin,int type)
{
  int temp=min;
  for (;;) 
  {
    if ( temp>= max || temp <= min) 
      incr = -incr;
    
    temp += incr;

    setServoAngle(pin, (temp+zero));
    delay(5);

    if (temp == max&&type==0)
      break;
    

    if (temp == min&&type==1)
      break;
  }
  delay(time);
}