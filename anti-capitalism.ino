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
int motorState = LOW;  
unsigned long previousMillis = 0; 
const long interval = 300; 

void setup(){
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600); 
  Serial.flush();
  while (!Serial);
  
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
    
    if (Serial.available() > 0) {
      capitalism = Serial.read();
    }
    
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
  
      if (motorState == LOW && capitalism == 'x') {
        motorState = HIGH;
        capitalism = 'y';
      } else {
        motorState = LOW;
      }
      
      digitalWrite(3, motorState);
    }
}