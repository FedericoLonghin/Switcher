void digit(int message)
{
    

    Wire.beginTransmission(8);
    Wire.write(message); 
    Wire.endTransmission();
    
}

