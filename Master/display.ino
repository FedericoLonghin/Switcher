void display()
{
    lcd.clear();
    if (btnMode[prog] == video)
    {
        lcd.setCursor(0, 0);
        lcd.print("Video   Prew: ");
        lcd.print(prew);
        lcd.setCursor(0, 1);
        nBars = ((millis() - videoStartTime) / videoduration[prog]) * 0.016;
        if (nBars <= videoduration[prog])
        {

            for (int i = 0; i < nBars; i++)
            {
                lcd.print("O");
            }
        }
        else
        {
            lcd.print("outOfTime");
        }
    }
    else
    {

        lcd.setCursor(0, 0);
        lcd.print("Page: ");
        lcd.print(page);
        lcd.setCursor(8, 0);
        lcd.print("Prew: ");
        lcd.print(prew);
        lcd.setCursor(8, 1);
        lcd.print("Prog: ");
        lcd.print(prog);
    }
}

String getButtonMode(byte mode)
{
    switch (mode)
    {
    case 0:
        return "normale ";
        break;
    case 1:
        return "Speciale";
        break;
    case 2:
        return "video   ";
        break;
    }
}