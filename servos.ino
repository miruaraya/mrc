#include <Servo.h>

Servo lowerServo;
Servo upperServo;

String command = String("");

const int lowerPin = 6;
const int upperPin = 10;

void setup() {
  lowerServo.attach(lowerPin);
  upperServo.attach(upperPin);

  // default/starting position for servos
  lowerServo.write(0);
  upperServo.write(90);

  Serial.begin(9600);
  
}

void loop() {
  
  if (!Serial.available()) {
    return;
  }
  
  command = Serial.readStringUntil('\n');
  command.trim();

  if (command == "lower(0)") {
    lowerServo.write(0);
  } else if (command == "lower(45)") {
    lowerServo.write(45);
  } else if (command == "lower(90)") {
    lowerServo.write(90);
  } else if (command == "lower(135)") {
    lowerServo.write(135);
  } else if (command == "lower(180)") {
    lowerServo.write(180);
  } else if (command == "upper(0)") {
    upperServo.write(0);
  } else if (command == "upper(45)") {
    upperServo.write(45);
  } else if (command == "upper(90)") {
    upperServo.write(90);
  } else if (command == "upper(135)") {
    upperServo.write(135);
  } else if (command == "upper(180)") {
    upperServo.write(180);
  }

}
