// Pin Definitions
const int motorLpin1 = 2;
const int motorLpin2 = 3;
const int motorRpin1 = 4;
const int motorRpin2 = 5;
const int motorLpwm = 10;
const int motorRpwm = 11;

// Motor Speed and Turn Rate
int motorSpeed = 125;
int turn = 50;

void setup() {
  Serial.begin(9600);
  pinMode(motorLpin1, OUTPUT);
  pinMode(motorLpin2, OUTPUT);
  pinMode(motorRpin1, OUTPUT);
  pinMode(motorRpin2, OUTPUT);
  pinMode(motorLpwm, OUTPUT);
  pinMode(motorRpwm, OUTPUT);
}

void loop() {
  String input = "";
  while (Serial.available()) {
    input += (char)Serial.read();
    delay(5);
  }

  if (input == "forward") {
    fwd();
  } else if (input == "stop") {
    stp();
  } else if (input == "backward") {
    rev();
  } else if (input.indexOf("left") > -1) {
    lft();
  } else if (input.indexOf("right") > -1) {
    rght();
  } else if (input != "") {
    motorSpeed = input.toInt();
  }
}

void fwd() {
  analogWrite(motorLpwm, motorSpeed);
  analogWrite(motorRpwm, motorSpeed);
  digitalWrite(motorLpin1, HIGH);
  digitalWrite(motorLpin2, LOW);
  digitalWrite(motorRpin1, HIGH);
  digitalWrite(motorRpin2, LOW);
}

void rev() {
  analogWrite(motorLpwm, motorSpeed);
  analogWrite(motorRpwm, motorSpeed);
  digitalWrite(motorLpin1, LOW);
  digitalWrite(motorLpin2, HIGH);
  digitalWrite(motorRpin1, LOW);
  digitalWrite(motorRpin2, HIGH);
}

void lft() {
  analogWrite(motorLpwm, motorSpeed - turn);
  analogWrite(motorRpwm, motorSpeed + turn);
  digitalWrite(motorLpin1, LOW);
  digitalWrite(motorLpin2, HIGH);
  digitalWrite(motorRpin1, HIGH);
  digitalWrite(motorRpin2, LOW);
}

void rght() {
  analogWrite(motorLpwm, motorSpeed + turn);
  analogWrite(motorRpwm, motorSpeed - turn);
  digitalWrite(motorLpin1, HIGH);
  digitalWrite(motorLpin2, LOW);
  digitalWrite(motorRpin1, LOW);
  digitalWrite(motorRpin2, HIGH);
}

void stp() {
  analogWrite(motorLpwm, 0);
  analogWrite(motorRpwm, 0);
}
