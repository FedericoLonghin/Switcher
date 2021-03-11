void display()
{
    lcd.setCursor(0, 0);
    lcd.print("Prog: ");
    lcd.print(prog);
    lcd.setCursor(0, 1);
    lcd.print("Prew: ");
    lcd.print(prew);
}