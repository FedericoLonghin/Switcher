

#include "settings.h"
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
  Wire.begin();
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
        num = btnPressed;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("btn N.: ");
        lcd.print(num);
        lcd.setCursor(0, 1);
        lcd.print("mod: ");
        lcd.print(getButtonMode(btnMode[num] ));
      }
      if (btnPressed == 14)
      {
        btnMode[num] ++;
        if(btnMode[num]>=3)btnMode[num] =0;
        lcd.setCursor(5, 1);
        lcd.print(getButtonMode(btnMode[num] ));
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