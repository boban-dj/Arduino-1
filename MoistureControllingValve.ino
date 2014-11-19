int solenoid = 13;
// assuming the power transitor connected to the solenoid is controlled through digital pin 13

void setup()
{
  pinMode(solenoid,OUTPUT);
  //digital pin 13 is set to output
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);
  //the variable sensorvalue reads the analog data from pin A0
  Serial.println(sensorValue);
  
  if (sensorValue > 500)
  {
    //if the sensorValue is less than 300, the solenoid is opened for a period of 10s (temporarily, real model the value should change)
    //then closed
    digitalWrite(solenoid,HIGH);
    delay(5000);
    digitalWrite(solenoid,LOW);
  }
  delay(10000);
}
