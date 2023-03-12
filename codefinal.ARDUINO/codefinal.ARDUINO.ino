#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


// change this to make the song slower or faster
int tempo = 80;

// change this to whichever pin you want to use
int buzzer = 11;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {

  // Star Trek Intro
  // Score available at https://musescore.com/user/10768291/scores/4594271
 
  NOTE_D4, -8, NOTE_G4, 16, NOTE_C5, -4, 
  NOTE_B4, 8, NOTE_G4, -16, NOTE_E4, -16, NOTE_A4, -16,
  NOTE_D5, 2,
  
};

int buzzerPin = 8; // Pin du buzzer
int Notes[] = { 262, 294, 330, 349, 392, 440, 494, 523 };


int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

const int ledA = 6;
const int ledB = 4;
const int ledC = 11;
const int ledD = 12;
const int ledOK = 10;

bool eA = 0;
bool eB = 0;
bool eC = 0;
bool eD = 0;
bool eOK = 0;

bool e1 = 0;
bool e2 = 0;
bool e3 = 0;


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
  ////////////////// change de input /////////////////////////
  if (analogRead(A1) >= 0 && analogRead(A1) <= 99) { //A
    while (analogRead(A1) >= 0 && analogRead(A1) <= 99) {}
    if (eA == 0) {
      e1 = 1;
      digitalWrite(ledA, HIGH);
      Serial.println("1");
    } else if (eA == 1) {
      e1 = 0;
      digitalWrite(ledA, LOW);
      Serial.println("1");
    }
  }

  else if (analogRead(A1) >= 500 && analogRead(A1) <= 599) { //B
    while (analogRead(A1) >= 500 && analogRead(A1) <= 599) {}
    if (eB == 0) {
      e2 = 1;
      digitalWrite(ledB, HIGH);
      Serial.println("2");
    } else if (eB == 1) {
      e2 = 0;
      digitalWrite(ledB, LOW);
      Serial.println("2");
    }
  }
  else if (analogRead(A1) >= 600 && analogRead(A1) <= 750) { //C
    while (analogRead(A1) >= 600 && analogRead(A1) <= 750) {}
    if (e3 == 0) {
      e3 = 1;
      digitalWrite(ledC, HIGH);
      Serial.println("3");
    } else if (e3 == 1) {
      e3 = 0;
      digitalWrite(ledC, LOW);
      Serial.println("3");

    }
  }
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

 