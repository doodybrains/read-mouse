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

int count = 0;
int capitalism;
int motorPin = 3;
bool isClicked = false;

void setup(){
  Serial.begin(9600); 
  pinMode(motorPin, OUTPUT);
  oldMouse.begin();
  Mouse.begin();
}

void loop() {
  uint8_t stat;
  int x,y;
  int newY;
  
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
  
  if (Serial.available() > 0) {
    capitalism = Serial.read();

    if (capitalism == 'x') {
      digitalWrite(3, HIGH);
      delay(400);
      digitalWrite(3, LOW);
      
      if (count < 1) {
        Mouse.move(100,100,0);
        count += 1;
      } else {
        count = 0;
      }
    }
  }
}