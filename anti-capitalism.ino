/*
PS2 Connector Wires
Green Wire - 5V
Black Wire - GRND
Yellow Wire - Clock - Pin 6
Brown Wire - Data - Pin 5
*/

#include "PS2Mouse.h"
#include "Mouse.h"

PS2Mouse oldMouse(6,5);

int angle = 0;

int capitalism;
int motorPin = 3;
bool isNegative = false;
bool isClicked = false;
bool reverseMouse = false;

long previousMillis = 0;  
long interval = 1000; 

void setup(){
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);  
  
  while(Serial);

  oldMouse.begin();
  Mouse.begin();
}

void loop() {
  uint8_t stat;
  int x,y;
  int newY;
  
  unsigned long currentMillis = millis();
  
  oldMouse.getPosition(stat,x,y);

  if (y < 0) { newY = abs(y); } 
  if (y > 0) { newY = -y; }
  if (y == 0) { newY = y; }
  
  Mouse.move(x, newY, 0);
  
  if (stat == 9 && isClicked == false) {
    Mouse.click();
    isClicked = true;    
  }
  
  if (stat != 9) { isClicked = false; }
  
  capitalism = Serial.read();
  if (capitalism == 'x') {
    digitalWrite(3, HIGH);

    if (angle < 1) {
      angle += 1;
    }
  } else {
    if (millis() - previousMillis > interval) {
      digitalWrite(3, LOW);
      previousMillis = millis(); 
    }
    
    angle = 0;
  }
  
  delay(5);  
}