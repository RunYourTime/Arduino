//collects data from an analog sensor

int sensorpin = 0;                 // analog pin used to connect the sharp sensor
float val = 0;                 // variable to store the values from sensor(initially zero)

void setup()
{
  Serial.begin(9600);               // starts the serial monitor
   delay(2000);
}
 
void loop()
{
  float volts;
  float distance;
  val = analogRead(sensorpin);       // reads the value of the sharp sensor
  volts = val*5/1024;
  distance = 28/volts;
  //Serial.println(distance);            // prints the value of the sensor to the serial monitor

 if (distance < 100 && distance > 40){
  Serial.println("Enas malakas perase."); 
  
  }
  delay(400);                    // wait for this much time before printing next value
}

