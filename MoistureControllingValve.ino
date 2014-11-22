// This sketch is used for automatic garden watering project.
// The arduino pin number 13 is used to send the digital output to the power transistor that switches the solenoid valve on and off
// The Soil Moisture data is fed into the arduino via the analogue pin A0
// The Soil Moisture data is fed only once in few hours and if the soil is found to be dry the solenoid is switched on for a few seconds (This depends
// on the diameter of the pipe and pressure head of the water supply)

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
