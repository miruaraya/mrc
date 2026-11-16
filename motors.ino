const int LF = 10;
const int LB = 12;
const int ENA = 11;

const int RF = 2;
const int RB = 7;
const int ENA2 = 3;

void moveForward() {
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);

  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);

  analogWrite(ENA, 255);
  analogWrite(ENA2, 255);

  delay(500);
  stopMotors();
}

void moveBackward() {
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);

  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);

  analogWrite(ENA, 255);
  analogWrite(ENA2, 255);

  delay(500);
  stopMotors();
}

void turnLeft() {
  // Left reverse, Right forward
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);

  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);

  analogWrite(ENA, 255);
  analogWrite(ENA2, 255);
  
  delay(1000);
  stopMotors();
}

void turnRight() {
  // Left forward, Right reverse
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);

  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);

  analogWrite(ENA, 255);
  analogWrite(ENA2, 255);
  
  delay(1000);
  stopMotors();
}

void stopMotors() {
  // Turn off PWM power
  analogWrite(ENA, 0);
  analogWrite(ENA2, 0);

  // Set direction pins LOW
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
}

void setup() {
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(ENA2, OUTPUT);

  Serial.begin(9600);
  stopMotors();

  Serial.println(">> READY");
}

void loop() {
  if (!Serial.available()) {
    return;
  }

  String command = Serial.readStringUntil('\n');
  command.trim();

  if (command == "F" || command == "f") {
    moveForward();
  }
  else if (command == "B" || command == "b") {
    moveBackward();
  }
  else if (command == "L" || command == "l") {
    turnLeft();
  }
  else if (command == "R" || command == "r") {
    turnRight();
  }
  else if (command == "S" || command == "s") {
    stopMotors();
  } // <-- Added missing closing brace here
  else {
    Serial.println(">> UNKNOWN COMMAND");
  }
}
