

#include <LiquidCrystal.h>
#define LEDLATCH A1
#define LEDDATA A2
#define LEDCLOCK A0

#define BTNLOAD 8
#define BTNCLOCK 7
#define BTNDATA 6
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 int prew = 0, prog = 2;
byte led1, led2;
bool ledState[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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
display();
  updateLed();
  checkButton();
}
