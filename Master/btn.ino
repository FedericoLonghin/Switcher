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

    digitalWrite(BTNCLOCK, LOW);
    delay(1);
    digitalWrite(BTNCLOCK, HIGH);
    delay(1);
  }

  return -1;
}

void getAllButtonPressed()
{
  for (int e = 0; e < 16; e++)
  {
    btnState[e] = (char)0;
  }
  digitalWrite(BTNLOAD, HIGH);
  delay(1);
  digitalWrite(BTNLOAD, LOW);
  delay(1);
  digitalWrite(BTNLOAD, HIGH);

  for (int i = 0; i < 16; i++)
  {

    // Serial.print(digitalRead(BTNDATA));
    if (digitalRead(BTNDATA))
    {
      switch (i)
      {
      case 0:
        btnState[4] = 1;
        break;
      case 1:
        btnState[5] = 1;
        break;
      case 2:
        btnState[6] = 1;
        break;
      case 3:
        btnState[7] = 1;
        break;
      case 4:
        btnState[3] = 1;
        break;
      case 5:
        btnState[2] = 1;
        break;
      case 6:
        btnState[1] = 1;
        break;
      case 7:
        btnState[0] = 1;
        break;
      case 8:
        btnState[12] = 1;
        break;
      case 9:
        btnState[13] = 1;
        break;
      case 10:
        btnState[14] = 1;
        break;
      case 11:
        btnState[15] = 1;
        break;
      case 12:
        btnState[11] = 1;
        break;
      case 13:
        btnState[10] = 1;
        break;
      case 14:
        btnState[9] = 1;
        break;
      case 15:
        btnState[8] = 1;
        break;
      }
    }
    digitalWrite(BTNCLOCK, LOW);
    delay(1);
    digitalWrite(BTNCLOCK, HIGH);
    delay(1);
  }
}
void checkButton()
{

  btnPressed = getButtonPressed();
  if (btnPressed != -1)
  {
    switch (btnPressed)
    {
    case 0: //SHIFT KEY
    HaveIToSwitch=1;
      if (page + 1 >= nPAGE)
        page = 0;
      else
        page++;
      break;

    case 1 ... 12: //NUMBER KEY
      if (btnMode[btnPressed] != 1)
      {
        prew = btnPressed;
      }
      digit(btnPressed);
      break;

    case 13 ... 15: //SET KEY
    switchscene(btnPressed);


     
      if (btnMode[prog] == video)
        videoStartTime = millis();
      break;
    }
    while (getButtonPressed() != -1)
    {
      getAllButtonPressed();

      if (btnState[13] && btnState[15])
      {
        mod = settings;
      }
    }
  }
}
