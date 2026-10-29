#include <Servo.h>

Servo lowerServo;
Servo upperServo;

String command = String("");

// placeholders because idk what pins we're using
const int lowerPin = 1;
const int upperPin = 2;

void setup() {
  lowerServo.attach(lowerPin);
  upperServo.attach(upperPin);

  // default/starting position for servos
  lowerServo.write(0);
  upperServo.write(90);

  Serial.begin(9600);
  
}

void loop() {
  command = Serial.readStringUntil('\n');
  command.trim();

}
