

#include <LiquidCrystal.h>
#include "settings.h"
#include <EEPROM.h>
void setup()
{
  EEPROM.begin();
  pinMode(LEDLATCH, OUTPUT);
  pinMode(LEDDATA, OUTPUT);
  pinMode(LEDCLOCK, OUTPUT);

  pinMode(BTNLOAD, OUTPUT);
  pinMode(BTNCLOCK, OUTPUT);
  pinMode(BTNDATA, INPUT);
  Serial.begin(115200);

  lcd.begin(16, 2);
  loadButtonMode();
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
    lcd.clear();
    clearLed();
    lcd.setCursor(0, 0);
    lcd.print("Settings");
    while (btnPressed != 0)
    {

      btnPressed = getButtonPressed();
      if (btnPressed > 0 && btnPressed < 13)
      {
        num = btnPressed - 1;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("btn N.: ");
        lcd.print(num);
        lcd.setCursor(0, 1);
        lcd.print("mod: ");
        lcd.print(btnMode[num] ? "normale " : "speciale");
      }
      if (btnPressed == 14)
      {
        btnMode[num] = !btnMode[num];
        lcd.setCursor(5, 1);
        lcd.print(btnMode[num] ? "normale " : "speciale");
        EEPROM.write(num, btnMode[num]);
        while (getButtonPressed() == 14)
        {
        }
      }
    }
    mod = normal;
    break;
  }
}