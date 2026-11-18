void loop() {
  if (!Serial.available()) return;

  String command = Serial.readStringUntil('\n');
  command.trim();

  int open = command.indexOf('(');
  int close = command.indexOf(')');
  if (open < 0 || close < open) {
    Serial.println("ERR: bad format");
    return;
  }

  String name = command.substring(0, open);
  int angle = constrain(command.substring(open + 1, close).toInt(), 0, 180);

  if (name == "lower") {
    lowerServo.write(angle);
  } else if (name == "upper") {
    upperServo.write(angle);
  } else {
    Serial.println("ERR: unknown servo");
    return;
  }
  Serial.println("OK");
}
