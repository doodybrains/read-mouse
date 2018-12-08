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

int capitalism;
int motorPin = 3;
bool isNegative = false;
bool isClicked = false;

int LED = 13;

void setup(){
//  pinMode(motorPin, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);  
  
  while(Serial);

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
  
  Serial.println(isClicked);
  capitalism = Serial.read();

  if (capitalism == 'x') {
    //digitalWrite(3, HIGH);
    digitalWrite(LED, HIGH);

  } else {
    //digitalWrite(3, LOW);
    digitalWrite(LED, LOW);
  }

  delay(5);  
}