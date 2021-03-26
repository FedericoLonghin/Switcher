
#include "Keyboard.h"
#include <Wire.h>
char lettere[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z'};

bool isShiftPressed;

void setup() {
  Serial.begin(115200);
  Keyboard.begin();
  Wire.begin(8);              
  Wire.onReceive(i2ckeyType);
}


void loop() {
}

void i2ckeyType() {

 while (1 < Wire.available()) {
    char c = Wire.read(); 
    Serial.print(c);      
  }
  int x = Wire.read(); 
isShiftPressed=x>20;

if(isShiftPressed){
x-=20;
Serial.print("CTRL+");
  Keyboard.press(0x80);
}


  Keyboard.press(0x82);
  Keyboard.press(lettere[x-1]);

  delay(100);
  Keyboard.releaseAll();
  Serial.println(x);     
}
