void digit(int message)
{
    

    Serial.print("scrivo");
    Wire.beginTransmission(8);
    Wire.write(message); 
    Wire.endTransmission();
        Serial.println("Fatto!");
    
}

