void updateLed()
{
    createByte();
    digitalWrite(LEDLATCH, 0);
    shiftOut(LEDDATA, LEDCLOCK, MSBFIRST, led1);
    shiftOut(LEDDATA, LEDCLOCK, MSBFIRST, led2);
    digitalWrite(LEDLATCH, 1);
}

void clearLed(){
 digitalWrite(LEDLATCH, 0);

    shiftOut(LEDDATA, LEDCLOCK, MSBFIRST, 0x00);
    shiftOut(LEDDATA, LEDCLOCK, MSBFIRST, 0x00);
    digitalWrite(LEDLATCH, 1);
}

void createByte()
{

for(int e=0;e<16;e++){
    ledState[e]=(char)0;
   
}
led1=led2=0;
    ledState[prog-1] = 1;
   

        ledState[prew-1] = millis() % 1000 > 500;


    for (int i = 0; i < 8; i++)
    {
        if (ledState[i])
        {
            led2 |= (1 << i);
        }
        if (ledState[i + 8])
        {
            led1 |= (1 << i);
        }
    }


}