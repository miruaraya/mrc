const int IN1 = 7;
const int IN2 = 8;
const int ENA = 9; 

const int IN3 = 11;
const int IN4 = 12;
const int ENA2 = 13; //idk if this is actually the pwm pin its placeholder

void setup() {
  // Left motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

 // Right motor pins
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA2, OUTPUT);

  Serial.begin(9600);

  // Default state is off
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.println(">> READY");
}

String currentCommand = String("");

void loop() {
  if (!Serial.available()) {
    return;
  }

  // Read command until newline
  currentCommand = Serial.readStringUntil('\n');
  currentCommand.trim();

  if (currentCommand == "Forward") {
    // Left and right motors forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    Serial.println(">> FORWARD");
  }

  else if (currentCommand == "Back") {
    // Left and right motors reverse
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    Serial.println(">> BACK");
  }

  else if (currentCommand == "Right") {
    // Left forward, right reverse
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    Serial.println(">> RIGHT");
  }

  else if (currentCommand == "Left") {
    // Left reverse, right forward
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);

    Serial.println(">> LEFT");
  }

  else if (currentCommand == "Stop") {
    // Stop both motor sides
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    Serial.println(">> STOP");
  }

  else {
    Serial.println(">> UNKNOWN COMMAND");
  }
}
