

void loadButtonMode()
{

    for (int i = 1; i < 13; i++)
    {
        btnMode[i] = EEPROM.read(i);
    }
}
void loadVideoDurations()
{
    for (int i = 1; i < 13; i++)
    {
        videoduration[i] = EEPROM.read(i + 100);
    }
}

void unloadButtonMode()
{
    for (int i = 1; i < 13; i++)
    {
        EEPROM.write(i, btnMode[i]);
    }
}
void unloadVideoDurations()
{
    for (int i = 1; i < 13; i++)
    {
        EEPROM.write(i + 100, videoduration[i]);
    }
}

void loadInfo(){
loadVideoDurations();
loadButtonMode();
autoSwitch=EEPROM.read(0);
}
void unloadInfo(){
unloadVideoDurations();
unloadButtonMode();
EEPROM.write(0,autoSwitch);
}

void switchscene(int transitiontype){
          int temp = prew;
      prew = prog;
      prog = temp;
       digit(transitiontype);
}