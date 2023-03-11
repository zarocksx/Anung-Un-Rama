
bool eA = 0;
bool eB = 0;
bool eC = 0;
bool eD = 0;
bool eOK = 0;

const int ledA = 6;
const int ledB = 4;
const int ledC = 5;
const int ledD = 3;
const int ledOK = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledOK, OUTPUT);
  startAnimation();
}

void loop() {
  if (analogRead(A0) >= 0 && analogRead(A0) <= 99) { //A
    while (analogRead(A0) >= 0 && analogRead(A0) <= 99) {}
    if (eA == 0) {
      eA = 1;
      digitalWrite(ledA, HIGH);
      Serial.println("a");
    } else if (eA == 1) {
      eA = 0;
      digitalWrite(ledA, LOW);
      Serial.println("a");
    }
  }

  else if (analogRead(A0) >= 500 && analogRead(A0) <= 599) { //B
    while (analogRead(A0) >= 500 && analogRead(A0) <= 599) {}
    if (eB == 0) {
      eB = 1;
      digitalWrite(ledB, HIGH);
      Serial.println("b");
    } else if (eB == 1) {
      eB = 0;
      digitalWrite(ledB, LOW);
      Serial.println("b");
    }
  }
  else if (analogRead(A0) >= 600 && analogRead(A0) <= 750) { //C
    while (analogRead(A0) >= 600 && analogRead(A0) <= 750) {}
    if (eC == 0) {
      eC = 1;
      digitalWrite(ledC, HIGH);
      Serial.println("c");
    } else if (eC == 1) {
      eC = 0;
      digitalWrite(ledC, LOW);
      Serial.println("c");

    }
  }
  else if (analogRead(A0) >= 751 && analogRead(A0) <= 799) { //D
    while (analogRead(A0) >= 751 && analogRead(A0) <= 799) {}
    if (eD == 0) {
      eD = 1;
      digitalWrite(ledD, HIGH);
      Serial.println("d");
    } else if (eD == 1) {
      eD = 0;
      digitalWrite(ledD, LOW);
      Serial.println("d");

    }
  }
  else if (analogRead(A0) >= 800 && analogRead(A0) <= 899) { //ok
    while (analogRead(A0) >= 800 && analogRead(A0) <= 899) {}
    eA = 0;
    eB = 0;
    eC = 0;
    eD = 0;
    eOK = 0;
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, LOW);
    Serial.println("ok");
    digitalWrite(ledOK, HIGH);
    delay(1000);
    digitalWrite(ledOK, LOW);
  }
  delay(50);
}

void startAnimation() {
  digitalWrite(ledA, HIGH);
  delay(200);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, HIGH);
  delay(200);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, HIGH);
  delay(200);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, HIGH);
  delay(200);
  digitalWrite(ledD, LOW);
  digitalWrite(ledOK, HIGH);
  delay(200);
  digitalWrite(ledOK, LOW);
  delay(200);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
  digitalWrite(ledD, HIGH);
  digitalWrite(ledOK, HIGH);
  delay(500);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, LOW);
  digitalWrite(ledOK, LOW);
}

 