//collects data from an analog sensor

int sensorpin = 0;                 // analog pin used to connect the sharp sensor
float val1 = 0;                 // variable to store the values from sensor(initially zero)
int start = 1;                 // analog pin used to connect the sharp sensor
float val2 = 0;                 // variable to store the values from sensor(initially zero)

void setup()
{
  Serial.begin(9600);               // starts the serial monitor
   delay(2000);
}
 
void loop()
{
  float volts;
  float distance;
  val1 = analogRead(sensorpin);       // reads the value of the sharp sensor
  volts = val1*5/1024;
  distance = 28/volts;
  val2 = analogRead(start);       // reads the value of the sharp sensor
  Serial.println(val2);            // prints the value of the sensor to the serial monitor

 if (distance < 70 && distance > 20){
  Serial.println("Enas malakas perase."); 
  
  }
  delay(400);                    // wait for this much time before printing next value
}

