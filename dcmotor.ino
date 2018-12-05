/*
Adafruit Arduino - Lesson 13. DC Motor
*/


int motorPin = 3;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
}


void loop() {

  if (Serial.available()) {
    int speed = 'p';
    if (speed == 'x') {
      digitalWrite(3, HIGH);
    } else {
      digitalWrite(3, LOW);
    }
  }
} 
