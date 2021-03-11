int getButtonPressed()
{
  digitalWrite(BTNLOAD, HIGH);
  delay(1);
  digitalWrite(BTNLOAD, LOW);
  delay(1);
  digitalWrite(BTNLOAD, HIGH);

  for (int i = 0; i < 16; i++)
  {
    if (digitalRead(BTNDATA))
    {
      switch (i)
      {
      case 0:
        return 4;
        break;
      case 1:
        return 5;
        break;
      case 2:
        return 6;
        break;
      case 3:
        return 7;
        break;
      case 4:
        return 3;
        break;
      case 5:
        return 2;
        break;
      case 6:
        return 1;
        break;
      case 7:
        return 0;
        break;
      case 8:
        return 12;
        break;
      case 9:
        return 13;
        break;
      case 10:
        return 14;
        break;
      case 11:
        return 15;
        break;
      case 12:
        return 11;
        break;
      case 13:
        return 10;
        break;
      case 14:
        return 9;
        break;
      case 15:
        return 8;
        break;
      }
    }
 //   Serial.print(digitalRead(BTNDATA), BIN);

    digitalWrite(BTNCLOCK, LOW);
    delay(1);
    digitalWrite(BTNCLOCK, HIGH);
    delay(1);
  }
  Serial.print("\n");

        return -1;
}


void checkButton() {

int btnPressed=getButtonPressed();
if(btnPressed>0 &&btnPressed<13 ){
prew=btnPressed-1;
}

}