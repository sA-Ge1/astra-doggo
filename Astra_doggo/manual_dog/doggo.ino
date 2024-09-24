#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create the PCA9685 PWM driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // Minimum pulse length count (out of 4096)
#define SERVOMAX  600 // Maximum pulse length count (out of 4096)

int angle0 = 90; // Initial angle for servo on channel 0
int angle1 = 90; // Initial angle for servo on channel 1

void setup() {
  Serial.begin(9600);
  Serial.println("Robot Doggo Control using PCA9685");

  // Initialize the PCA9685
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz

  delay(10);

  // Move servos to initial positions
  setServoPulse(0, angle0);
  setServoPulse(1, angle1);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'u') {
      angle0 = constrain(angle0 + 1, 0, 180);
      angle1 = constrain(angle1 + 1, 0, 180);
    } else if (command == 'd') {
      angle0 = constrain(angle0 - 1, 0, 180);
      angle1 = constrain(angle1 - 1, 0, 180);
    }

    // Update servo positions
    setServoPulse(0, angle0);
    setServoPulse(1, angle1);

    // Print the current angles to the Serial Monitor
    Serial.print("Servo 0 angle: ");
    Serial.print(angle0);
    Serial.print(", Servo 1 angle: ");
    Serial.println(angle1);
  }
}

// Function to set the pulse width for a servo
void setServoPulse(uint8_t n, int angle) {
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(n, 0, pulse);
}
