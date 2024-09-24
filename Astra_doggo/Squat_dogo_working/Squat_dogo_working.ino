#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN0  30 
#define SERVOMAX0  60 

#define SERVOMIN1  110
#define SERVOMAX1  140 

#define SERVOMIN2  120
#define SERVOMAX2  150 

#define SERVOMIN_PULSE  150 
#define SERVOMAX_PULSE  600 

int angle0 = SERVOMIN0;
int angle1 = SERVOMAX1;
int angle2 = SERVOMAX2;
int increment0 = 1;
int increment1 = 1;
int increment2 = 1;
int a=190;
int b=200;
int c=-20;
int d=-10;
int i=1;
int i1=1;
int i3=-1;
int i4=-1;
void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);

  // Move servos to initial positions
  setServoAngle(7, angle0);
  setServoAngle(8, angle1);
  setServoAngle(6, angle0);
  setServoAngle(9, angle2);


  setServoAngle(0,a);
  setServoAngle(1, b);
  setServoAngle(13, c);
  setServoAngle(15, d);

  delay(5000);
}

void loop() 
{
  
  angle0 += increment0;
  if (angle0 >= SERVOMAX0 || angle0 <= SERVOMIN0) 
  {
    increment0 = -increment0;
  }
  
  if (angle1 >= SERVOMAX1 || angle1 <= SERVOMIN1)
  {
    increment1 = -increment1;
  }
  angle1 += increment1;

  if (angle2 >= SERVOMAX2 || angle2 <= SERVOMIN2) 
  {
    increment2 = -increment2;
  }
  angle2 += increment2;






  if (a >= 190 || a <= 160) 
  {
    i = -i;
  }
   a += i;

  

  if (b >= 200 || b <= 170) 
  {
    i1 = -i1;
  }
   b += i1;
   
  

  c=c+20;
  if (c <= 0 || c >= 30) 
  {
    i3 = -i3;
  }
  c=c-20;
  c += i3;

  d=d+10;
  if (d <= 0 || d >= 30) 
  {
    i4 = -i4;
  }
  d=d-10;
  d += i4;
   
 

  //lowerlimb
  setServoAngle(7, angle0);
  setServoAngle(8, angle1);
  setServoAngle(6, angle0);
  setServoAngle(9, angle2);

  //upperlimb
  setServoAngle(0, a);
  setServoAngle(1, b);
  setServoAngle(13, c);
  setServoAngle(15, d);

  delay(20);
}

void setServoAngle(uint8_t n, int angle) 
{
  int pulse = map(angle, 0, 180, SERVOMIN_PULSE, SERVOMAX_PULSE);
  pwm.setPWM(n, 0, pulse);
}
