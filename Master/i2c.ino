void digit(int message)
{

    Wire.beginTransmission(8);
    Wire.write(message);
    Wire.endTransmission();
    Serial.print("digiting: ");
    Serial.println(message);
}
