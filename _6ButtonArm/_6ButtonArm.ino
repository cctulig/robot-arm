#include <SoftwareSerial.h>
#include <Servo.h>


Servo shoulder;
Servo wrist;
Servo hand;

const int shoulderUp = 5;
const int shoulderDown = 6;
const int wristUp = 7;
const int wristDown = 4;
const int handUp = 3;
const int handDown = 2;

int shoulderPos = 45;
int wristPos = 90;
int handPos = 90;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  shoulder.attach(9);
  wrist.attach(10);
  hand.attach(11);

  pinMode(shoulderUp, INPUT);
  pinMode(shoulderDown, INPUT);
  pinMode(wristUp, INPUT);
  pinMode(wristDown, INPUT);
  pinMode(handUp, INPUT);
  pinMode(handDown, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ((digitalRead(shoulderUp) == 1) && !(shoulderPos == 170)) {
    shoulderPos += 1;
    Serial.print("Shoulder up ");
    Serial.println(shoulderPos);
  }
  else if ((digitalRead(shoulderDown) == 1) && !(shoulderPos == 10) ) {
    shoulderPos -= 1;
    Serial.println("Shoulder down");
    Serial.println(shoulderPos);
  }
  else if ((digitalRead(wristUp) == 1) && !(wristPos == 170)) {
    wristPos += 5;
    Serial.println("Wrist up");
    Serial.println(wristPos);
  }
  else if ((digitalRead(wristDown) == 1) && !(wristPos == 10)) {
    wristPos -= 5;
    Serial.println("Wirst down");
    Serial.println(wristPos);
  }
  else if ((digitalRead(handUp) == 1) && !(handPos == 170)) {
    handPos += 5;
    Serial.println("Hand up");
    Serial.println(handPos);
  }
  else if ((digitalRead(handDown) == 1) && !(handPos == 10)) {
    handPos -= 5;
    Serial.println("Hand down");
    Serial.println(handPos);
  }

  shoulder.write(shoulderPos);
  wrist.write(wristPos);
  hand.write(handPos);
  delay(10);
}
