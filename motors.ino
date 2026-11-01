const int LF = 7;
const int LB = 8;
const int ENA = 9; 

const int RF = 10;
const int RB = 12;
const int ENA2 = 11; //idk if this is actually the pwm pin its placeholder

void setup() {
  // Left motor pins
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(ENA, OUTPUT);

 // Right motor pins
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(ENA2, OUTPUT);

  Serial.begin(9600);

  // Default state is off
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);

  Serial.println(">> READY");


void loop() {
  // put your main code here, to run repeatedly:
  if (!Serial.available()) {
    return;
  }

// Read command until newline
  currentCommand = Serial.readStringUntil('\n');
  currentCommand.trim();

//command control
  if (currentCommand == "F") {
  moveForward();
}
  else if (currentCommand == "B") {
  moveBackward();
}
  else if (currentCommand == "L") {
  turnLeft();
}
  else if (currentCommand == "R") {
  turnRight();
}
  else if (currentCommand == "S") {
    // Stop both motor sides
   stopMotors();

  else {
    Serial.println(">> UNKNOWN COMMAND");
  }

}


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
    // Left reverse, right forward
    digitalWrite(LF, LOW);
    digitalWrite(LB, LOW);
    digitalWrite(RF, HIGH);
    digitalWrite(RB, HIGH);

}

void turnRight() {
  //left forward, right reverse
    digitalWrite(LF, HIGH);
    digitalWrite(LB, HIGH);
    digitalWrite(RF, LOW);
    digitalWrite(RB, LOW);
}


void stopMotors() {
    // Stop both motor sides
    digitalWrite(LF, LOW);
    digitalWrite(LB, LOW);
    digitalWrite(RF, LOW);
    digitalWrite(RB, LOW);
  
}


