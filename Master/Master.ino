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
  lcd.createChar(0, fillChar);
  loadInfo();
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
    lcd.print("autoSwitch:");
    lcd.print(autoSwitch);
    btnPressed=getButtonPressed();
    while (btnPressed==-1||btnPressed>12)
    {
    btnPressed=getButtonPressed();
              Serial.print(btnPressed);

      if (btnPressed==14)
      {
        Serial.print("b");

        autoSwitch = !autoSwitch;
        lcd.setCursor(11, 0);
        lcd.print(autoSwitch);
        while (getButtonPressed() == 14){}
          
      }
    }
    num = 0;

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
        lcd.print(getButtonMode(btnMode[num]));
      }

      if (btnMode[num] == video)
      {
        lcd.setCursor(12, 1);
        lcd.print(videoduration[num]);
        if (btnPressed == 13 && videoduration[num] > 1)
        {
          videoduration[num]--;
          delay(100);
        }
        if (btnPressed == 15)
        {
          videoduration[num]++;
          delay(100);
        }
        if (videoduration[num] < 10)
          lcd.print(" ");
      }

      if (btnPressed == 14 && num != 0)
      {
        btnMode[num]++;
        if (btnMode[num] >= 3)
          btnMode[num] = 0;
        lcd.setCursor(5, 1);
        lcd.print(getButtonMode(btnMode[num]));
        while (getButtonPressed() == 14)
        {
        }
      }
    }

    unloadInfo();
    mod = normal;
    break;
  }
}