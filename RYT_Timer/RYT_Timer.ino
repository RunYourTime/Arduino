#include <TimerOne.h>

/***************************************
name:Stopwatch
function: you can see the number increases by one per second on the 4-digit 7-segment display.
***********************************/
//Email:support@sunfounder.com
//Website:www.sunfounder.com

/**************************************/
#include <TimerOne.h>
//the pins of 4-digit 7-segment display attach to pin2-13 respectively 
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int p = 9;

int d4 = 10;
int d3 = 11;
int d2 = 12;
int d1 = 13;

long n = 0;// n represents the value displayed on the LED display. For example, when n=0, 0000 is displayed. The maximum value is 9999.
long nlast = 0; 
int x = 100;
int del = 5;//Set del as 5; the value is the degree of fine tuning for the clock
int count = 0;//Set count=0. Here count is a count value that increases by 1 every 0.1 second, which means 1 second is counted when the value is 10
int countlast = 0;


int sensorpin = 0;                 // analog pin used to connect the sharp sensor
float val1 = 0;                 // variable to store the values from sensor(initially zero)
int start = 2;                 // analog pin used to connect the sharp sensor
float val2 = 0;                 // variable to store the values from sensor(initially zero)
boolean RYT = false;

void setup()
{
  //set all the pins of the LED display as output
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);

  Timer1.initialize(10000); // set a timer of length 10000 microseconds (or 0.01 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( add ); // attach the service routine here
}
/***************************************/ 
void loop()
{

  float volts;
  float distance;
  val1 = analogRead(sensorpin);       // reads the value of the sharp sensor
  volts = val1*5/1024;
  distance = 28/volts;
  //Serial.println(distance);            // prints the value of the sensor to the serial monitor

  val2 = analogRead(start);       // reads the value of the sharp sensor

  if (val2 > 800 && !RYT){
  RYT = true; 
  n = 0;
  count = 0;
  }
  
 if (distance < 60 && distance > 50 && RYT){
  RYT = false; 
  nlast = n;
  countlast = count;
  }
  
  delay(del);//delay 5ms


  if (RYT){
  clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d1
  pickNumber(n%100/10);// get the value of thousand
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d2
  pickNumber(n%10);// get the value of hundred
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(2);//Light up 7-segment display d3
  pickNumber(count%100/10);//get the value of ten
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(3);//Light up 7-segment display d4
  pickNumber(count%10);//Get the value of single digit
  delay(del);//delay 5ms

  }
  else{
  clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d1
  pickNumber(nlast%100/10);// get the value of thousand
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d2
  pickNumber(nlast%10);// get the value of hundred
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(2);//Light up 7-segment display d3
  pickNumber(countlast%100/10);//get the value of ten
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(3);//Light up 7-segment display d4
  pickNumber(countlast%10);//Get the value of single digit
  delay(del);//delay 5ms
  }

  
}
/**************************************/ 
void pickDigit(int x) //light up a 7-segment display
{
  //The 7-segment LED display is a common-cathode one. So also use digitalWrite to  set d1 as high and the LED will go out
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  switch(x)
  {
    case 0: 
    digitalWrite(d1, HIGH);//Light d1 up 
    digitalWrite(p, HIGH);
    break;
    case 1: 
    digitalWrite(d2, HIGH); //Light d2 up 
    digitalWrite(p, LOW);
    break;
    case 2: 
    digitalWrite(d3, HIGH); //Light d3 up 
    digitalWrite(p, HIGH);
    break;
    default: 
    digitalWrite(d4, HIGH); //Light d4 up 
    digitalWrite(p, HIGH);
    break;
  }
}
//The function is to control the 7-segment LED display to display numbers. Here x is the number to be displayed. It is an integer from 0 to 9 
void pickNumber(int x)
{
  switch(x)
  {
    default: 
    zero(); 
    break;
    case 1: 
    one(); 
    break;
    case 2: 
    two(); 
    break;
    case 3: 
    three(); 
    break;
    case 4: 
    four(); 
    break;
    case 5: 
    five(); 
    break;
    case 6: 
    six(); 
    break;
    case 7: 
    seven(); 
    break;
    case 8: 
    eight(); 
    break;
    case 9: 
    nine(); 
    break;
  }
} 
void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void zero() //the 7-segment led display 0
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void one() //the 7-segment led display 1
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void two() //the 7-segment led display 2
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void three() //the 7-segment led display 3
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void four() //the 7-segment led display 4
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void five() //the 7-segment led display 5
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void six() //the 7-segment led display 6
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void seven() //the 7-segment led display 7
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void eight() //the 7-segment led display 8
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void nine() //the 7-segment led display 9
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
/*******************************************/
void add()
{
  // Toggle LED
  count ++;
  if(count == 100)
  {
    count = 0;
    n++;
    if(n == 10000)
    {
      n = 0;
    }
  }
}
