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
int dig=140;
int a=150;
int b=160;
int c=20;
int d=30;
int i=-2;
int i1=-2;
int i3=2;
int i4=2;
void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);

  // Move servos to initial positions
  setServoAngle(7, 80);
  setServoAngle(8, 90);
  setServoAngle(6, 80);
  setServoAngle(9, 110);


  setServoAngle(0,a);
  setServoAngle(1, b);
  setServoAngle(14, c);
  setServoAngle(15, d);

  delay(5000);
}

void loop() 
{

for(;;)
{


  if (a >= 170 || a <= 150) 
  {
    i = -i;
  }
   a += i;

  if (d <= 10 || d >= 30) 
  {
    i4 = -i4;
  }
  d += i4;
  setServoAngle(15, d);
  setServoAngle(0, a);
  delay(10);
  if(a==170)
  {
    setServoAngle(7, 60);
    setServoAngle(9, 130);
  }
  
  if(a==150)
  {
    setServoAngle(7, 80);
    setServoAngle(9, 110);
  }
  if(a==150)
    break;
}


delay(100);
for(;;)
{
  c=c+20;
  if (c <= 20 || c >= 40) 
  {
    i3 = -i3;
  }
  c=c-20;
  c += i3;
  if (b >= 180 || b <= 160) 
  {
    i1 = -i1;
  }
   b += i1;
  setServoAngle(1, b);
  setServoAngle(14, c);
  if(b==180)
  {
    setServoAngle(6, 60);
    setServoAngle(8, 110);

  }
    
  
  if(b==160)
  {
    setServoAngle(6, 80);
    setServoAngle(8, 90);
  }
  delay(10);
    if(c==20)
    break;
}

  delay(10);


}

void setServoAngle(uint8_t n, int angle) 
{
  int pulse = map(angle, 0, 180, SERVOMIN_PULSE, SERVOMAX_PULSE);
  pwm.setPWM(n, 0, pulse);
}
