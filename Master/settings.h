#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Wire.h>
#define LEDLATCH A1
#define LEDDATA A2
#define LEDCLOCK A0

#define BTNLOAD 8
#define BTNCLOCK 7
#define BTNDATA 6
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define nPAGE 2
int prew = 5, prog = 2, page = 0;

byte led1, led2;
bool ledState[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool btnState[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool btnMode[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int mod = 0;
enum mod
{
    normal,
    settings
};
int btnPressed = -1;
int num;