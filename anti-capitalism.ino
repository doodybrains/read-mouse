/*
WORKING
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

void setup(){
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);  
  Mouse.begin();
  while(!Serial);
  Serial.print("Setup...");
  oldMouse.begin();
  Mouse.begin();
}

void loop() {
  uint8_t stat;
  int x,y;

  oldMouse.getPosition(stat,x,y);
  
  Mouse.move(x, y, 0);

//  Serial.print(stat);
//  Serial.print("\tx=");
//  Serial.print(x, DEC);
//  Serial.print("\ty=");
//  Serial.println(y, DEC);
  
  if (stat == 9) {
    Mouse.click();
  }

  capitalism = Serial.read();

  if (capitalism == 'x') {
   digitalWrite(3, HIGH);
   delay(1000);
  } else {
    digitalWrite(3, LOW);
  }

  delay(50);  
}