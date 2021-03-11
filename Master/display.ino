void display()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Page: ");
    lcd.print(page);
    lcd.setCursor(8, 0);
    lcd.print("Prog: ");
    lcd.print(prog);
    lcd.setCursor(8, 1);
    lcd.print("Prew: ");
    lcd.print(prew);
}