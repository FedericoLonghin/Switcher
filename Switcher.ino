

#include <LiquidCrystal.h>
#include "settings.h"

void setup()
{
  pinMode(LEDLATCH, OUTPUT);
  pinMode(LEDDATA, OUTPUT);
  pinMode(LEDCLOCK, OUTPUT);

  pinMode(BTNLOAD, OUTPUT);
  pinMode(BTNCLOCK, OUTPUT);
  pinMode(BTNDATA, INPUT);
  Serial.begin(115200);

  lcd.begin(16, 2);
}

void loop()
{
  switch (mod)
  {
  case normal:
    display();
    updateLed();
    checkButton();
    break;
  case settings:

    while (!btnState[0])
    {
      getAllButtonPressed();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Settings");
    }
    mod = normal;
    break;
  }
}
