

#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver(2000, 14, 15, 16  ); // ESP8266 or ESP32: do not use pin 11

int ledPin = 7;

void setup()
{
    Serial.begin(9600);  // Debugging only
    pinMode(A0, INPUT);
    pinMode(ledPin, OUTPUT);
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
  int i;

 String str = "";
   
//for(int i =0;i<1;i++ ){
  str = (char)buf[0];
//}
if(str == "A"){
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
}

 Serial.println(str);


}
 
}
