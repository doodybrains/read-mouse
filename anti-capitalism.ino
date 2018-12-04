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
const int motor = 12; 


void setup(){
  Serial.begin(9600);  Mouse.begin();
  while(!Serial);
  Serial.print("Setup...");
  oldMouse.begin();
  Mouse.begin();
  pinMode(motor, OUTPUT);
}

void loop() {

    
  digitalWrite(motor, HIGH);
  delay(1000);
  digitalWrite(motor, LOW);


  
  uint8_t stat;
  int x,y;
  oldMouse.getPosition(stat,x,y);
  Mouse.move(x, y, 0);
  Serial.print("\tx=");
  Serial.print(x, DEC);
  Serial.print("\ty=");
  Serial.println(y, DEC);

  if (Serial.available() > 0) {
    capitalism = Serial.read();
  }    

  delay(100);  

}