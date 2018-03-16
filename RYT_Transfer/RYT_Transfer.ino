

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile


RH_ASK driver(2000, 14, 2, 15); // ESP8266 or ESP32: do not use pin 11


int sensorpin = 14;                 // analog pin used to connect the sharp sensor
float val1 = 0;                 // variable to store the values from sensor(initially zero)

int inPin = 6;
void setup()
{
    Serial.begin(9600);    // Debugging only
    pinMode(inPin, INPUT);
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{

  
   const char *msg = "A";

    val1 = analogRead(sensorpin);       // reads the value of the sharp sensor
    Serial.println(val1); 
    if (val1 < 1000 && val1 > 90){
       //Serial.println(val1); 
      driver.send((uint8_t *)msg, strlen(msg));
      driver.waitPacketSent();
      
    }
    //delay(100);
}
